#ifndef ACTIVEOBJECT_H
#define ACTIVEOBJECT_H

#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>

#include <DatabaseAdapter/Schema.h>

template <class T>
class ActiveObject {
public:
    bool create();
    bool save();
    bool destroy();

    static bool all(T**);
    static bool first(T&);
    static bool last(T&);
    static int count();
    static bool where(T&, int id);

    template <typename U>
    static bool where(T**, QString colName, U value);

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
bool ActiveObject<T>::all(T** output) {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getAllQuery =
            QString("SELECT * FROM %1;")
            .arg(tableName);

    if (!query.exec(getAllQuery)) {
        return false;
    }

    int i = 0;

    while (query.next()) {
        QSqlRecord record = query.record();
        T* item = new T(&record);

        output[i] = item;
        i++;
    }

    return true;
}

template <class T>
bool ActiveObject<T>::first(T& output) {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getFirstQuery =
            QString("SELECT * FROM %1 ORDER BY id ASC LIMIT 1;")
            .arg(tableName);

    if (query.exec(getFirstQuery) && query.first()) {
        QSqlRecord record = query.record();
        output = T(&record);

        return true;
    }

    return false;
}

template <class T>
bool ActiveObject<T>::last(T& output) {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getLastQuery =
            QString("SELECT * FROM %1 ORDER BY id DESC LIMIT 1;")
            .arg(tableName);

    if (query.exec(getLastQuery) && query.first()) {
        QSqlRecord record = query.record();
        output = T(&record);

        return true;
    }

    return false;
}

template <class T>
bool ActiveObject<T>::where(T& output, int id) {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getWhereQuery =
            QString("SELECT * FROM %1 WHERE id = %2 LIMIT 1;")
            .arg(tableName)
            .arg(id);

    if (query.exec(getWhereQuery) && query.first()) {
        QSqlRecord record = query.record();
        output = T(&record);

        return true;
    }

    return false;
}

template <class T>
template <typename U>
bool ActiveObject<T>::where(T** output, QString colName, U value) {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getWhereQuery =
            QString("SELECT * FROM %1 WHERE %2 = %3 LIMIT 1;")
            .arg(tableName)
            .arg(colName)
            .arg(value);

    if (!query.exec(getWhereQuery)) {
        return false;
    }

    int i = 0;

    while (query.next()) {
        QSqlRecord record = query.record();
        T* item = new T(&record);

        output[i] = item;
        i++;
    }

    return true;
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
