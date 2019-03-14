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
    static bool first(T*);
    static bool last(T*);
    static int count();

protected:
    int id;
    ActiveObject();
    ActiveObject(int id);
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
ActiveObject<T>::ActiveObject(int id) {
    this->id = id;
}

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
bool ActiveObject<T>::first(T* output) {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getFirstQuery =
            QString("SELECT * FROM %1 ORDER BY id ASC LIMIT 1;")
            .arg(tableName);

    if (!query.exec(getFirstQuery)) {
        return false;
    }

    QSqlRecord record = query.record();
    output = new T(&record);

    return true;
}

template <class T>
bool ActiveObject<T>::last(T* output) {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getLastQuery =
            QString("SELECT * FROM %1 ORDER BY id DESC LIMIT 1;")
            .arg(tableName);

    if (!query.exec(getLastQuery)) {
        return false;
    }

    QSqlRecord record = query.record();
    output = new T(&record);

    return true;
}

template <class T>
int ActiveObject<T>::count() {
    QString tableName;
    getTableName(tableName);

    QSqlQuery query;
    QString getCountQUery =
            QString("SELECT COUNT(*) FROM %1;")
            .arg(tableName);

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

    return insert.exec(insertQuery);
}

template <class T>
bool ActiveObject<T>::save() {
    QString args, tableName;
    this->toCommaSeparated(args);
    this->getTableName(tableName);

    if (!this->id) {
        qDebug() << "Cannot save object with no id.";
        return false;
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

    if (!this->id) {
        qDebug() << "Cannot destroy object with no id.";
        return false;
    }

    QSqlQuery destroy;
    QString destroyQuery =
            QString("DELETE FROM %1 WHERE id = %2;")
            .arg(tableName)
            .arg(id);

    return destroy.exec(destroyQuery);
}

#endif // ACTIVEOBJECT_H
