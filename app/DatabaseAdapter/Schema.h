#ifndef SCHEMA_H
#define SCHEMA_H

#include <QString>

static const QString ANIMAL_TABLE = "animals";
static const QString CLIENT_TABLE = "clients";
static const QString ATTRIBUTE_TABLE = "attributes";
static const QString ANIMAL_ATTRIBUTE_TABLE = "animals_attributes";

static const QString ANIMAL_SCHEMA =
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "species TEXT NOT NULL,"
        "gender TEXT NOT NULL,"
        "main_color TEXT NOT NULL,"
        "breed TEXT NOT NULL,"
        "age INTEGER NOT NULL,"
        "neutered_or_spayed INTEGER NOT NULL,"
        "requires_medical INTEGER NOT NULL,"
        "name TEXT NOT NULL,"
        "hypothetical INTEGER NOT NULL,"
        "bite_tendency INTEGER NOT NULL,"
        "scratch_tendency INTEGER NOT NULL,"
        "dominance_tendency INTEGER NOT NULL,"
        "friendliness_adults INTEGER NOT NULL,"
        "friendliness_children INTEGER NOT NULL,"
        "friendliness_animals INTEGER NOT NULL,"
        "noise_level INTEGER NOT NULL,"
        "independence INTEGER NOT NULL,"
        "affection INTEGER NOT NULL,"
        "energy_level INTEGER NOT NULL,"
        "anxiety_level INTEGER NOT NULL,"
        "curiosity_level INTEGER NOT NULL";

static const QString CLIENT_SCHEMA =
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "name TEXT NOT NULL,"
        "age INTEGER NOT NULL,"
        "phone_number TEXT NOT NULL,"
        "email TEXT NOT NULL";

static const QString ATTRIBUTE_SCHEMA =
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "name TEXT NOT NULL,"
        "description TEXT";

static const QString ANIMAL_ATTRIBUTE_SCHEMA = QString(
            "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
            "animal_id INTEGER NOT NULL,"
            "attribute_id INTEGER NOT NULL,"
            "value INTEGER NOT NULL,"
            "FOREIGN KEY (animal_id) REFERENCES %1(id),"
            "FOREIGN KEY (attribute_id) REFERENCES %2(id)"
            )
        .arg(ANIMAL_TABLE)
        .arg(ATTRIBUTE_TABLE);

#endif // SCHEMA_H
