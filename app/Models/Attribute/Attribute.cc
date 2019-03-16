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

const QString Attribute::getName() { return name; }

const QString Attribute::getDescription() { return description; }

const QString Attribute::toCommaSeparated() {
    QString formatted = QString("'%1', '%2'")
            .arg(name)
            .arg(description);

    return formatted;
}

const QString Attribute::getTableName() {
    return ATTRIBUTE_TABLE;
}
