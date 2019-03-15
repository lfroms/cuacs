#ifndef ATTRIBUTEDOBJECT_H
#define ATTRIBUTEDOBJECT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QDebug>
#include <Models/Attribute/Attribute.h>

template <class T>
class AttributedObject : public ActiveObject<T> {
public:
    AttributedObject<T>* attr(QString attrName, int value);
    AttributedObject<T>* attr(int attrId, int value);

    bool clearAttribute(QString attrName);
    bool clearAttribute(int attrId);

protected:
    AttributedObject();
    virtual ~AttributedObject() = 0;

    static void getAttributeTableName(QString& outStr) {
        T::getAttributeTableName(outStr);
    }

    static void getAttributeIdColumnName(QString& outStr) {
        T::getAttributeIdColumnName(outStr);
    }
};

template <class T>
AttributedObject<T>::AttributedObject() {}

template <class T>
AttributedObject<T>::~AttributedObject() {}

template <class T>
AttributedObject<T>* AttributedObject<T>::attr(int attrId, int value) {
    int objectId = this->getId();
    QString attributeTableName;
    this->getAttributeTableName(attributeTableName);

    QSqlQuery insert;
    QString insertQuery =
            QString("INSERT OR REPLACE INTO %1 VALUES(null, %2, %3, %4);")
            .arg(attributeTableName)
            .arg(objectId)
            .arg(attrId)
            .arg(value);

    bool queryDidSucceed = insert.exec(insertQuery);

    if (!queryDidSucceed) {
        qDebug() << QString("Failed to save value for attribute with id %1")
                    .arg(attrId);
    }

    return this;
}

template <class T>
AttributedObject<T>* AttributedObject<T>::attr(QString attrName, int value) {
    Attribute** a;
    Attribute::where(a, "name", attrName);

    int attributeId = a[0]->getId();
    qDebug() << attributeId;
    return this->attr(attributeId, value);
}

template <class T>
bool AttributedObject<T>::clearAttribute(int attrId) {
    int objectId = this->getId();

    QString attributeTableName, attributeColumnName;
    this->getAttributeTableName(attributeTableName);
    this->getAttributeIdColumnName(attributeColumnName);

    QSqlQuery insert;
    QString deleteQuery =
            QString("DELETE FROM %1 WHERE %2 = %3 AND %4 = %5;")
            .arg(attributeTableName)
            .arg(attributeColumnName)
            .arg(objectId)
            .arg("attribute_id")
            .arg(attrId);

    bool queryDidSucceed = insert.exec(deleteQuery);

    if (!queryDidSucceed) {
        qDebug() << QString("Failed to delete attribute in %1")
                    .arg(attributeTableName);
    }

    return queryDidSucceed;
}

template <class T>
bool AttributedObject<T>::clearAttribute(QString attrName) {
    Attribute** a;
    Attribute::where(a, "name", attrName);

    int attributeId = a[0]->getId();
    return this->clearAttribute(attributeId);
}


#endif // ATTRIBUTEDOBJECT_H
