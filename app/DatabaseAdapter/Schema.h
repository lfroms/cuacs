#ifndef SCHEMA_H
#define SCHEMA_H

#include <QString>

#include <Models/Animal/Animal.h>
#include <Models/Client/Client.h>
#include <Models/Attribute/Attribute.h>
#include <Models/User/User.h>

static const QString ANIMAL_TABLE = Animal::getTableName();
static const QString CLIENT_TABLE = Client::getTableName();
static const QString ATTRIBUTE_TABLE = Attribute::getTableName();
static const QString USER_TABLE = User::getTableName();

static const QString ANIMAL_ATTRIBUTE_TABLE = Animal::getAttributeTableName();
static const QString ANIMAL_ATTRIBUTE_COLUMN_NAME = Animal::getAttributeIdColumnName();

static const QString CLIENT_ATTRIBUTE_TABLE = Client::getAttributeTableName();
static const QString CLIENT_ATTRIBUTE_COLUMN_NAME = Client::getAttributeIdColumnName();

static const QString ANIMAL_SCHEMA =
        QString(
            "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
            "name TEXT NOT NULL,"
            "species TEXT NOT NULL,"
            "gender TEXT NOT NULL,"
            "breed TEXT NOT NULL,"
            "age INTEGER NOT NULL,"
            "neutered_or_spayed INTEGER NOT NULL,"
            "requires_medical INTEGER NOT NULL,"
            "main_color TEXT NOT NULL,"
            "hypothetical INTEGER NOT NULL"
            );

static const QString CLIENT_SCHEMA =
        QString(
            "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
            "user_id INTEGER NOT NULL,"
            "age INTEGER NOT NULL,"
            "phone_number TEXT NOT NULL,"
            "email TEXT NOT NULL,"
            "home_sq_foot INT NOT NULL,"
            "owned_animal INT NOT NULL,"
            "owns_animal INT NOT NULL,"
            "salary INT NOT NULL,"
            "hrs_dedication INT NOT NULL,"
            "has_children INT NOT NULL,"
            "ideal_animal_id INTEGER,"
            "FOREIGN KEY (ideal_animal_id) REFERENCES %1(id),"
            "FOREIGN KEY (user_id) REFERENCES %2(id)"
            )
        .arg(ANIMAL_TABLE)
        .arg(USER_TABLE);

static const QString ATTRIBUTE_SCHEMA =
        QString(
            "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
            "name TEXT NOT NULL UNIQUE,"
            "description TEXT,"
            "type TEXT"
            );

static const QString USER_SCHEMA =
        QString(
            "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
            "name TEXT NOT NULL,"
            "username TEXT NOT NULL UNIQUE,"
            "password TEXT NOT NULL,"
            "type TEXT NOT NULL,"
            "admin INTEGER NOT NULL DEFAULT 0"
            );

static const QString ANIMAL_ATTRIBUTE_SCHEMA =
        QString(
            "%3 INTEGER NOT NULL,"
            "attribute_id INTEGER NOT NULL,"
            "value INTEGER NOT NULL,"
            "FOREIGN KEY (%3) REFERENCES %1(id),"
            "FOREIGN KEY (attribute_id) REFERENCES %2(id),"
            "PRIMARY KEY (%3, attribute_id)"
            )
        .arg(ANIMAL_TABLE)
        .arg(ATTRIBUTE_TABLE)
        .arg(ANIMAL_ATTRIBUTE_COLUMN_NAME);

static const QString CLIENT_ATTRIBUTE_SCHEMA =
        QString(
            "%3 INTEGER NOT NULL,"
            "attribute_id INTEGER NOT NULL,"
            "value INTEGER NOT NULL,"
            "FOREIGN KEY (%3) REFERENCES %1(id),"
            "FOREIGN KEY (attribute_id) REFERENCES %2(id),"
            "PRIMARY KEY (%3, attribute_id)"
            )
        .arg(CLIENT_TABLE)
        .arg(ATTRIBUTE_TABLE)
        .arg(CLIENT_ATTRIBUTE_COLUMN_NAME);

#endif // SCHEMA_H
