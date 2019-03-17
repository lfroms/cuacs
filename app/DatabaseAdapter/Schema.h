#ifndef SCHEMA_H
#define SCHEMA_H

#include <QString>

static const QString ANIMAL_TABLE = "animals";
static const QString CLIENT_TABLE = "clients";
static const QString ATTRIBUTE_TABLE = "attributes";

static const QString ANIMAL_ATTRIBUTE_TABLE = "animals_attributes";
static const QString ANIMAL_ATTRIBUTE_COLUMN_NAME = "animal_id";

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
            "name TEXT NOT NULL,"
            "age INTEGER NOT NULL,"
            "phone_number TEXT NOT NULL,"
            "email TEXT NOT NULL,"
            "ideal_animal_id INTEGER,"
            "FOREIGN KEY (ideal_animal_id) REFERENCES %1(id)"
            )
        .arg(ANIMAL_TABLE);

static const QString ATTRIBUTE_SCHEMA =
        QString(
            "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
            "name TEXT NOT NULL UNIQUE,"
            "description TEXT,"
            "type TEXT"
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

#endif // SCHEMA_H
