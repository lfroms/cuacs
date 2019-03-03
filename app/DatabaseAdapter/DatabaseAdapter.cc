#include "DatabaseAdapter.h"
#include "Models/Animal.h"

static const QString DATABASE_PATH = "cuacs.db";

static const QString commonAttributes =
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "gender TEXT NOT NULL,"
        "main_color TEXT NOT NULL,"
        "breed TEXT NOT NULL,"
        "age INTEGER NOT NULL,"
        "neutered_or_spayed INTEGER NOT NULL,"
        "name TEXT NOT NULL,"
        "hypothetical INTEGER NOT NULL,"
        "bite_tendency INTEGER NOT NULL,"
        "scratch_tendency INTEGER NOT NULL,"
        "friendliness_adults INTEGER NOT NULL,"
        "friendliness_children INTEGER NOT NULL,"
        "noise_level INTEGER NOT NULL,"
        "alone_comfort INTEGER NOT NULL,"
        "likes_bed_sleep INTEGER NOT NULL,"
        "snores INTEGER NOT NULL,"
        "energy_level INTEGER NOT NULL,"
        "comfortable_vet INTEGER NOT NULL,"
        "comfortable_handled INTEGER NOT NULL,"
        "escape_tendency INTEGER NOT NULL";

static const QString clientSchema =
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "name TEXT NOT NULL,"
        "age INTEGER NOT NULL,"
        "phone_number TEXT NOT NULL,"
        "email TEXT NOT NULL";

QSqlDatabase DatabaseAdapter::db;

DatabaseAdapter::DatabaseAdapter() {
    db = QSqlDatabase::addDatabase("QSQLITE");
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
    QSqlQuery createDogs;
    QString dogQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg("dogs")
            .arg(commonAttributes);

    QSqlQuery createCats;
    QString catQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg("cats")
            .arg(commonAttributes);

    QSqlQuery createRabbits;
    QString rabbitQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg("rabbits")
            .arg(commonAttributes);

    QSqlQuery createClients;
    QString clientQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg("clients")
            .arg(clientSchema);

    if (createDogs.exec(dogQuery) &&
            createCats.exec(catQuery) &&
            createRabbits.exec(rabbitQuery) &&
            createClients.exec(clientQuery)) {
        return seed();
    } else {
        return false;
    }
}

/* === Public-Facing Database Operation Methods === */

bool DatabaseAdapter::insertAnimal(Animal * animal) {
    QSqlQuery addAnimal;

    QString animalCommaSeparated;
    animal->toCommaSeperated(animalCommaSeparated);

    QString addAnimalQuery =
            QString("INSERT INTO %1 VALUES(null, %2);")
            .arg(animal->getTableName())
            .arg(animalCommaSeparated);

    return  addAnimal.exec(addAnimalQuery);
}

bool DatabaseAdapter::getAnimals(Animal** animals){
    QSqlQuery query;
    query.exec("SELECT * FROM rabbits;");
    int i = 0;

    // Loading all rabbits
    while (query.next()) {
        Rabbit* r = new Rabbit(
                    query.value(1).toString(),
                    query.value(2).toString(),
                    query.value(3).toString(),
                    query.value(4).toInt(),
                    query.value(5).toBool(),
                    query.value(6).toString(),
                    query.value(7).toBool(),
                    query.value(8).toInt(),
                    query.value(9).toInt(),
                    query.value(10).toInt(),
                    query.value(11).toInt(),
                    query.value(12).toInt(),
                    query.value(13).toInt(),
                    query.value(14).toBool(),
                    query.value(15).toBool(),
                    query.value(16).toInt(),
                    query.value(17).toInt(),
                    query.value(18).toInt(),
                    query.value(19).toInt()
                    );

        animals[i] = r;
        i++;
    }

    query.exec("SELECT * FROM dogs");

    // Loading all dogs
    while (query.next()) {
        Dog* d = new Dog(
                    query.value(1).toString(),
                    query.value(2).toString(),
                    query.value(3).toString(),
                    query.value(4).toInt(),
                    query.value(5).toBool(),
                    query.value(6).toString(),
                    query.value(7).toBool(),
                    query.value(8).toInt(),
                    query.value(9).toInt(),
                    query.value(10).toInt(),
                    query.value(11).toInt(),
                    query.value(12).toInt(),
                    query.value(13).toInt(),
                    query.value(14).toBool(),
                    query.value(15).toBool(),
                    query.value(16).toInt(),
                    query.value(17).toInt(),
                    query.value(18).toInt(),
                    query.value(19).toInt()
                    );

        animals[i] = d;
        i++;
    }

    query.exec("SELECT * FROM cats");

    // Loading all cats
    while (query.next()) {
        Cat* c = new Cat(
                    query.value(1).toString(),
                    query.value(2).toString(),
                    query.value(3).toString(),
                    query.value(4).toInt(),
                    query.value(5).toBool(),
                    query.value(6).toString(),
                    query.value(7).toBool(),
                    query.value(8).toInt(),
                    query.value(9).toInt(),
                    query.value(10).toInt(),
                    query.value(11).toInt(),
                    query.value(12).toInt(),
                    query.value(13).toInt(),
                    query.value(14).toBool(),
                    query.value(15).toBool(),
                    query.value(16).toInt(),
                    query.value(17).toInt(),
                    query.value(18).toInt(),
                    query.value(19).toInt()
                    );

        animals[i] = c;
        i++;
    }

    return true;
}

int DatabaseAdapter::getTotalAnimals() {
    QSqlQuery rabbitCountQ("SELECT COUNT(*) FROM rabbits;");
    rabbitCountQ.first();
    int rabbitCount = rabbitCountQ.value(0).toInt();

    QSqlQuery catCountQ("SELECT COUNT(*) FROM cats;");
    catCountQ.first();
    int catCount = catCountQ.value(0).toInt();

    QSqlQuery dogCountQ("SELECT COUNT(*) FROM dogs;");
    dogCountQ.first();
    int dogCount = dogCountQ.value(0).toInt();

    return rabbitCount + dogCount + catCount;
}

bool DatabaseAdapter::saveClient(Client * client) {
    QSqlQuery addClient;

    QString clientCommaSeparated;
    client->toCommaSeperated(clientCommaSeparated);

    QString addClientQuery =
            QString("INSERT INTO %1 VALUES(null, %2);")
            .arg(client->getTableName())
            .arg(clientCommaSeparated);

    return addClient.exec(addClientQuery);
}

bool DatabaseAdapter::getClients(Client ** clients){
    QSqlQuery query;

    int i = 0;
    query.exec("SELECT * FROM clients");

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
            .arg("clients")
            .arg(clientId);

    return deleteClient.exec(deleteClientQuery);
}

int DatabaseAdapter::getClientCount() {
    QSqlQuery clientCountQuery("SELECT COUNT(*) FROM clients;");
    clientCountQuery.first();

    int count = clientCountQuery.value(0).toInt();
    return count;
}

bool DatabaseAdapter::seed() {
    for (int i = getTotalAnimals(); i < 5; i++) {
        Animal* a = Seeds().getAnimals()[i];

        if (!insertAnimal(a)) {
            qDebug() << "Failed to seed database.";
            return false;
        }
    }

    for (int i = getClientCount(); i < 1; i++) {
        Client* c = Seeds().getClients()[i];

        if (!saveClient(c)) {
            qDebug() << "Failed to seed database.";
            return false;
        }
    }

    qDebug() << "Seed succeeded.";
    return true;
}
