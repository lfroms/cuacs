#include "DatabaseAdapter.h"

#include "Config.h"
#include "Schema.h"

QSqlDatabase DatabaseAdapter::db;

DatabaseAdapter::DatabaseAdapter() {}

DatabaseAdapter::~DatabaseAdapter() {
    db.close();
}

bool DatabaseAdapter::init() {
    db = QSqlDatabase::addDatabase(DATABASE_TYPE);
    db.setDatabaseName(DATABASE_PATH);

    // Connect and init the database.
    if (!db.open() || !setup()) {
        qDebug() << "Failed to connect to database.";
        return false;
    }

    qDebug() << "Database connection succeeded.";
    return true;
}

// Set up the database.
bool DatabaseAdapter::setup() {
    QSqlQuery setup;
    setup.exec("PRAGMA foreign_keys = ON;");

    QSqlQuery createAnimals;
    QString animalQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(ANIMAL_TABLE)
            .arg(ANIMAL_SCHEMA);

    QSqlQuery createClients;
    QString clientQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(CLIENT_TABLE)
            .arg(CLIENT_SCHEMA);

    QSqlQuery createAttributes;
    QString attributesQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2)")
            .arg(ATTRIBUTE_TABLE)
            .arg(ATTRIBUTE_SCHEMA);

    QSqlQuery createAnimalAttributes;
    QString animalAttributesQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2)")
            .arg(ANIMAL_ATTRIBUTE_TABLE)
            .arg(ANIMAL_ATTRIBUTE_SCHEMA);

    bool didCompleteQueries =
            createAnimals.exec(animalQuery) &&
            createClients.exec(clientQuery) &&
            createAttributes.exec(attributesQuery) &&
            createAnimalAttributes.exec(animalAttributesQuery);

    if (didCompleteQueries) {
        seed();
        return true;
    }

    return false;
}

void DatabaseAdapter::seed() {
    Seeds::runAll();
    qDebug() << "Database seeded.";
}
