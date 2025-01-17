#include "DatabaseAdapter.h"

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

    QString animalQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(ANIMAL_TABLE)
            .arg(ANIMAL_SCHEMA);

    QString clientQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(CLIENT_TABLE)
            .arg(CLIENT_SCHEMA);

    QString attributesQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(ATTRIBUTE_TABLE)
            .arg(ATTRIBUTE_SCHEMA);

    QString userQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(USER_TABLE)
            .arg(USER_SCHEMA);

    QString animalAttributesQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(ANIMAL_ATTRIBUTE_TABLE)
            .arg(ANIMAL_ATTRIBUTE_SCHEMA);

    QString clientAttributesQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(CLIENT_ATTRIBUTE_TABLE)
            .arg(CLIENT_ATTRIBUTE_SCHEMA);

    bool didCompleteQueries =
            setup.exec(animalQuery) &&
            setup.exec(clientQuery) &&
            setup.exec(attributesQuery) &&
            setup.exec(userQuery) &&
            setup.exec(animalAttributesQuery) &&
            setup.exec(clientAttributesQuery);

    return didCompleteQueries;
}

bool DatabaseAdapter::resetAll() {
    qDebug() << "\nResetting all data...";

    QSqlQuery drop;

    // Need to disable foreign keys so that constraints are ignored
    // when dropping database tables.  They are re-enabled in setup();
    drop.exec("PRAGMA foreign_keys = OFF;");

    QString animalQuery =
            QString("DROP TABLE IF EXISTS %1;")
            .arg(ANIMAL_TABLE);

    QString clientQuery =
            QString("DROP TABLE IF EXISTS %1;")
            .arg(CLIENT_TABLE);

    QString attributesQuery =
            QString("DROP TABLE IF EXISTS %1;")
            .arg(ATTRIBUTE_TABLE);

    QString userQuery =
            QString("DROP TABLE IF EXISTS %1;")
            .arg(USER_TABLE);

    QString animalAttributesQuery =
            QString("DROP TABLE IF EXISTS %1;")
            .arg(ANIMAL_ATTRIBUTE_TABLE);

    QString clientAttributesQuery =
            QString("DROP TABLE IF EXISTS %1;")
            .arg(CLIENT_ATTRIBUTE_TABLE);

    bool didDropAll =
            drop.exec(animalQuery) &&
            drop.exec(clientQuery) &&
            drop.exec(attributesQuery) &&
            drop.exec(userQuery) &&
            drop.exec(animalAttributesQuery) &&
            drop.exec(clientAttributesQuery);

    if (!didDropAll) {
        qDebug() << "Could not delete tables.";
        return false;
    }

    bool didSetUp = setup();

    if (!didSetUp) {
        qDebug() << "Could not set up database tables.";
        return false;
    }

    Seeds::runAll();

    qDebug() << "\nDatabase successfully reset and seeded.";

    return true;
}
