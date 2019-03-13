#include "DatabaseAdapter.h"
#include <Models/Animal/Animal.h>

#include "Config.h"
#include "Schema.h"

QSqlDatabase DatabaseAdapter::db;

DatabaseAdapter::DatabaseAdapter() {
    db = QSqlDatabase::addDatabase(DATABASE_TYPE);
    db.setDatabaseName(DATABASE_PATH);

    // Connect and init the database.
    if (!db.open() || !init()) {
        qDebug() << "Failed to connect to database.";
        return;
    }

    qDebug() << "Database connection succeeded.";
}

DatabaseAdapter::~DatabaseAdapter() {
    db.close();
}

DatabaseAdapter* DatabaseAdapter::getInstance() {
    static DatabaseAdapter instance;
    return &instance;
}

// Set up the database.
bool DatabaseAdapter::init() {
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

/* === Public-Facing Database Operation Methods === */

bool DatabaseAdapter::insertAnimal(Animal * animal) {
    QSqlQuery addAnimal;

    QString animalCommaSeparated;
    animal->toCommaSeperated(animalCommaSeparated);

    QString addAnimalQuery =
            QString("INSERT INTO %1 VALUES(null, %2);")
            .arg(ANIMAL_TABLE)
            .arg(animalCommaSeparated);

    return addAnimal.exec(addAnimalQuery);
}

bool DatabaseAdapter::getAnimals(Animal** animals) {
    QSqlQuery query;
    QString getAnimalsQuery =
            QString("SELECT * FROM %1;")
            .arg(ANIMAL_TABLE);

    query.exec(getAnimalsQuery);
    int i = 0;

    // Loading all animals
    while (query.next()) {
        Animal* r = new Animal(
                    query.value(1).toString(),
                    query.value(2).toString(),
                    query.value(3).toString(),
                    query.value(4).toString(),
                    query.value(5).toInt(),
                    query.value(6).toBool(),
                    query.value(7).toBool(),
                    query.value(8).toString(),
                    query.value(9).toBool()
                    );

        int id = query.value(0).toInt();
        r->setId(id);

        animals[i] = r;
        i++;
    }

    return true;
}

int DatabaseAdapter::getTotalAnimals() {
    QString getAnimalsCount =
            QString("SELECT COUNT(*) FROM %1;")
            .arg(ANIMAL_TABLE);
    QSqlQuery animalCountQ(getAnimalsCount);

    animalCountQ.first();
    int animalCount = animalCountQ.value(0).toInt();

    return animalCount;
}

bool DatabaseAdapter::saveClient(Client * client) {
    QSqlQuery addClient;

    QString clientCommaSeparated;
    client->toCommaSeperated(clientCommaSeparated);

    QString addClientQuery =
            QString("INSERT INTO %1 VALUES(null, %2);")
            .arg(CLIENT_TABLE)
            .arg(clientCommaSeparated);

    return addClient.exec(addClientQuery);
}

bool DatabaseAdapter::getClients(Client ** clients){
    QSqlQuery query;

    int i = 0;
    query.exec(QString("SELECT * FROM %1").arg(CLIENT_TABLE));

    while (query.next()) {
        Client* c = new Client(
                    query.value(1).toString(),
                    query.value(2).toInt(),
                    query.value(3).toString(),
                    query.value(4).toString()
                    );

        clients[i] = c;
        i++;
    }

    return true;
}

bool DatabaseAdapter::deleteClient(int clientId) {
    QSqlQuery deleteClient;

    QString deleteClientQuery =
            QString("DELETE FROM %1 WHERE id = %2;")
            .arg(CLIENT_TABLE)
            .arg(clientId);

    return deleteClient.exec(deleteClientQuery);
}

int DatabaseAdapter::getClientCount() {
    QSqlQuery clientCountQuery(QString("SELECT COUNT(*) FROM %1;").arg(CLIENT_TABLE));
    clientCountQuery.first();

    int count = clientCountQuery.value(0).toInt();
    return count;
}

bool DatabaseAdapter::seed() {
    for (int i = getTotalAnimals(); i < 25; i++) {
        Animal* a = Seeds().getAnimals()[i];

        if (!insertAnimal(a)) {
            qDebug() << "Failed to seed database.";
            return false;
        }
    }

    for (int i = getClientCount(); i < 5; i++) {
        Client* c = Seeds().getClients()[i];

        if (!saveClient(c)) {
            qDebug() << "Failed to seed database.";
            return false;
        }
    }

    qDebug() << "Seed succeeded.";
    return true;
}
