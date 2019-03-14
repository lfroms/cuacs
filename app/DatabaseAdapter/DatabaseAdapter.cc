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
        return seed();
    }

    return false;
}

bool DatabaseAdapter::seed() {
    for (int i = Animal::count(); i < 25; i++) {
        Animal* a = Seeds().getAnimals()[i];

        bool animalSaved = a->create();

        QString test;
        a->getName(test);

        if (!animalSaved) {
            qDebug() << "Failed to seed database.";
            return false;
        }
    }

    for (int i = Client::count(); i < 5; i++) {
        Client* c = Seeds().getClients()[i];

        bool clientSaved = c->create();

        if (!clientSaved) {
            qDebug() << "Failed to seed database.";
            return false;
        }
    }

    qDebug() << "Seed succeeded.";
    return true;
}
