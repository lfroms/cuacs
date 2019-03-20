#ifndef ACTIVEOBJECT_H
#define ACTIVEOBJECT_H

#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QVector>

template <class T>
class ActiveObject {
public:
    bool create();
    bool save();
    bool destroy();

    static QVector<T*>* all();
    static T* first();
    static T* last();
    static int count();
    static T* findBy(int id);

    template <typename U>
    static QVector<T*>* where(QString colName, U value, bool includeNull = false);

    int getId();

    const static QString getTableName() {
        return T::className() + "s";
    }

protected:
    int id = -1;
    ActiveObject();
    virtual ~ActiveObject() = 0;

    virtual const QString toCommaSeparated() = 0;

    static const QString className() {
        return T::className();
    }
};

template <class T>
ActiveObject<T>::ActiveObject() {}

template <class T>
ActiveObject<T>::~ActiveObject() {}

template <class T>
QVector<T*>* ActiveObject<T>::all(){
    QSqlQuery query;
    QString getAllQuery =
            QString("SELECT * FROM %1;")
            .arg(getTableName());

    if (!query.exec(getAllQuery)) {
        return new QVector<T*>();
    }

    QVector<T*>* output = new QVector<T*>();

    while (query.next()) {
        QSqlRecord record = query.record();
        T* t = new T(&record);
        output->append(t);
    }

    return output;
}

template <class T>
T* ActiveObject<T>::first() {
    QSqlQuery query;
    QString getFirstQuery =
            QString("SELECT * FROM %1 ORDER BY id ASC LIMIT 1;")
            .arg(getTableName());

    if (query.exec(getFirstQuery) && query.first()) {
        QSqlRecord record = query.record();
        return new T(&record);
    }

    return nullptr;
}

template <class T>
T* ActiveObject<T>::last() {
    QSqlQuery query;
    QString getLastQuery =
            QString("SELECT * FROM %1 ORDER BY id DESC LIMIT 1;")
            .arg(getTableName());

    if (query.exec(getLastQuery) && query.first()) {
        QSqlRecord record = query.record();
        return new T(&record);
    }

    return nullptr;
}

template <class T>
T* ActiveObject<T>::findBy(int id) {
    QSqlQuery query;
    QString getWhereQuery =
            QString("SELECT * FROM %1 WHERE id = %2 LIMIT 1;")
            .arg(getTableName())
            .arg(id);

    if (query.exec(getWhereQuery) && query.first()) {
        QSqlRecord record = query.record();
        return new T(&record);
    }

    return nullptr;
}

template <class T>
template <typename U>
QVector<T*>* ActiveObject<T>::where(QString colName, U value, bool includeNull) {
    QSqlQuery query;

    QString includeNullSegment =
            QString("OR %1 IS NULL")
            .arg(colName);

    QString getWhereQuery =
            QString("SELECT * FROM %1 WHERE %2 = '%3' %4;")
            .arg(getTableName())
            .arg(colName)
            .arg(value)
            .arg(includeNull ? includeNullSegment : "");

    if (!query.exec(getWhereQuery)) {
        return new QVector<T*>();
    }

    QVector<T*>* output = new QVector<T*>();

    while (query.next()) {
        QSqlRecord record = query.record();
        T* t = new T(&record);
        output->append(t);
    }

    return output;
}

template <class T>
int ActiveObject<T>::count() {
    QSqlQuery query;
    QString getCountQuery =
            QString("SELECT COUNT(*) FROM %1;")
            .arg(getTableName());

    query.exec(getCountQuery);
    query.first();

    return query.value(0).toInt();
}

template <class T>
bool ActiveObject<T>::create() {
    QSqlQuery insert;
    QString insertQuery =
            QString("INSERT INTO %1 VALUES(null, %2);")
            .arg(getTableName())
            .arg(toCommaSeparated());

    bool queryDidSucceed = insert.exec(insertQuery);

    if (queryDidSucceed) {
        this->id = insert.lastInsertId().toInt();
        return true;
    }

    return false;
}

template <class T>
bool ActiveObject<T>::save() {
    if (this->id == -1) {
        return this->create();
    }

    QSqlQuery update;
    QString updateQuery =
            QString("REPLACE INTO %1 VALUES(%2, %3);")
            .arg(getTableName())
            .arg(id)
            .arg(toCommaSeparated());

    return update.exec(updateQuery);
}

template <class T>
bool ActiveObject<T>::destroy() {
    if (this->id == -1) {
        qDebug() << "Cannot destroy (unsaved) object with no id.";
        return false;
    }

    QSqlQuery destroy;
    QString destroyQuery =
            QString("DELETE FROM %1 WHERE id = %2;")
            .arg(getTableName())
            .arg(id);

    bool didDestroy = destroy.exec(destroyQuery);

    if (!didDestroy) {
        qDebug() << "Could not destroy the record. Is this object stale?";
        return false;
    }

    this->id = -1;
    return true;
}

template <class T>
int ActiveObject<T>::getId() {
    return id;
}

#endif // ACTIVEOBJECT_H
