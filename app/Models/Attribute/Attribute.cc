#include "Attribute.h"

#include <DatabaseAdapter/Schema.h>

Attribute::Attribute(QString name) {
    this->name = name;
}

Attribute::Attribute(QString name, QString description)
    : Attribute::Attribute(name) {
    this->description = description;
}

// Define how the SQL record should be decomposed into this object.
Attribute::Attribute(QSqlRecord* record) :
    Attribute(record->field("name").value().toString(),
              record->field("description").value().toString()
              ) {
    this->id = record->field("id").value().toInt();
}

Attribute::~Attribute() {}

void Attribute::getName(QString& outStr) {
    outStr = name;
}

void Attribute::getDescription(QString &outStr) {
    outStr = description;
}

void Attribute::toCommaSeparated(QString &outStr) {
    QString formatted = QString("'%1', '%2'")
            .arg(name)
            .arg(description);

    outStr = formatted;
}

void Attribute::getTableName(QString &outStr) {
    outStr = ATTRIBUTE_TABLE;
}
