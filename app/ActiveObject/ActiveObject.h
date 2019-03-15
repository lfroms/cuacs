#ifndef ACTIVEOBJECT_H
#define ACTIVEOBJECT_H

#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QVector>

#include <DatabaseAdapter/Schema.h>

template <class T>
class ActiveObject {
public:
    bool create();
    bool save();
    bool destroy();

    static QVector<T>* all();
    static T* first();
    static T* last();
    static int count();
    static T* where(int id);

    template <typename U>
    static QVector<T>* where(QString colName, U value);

    int getId();

protected:
    int id = -1;
    ActiveObject();
    virtual ~ActiveObject() = 0;

    virtual void toCommaSeparated(QString& outStr) = 0;

    static void getTableName(QString& outStr) {
        T::getTableName(outStr);
    }
};

template <class T>
ActiveObject<T>::ActiveObject() {}

template <class T>
ActiveObject<T>::~ActiveObject() {}

template <class T>
QVector<T>* ActiveObject<T>::all(){
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getAllQuery =
            QString("SELECT * FROM %1;")
            .arg(tableName);

    if (!query.exec(getAllQuery)) {
        return new QVector<T>();
    }

    QVector<T>* output = new QVector<T>();

    while (query.next()) {
        QSqlRecord record = query.record();
        T* t = new T(&record);
        output->append(*t);
    }

    return output;
}

template <class T>
T* ActiveObject<T>::first() {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getFirstQuery =
            QString("SELECT * FROM %1 ORDER BY id ASC LIMIT 1;")
            .arg(tableName);

    if (query.exec(getFirstQuery) && query.first()) {
        QSqlRecord record = query.record();
        return new T(&record);
    }

    return nullptr;
}

template <class T>
T* ActiveObject<T>::last() {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getLastQuery =
            QString("SELECT * FROM %1 ORDER BY id DESC LIMIT 1;")
            .arg(tableName);

    if (query.exec(getLastQuery) && query.first()) {
        QSqlRecord record = query.record();
        return new T(&record);
    }

    return nullptr;
}

template <class T>
T* ActiveObject<T>::where(int id) {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getWhereQuery =
            QString("SELECT * FROM %1 WHERE id = %2 LIMIT 1;")
            .arg(tableName)
            .arg(id);

    if (query.exec(getWhereQuery) && query.first()) {
        QSqlRecord record = query.record();
        return new T(&record);
    }

    return nullptr;
}

template <class T>
template <typename U>
QVector<T>* ActiveObject<T>::where(QString colName, U value) {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getWhereQuery =
            QString("SELECT * FROM %1 WHERE %2 = '%3';")
            .arg(tableName)
            .arg(colName)
            .arg(value);

    if (!query.exec(getWhereQuery)) {
        return new QVector<T>();
    }

    QVector<T>* output = new QVector<T>();

    while (query.next()) {
        QSqlRecord record = query.record();
        T* t = new T(&record);
        output->append(*t);
    }

    return output;
}

template <class T>
int ActiveObject<T>::count() {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getCountQuery =
            QString("SELECT COUNT(*) FROM %1;")
            .arg(tableName);

    query.exec(getCountQuery);
    query.first();

    return query.value(0).toInt();
}

template <class T>
bool ActiveObject<T>::create() {
    QString args, tableName;
    this->toCommaSeparated(args);
    this->getTableName(tableName);

    QSqlQuery insert;
    QString insertQuery =
            QString("INSERT INTO %1 VALUES(null, %2);")
            .arg(tableName)
            .arg(args);

    bool queryDidSucceed = insert.exec(insertQuery);

    if (queryDidSucceed) {
        this->id = insert.lastInsertId().toInt();
        return true;
    }

    return false;
}

template <class T>
bool ActiveObject<T>::save() {
    QString args, tableName;
    this->toCommaSeparated(args);
    this->getTableName(tableName);

    if (this->id == -1) {
        return this->create();
    }

    QSqlQuery update;
    QString updateQuery =
            QString("REPLACE INTO %1 VALUES(%2, %3);")
            .arg(tableName)
            .arg(id)
            .arg(args);

    return update.exec(updateQuery);
}

template <class T>
bool ActiveObject<T>::destroy() {
    QString tableName;
    this->getTableName(tableName);

    if (this->id == -1) {
        qDebug() << "Cannot destroy (unsaved) object with no id.";
        return false;
    }

    QSqlQuery destroy;
    QString destroyQuery =
            QString("DELETE FROM %1 WHERE id = %2;")
            .arg(tableName)
            .arg(id);

    return destroy.exec(destroyQuery);
}

template <class T>
int ActiveObject<T>::getId() {
    return id;
}

#endif // ACTIVEOBJECT_H
