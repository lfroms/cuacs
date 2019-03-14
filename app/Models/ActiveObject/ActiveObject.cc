#include "ActiveObject.h"

#include <DatabaseAdapter/DatabaseAdapter.h>

ActiveObject::ActiveObject() {}
ActiveObject::~ActiveObject() {}

ActiveObject::ActiveObject(int id) {
    this->id = id;
}

bool ActiveObject::create() {
    QString commaSeparatedParams, tableName;
    this->toCommaSeparated(commaSeparatedParams);
    this->getTableName(tableName);

    return DatabaseAdapter::insert(tableName, commaSeparatedParams);
}

bool ActiveObject::save() {
    QString commaSeparatedParams, tableName;
    this->toCommaSeparated(commaSeparatedParams);
    this->getTableName(tableName);

    if (!this->id) {
        return false;
    }

    return DatabaseAdapter::update(this->id, tableName, commaSeparatedParams);
}

bool ActiveObject::destroy() {
    QString tableName;
    this->getTableName(tableName);

    if (!this->id) {
        return false;
    }

    return DatabaseAdapter::destroy(this->id, tableName);
}
