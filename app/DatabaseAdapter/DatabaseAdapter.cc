#include "DatabaseAdapter.h"
#include "Models/Animal.h"

static const QString DATABASE_PATH = "cuacs.db";
static const QString ANIMAL_TABLE = "animals";
static const QString CLIENT_TABLE = "clients";

static const QString commonAttributes =
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
    QSqlQuery createAnimals;
    QString animalQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(ANIMAL_TABLE)
            .arg(commonAttributes);

    QSqlQuery createClients;
    QString clientQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2);")
            .arg(CLIENT_TABLE)
            .arg(clientSchema);

    if (createAnimals.exec(animalQuery) &&
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
            .arg(ANIMAL_TABLE)
            .arg(animalCommaSeparated);

    return  addAnimal.exec(addAnimalQuery);
}

bool DatabaseAdapter::getAnimals(Animal** animals){
    QSqlQuery query;
    query.exec(QString("SELECT * FROM %1;").arg(ANIMAL_TABLE));
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
                    query.value(9).toBool(),
                    query.value(10).toInt(),
                    query.value(11).toInt(),
                    query.value(12).toInt(),
                    query.value(13).toInt(),
                    query.value(14).toInt(),
                    query.value(15).toInt(),
                    query.value(16).toInt(),
                    query.value(17).toInt(),
                    query.value(18).toInt(),
                    query.value(19).toInt(),
                    query.value(20).toInt(),
                    query.value(21).toInt()
                    );

        animals[i] = r;
        i++;
    }

    return true;
}

int DatabaseAdapter::getTotalAnimals() {
    QSqlQuery animalCountQ(QString("SELECT COUNT(*) FROM %1;").arg(ANIMAL_TABLE));
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
