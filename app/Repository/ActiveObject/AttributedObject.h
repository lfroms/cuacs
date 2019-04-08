#ifndef ATTRIBUTEDOBJECT_H
#define ATTRIBUTEDOBJECT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlField>
#include <QDebug>
#include <QVector>
#include <QHash>
#include <Repository/Attribute/Attribute.h>

template <class T>
class AttributedObject : public ActiveObject<T> {
public:
    AttributedObject<T>* setAttr(QString attrName, int value);
    int attr(QString attrName);
    bool clearAttr(QString attrName);
    QHash<QString, float> attributes();

    static const QString getAttributeTableName() {
        return T::className() + "s_attributes";
    }

    static const QString getAttributeIdColumnName() {
        return T::className() + "_id";
    }

protected:
    AttributedObject();
    virtual ~AttributedObject() = 0;

private:
    AttributedObject<T>* setAttr(int attrId, int value);
    int attr(int attrId);
    bool clearAttr(int attrId);
};

template <class T>
AttributedObject<T>::AttributedObject() {}

template <class T>
AttributedObject<T>::~AttributedObject() {}

template <class T>
AttributedObject<T>* AttributedObject<T>::setAttr(int attrId, int value) {
    int objectId = this->getId();

    QSqlQuery insert;
    QString insertQuery =
            QString("INSERT OR REPLACE INTO %1 VALUES(%2, %3, %4);")
            .arg(getAttributeTableName())
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
AttributedObject<T>* AttributedObject<T>::setAttr(QString attrName, int value) {
    QVector<Attribute*>* attributes = Attribute::where("name", attrName);

    if (attributes->isEmpty()) {
        qDebug() << QString("Could not find attribute named %1.").arg(attrName);
        return this;
    }

    int attributeId = attributes->first()->getId();
    return this->setAttr(attributeId, value);
}

template <class T>
int AttributedObject<T>::attr(int attrId) {
    int objectId = this->getId();

    QSqlQuery query;
    QString getAttrQuery =
            QString("SELECT value FROM %1 WHERE %2 = %3 AND attribute_id = %4;")
            .arg(getAttributeTableName())
            .arg(getAttributeIdColumnName())
            .arg(objectId)
            .arg(attrId);

    bool queryDidSucceed = query.exec(getAttrQuery) && query.first();

    if (!queryDidSucceed) {
        qDebug() << QString("Failed to get attribute. It may not exist.");
        return -1;
    }

    return query.record().field("value").value().toInt();
}

template <class T>
int AttributedObject<T>::attr(QString attrName) {
    QVector<Attribute*>* attributes = Attribute::where("name", attrName);

    if (attributes->isEmpty()) {
        qDebug() << QString("Could not find attribute named %1.").arg(attrName);
        return -1;
    }

    int attributeId = attributes->first()->getId();
    return this->attr(attributeId);
}

template <class T>
QHash<QString, float> AttributedObject<T>::attributes() {
    int objectId = this->getId();

    QSqlQuery query;
    QString getAttributesQuery =
            QString("SELECT * FROM %1 JOIN attributes "
                    "ON %1.attribute_id = attributes.id "
                    "WHERE %1.%2 = %3;")
            .arg(getAttributeTableName())
            .arg(getAttributeIdColumnName())
            .arg(objectId);

    bool queryDidSucceed = query.exec(getAttributesQuery);
    QHash<QString, float> attributeHash;

    if (!queryDidSucceed) {
        qDebug() << QString("Failed to get attribute. It may not exist.");
        return attributeHash;
    }

    while(query.next()) {
        attributeHash[query.value("name").toString()] = query.value("value").toFloat();
    }

    return attributeHash;
}

template <class T>
bool AttributedObject<T>::clearAttr(int attrId) {
    int objectId = this->getId();

    QString attributeTableName = getAttributeTableName();

    QSqlQuery insert;
    QString deleteQuery =
            QString("DELETE FROM %1 WHERE %2 = %3 AND attribute_id = %4;")
            .arg(attributeTableName)
            .arg(getAttributeIdColumnName())
            .arg(objectId)
            .arg(attrId);

    bool queryDidSucceed = insert.exec(deleteQuery);

    if (!queryDidSucceed) {
        qDebug() << QString("Failed to delete attribute in %1")
                    .arg(attributeTableName);
    }

    return queryDidSucceed;
}

template <class T>
bool AttributedObject<T>::clearAttr(QString attrName) {
    QVector<Attribute*>* attributes = Attribute::where("name", attrName);

    if (attributes->isEmpty()) {
        qDebug() << QString("Could not find attribute named %1.").arg(attrName);
        return -1;
    }

    int attributeId = attributes->first()->getId();
    return this->clearAttr(attributeId);
}

#endif // ATTRIBUTEDOBJECT_H
