#include "DatabaseAdapter.h"
#include "Models/animal.h"

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

static const QString dogAttributes =
        "friendliness_dogs INTEGER NOT NULL,"
        "house_trained INTEGER NOT NULL,"
        "bark_tendency INTEGER NOT NULL";

static const QString catAttributes =
        "indoor_outdoor TEXT NOT NULL,"
        "litter_trained INTEGER NOT NULL,"
        "friendliness_cats INTEGER NOT NULL";

static const QString rabbitAttributes =
        "night_activity_level INTEGER NOT NULL";

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
            QString("CREATE TABLE IF NOT EXISTS %1(%2, %3);")
            .arg("dogs")
            .arg(commonAttributes)
            .arg(dogAttributes);

    QSqlQuery createCats;
    QString catQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2, %3);")
            .arg("cats")
            .arg(commonAttributes)
            .arg(catAttributes);

    QSqlQuery createRabbits;
    QString rabbitQuery =
            QString("CREATE TABLE IF NOT EXISTS %1(%2, %3);")
            .arg("rabbits")
            .arg(commonAttributes)
            .arg(rabbitAttributes);

    if (createDogs.exec(dogQuery) &&
            createCats.exec(catQuery) &&
            createRabbits.exec(rabbitQuery)) {
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

    qDebug() << "Hello";
    qDebug() << animalCommaSeparated;
    QString addAnimalQuery =
            QString("INSERT INTO %1 VALUES(null, %2)")
            .arg(animal->getTableName())
            .arg(animalCommaSeparated);

    return addAnimal.exec(addAnimalQuery);
}

bool DatabaseAdapter::getAnimals(Animal** animals){
    QSqlQuery query;
    QString countQuery = QString("SELECT COUNT(*) FROM %1");

    query.exec(countQuery.arg("rabbits"));
    int rabbitCount = query.value(0).toInt();
    query.exec(countQuery.arg("dogs"));
    int dogCount = query.value(0).toInt();
    query.exec(countQuery.arg("cats"));
    int catCount = query.value(0).toInt();

//    animals = new Animal*[rabbitCount + dogCount + catCount];

//    QString selectQuery = QString("SELECT * FROM %1");
//    query.exec(selectQuery.arg("rabbits"));

//    // Loading all rabbits
//    while(query.next()){
//        Rabbit r = new Rabbit(query.value(20).toInt(),
//                              query.value(1).toString(),
//                              query.value(2).toString(),
//                              query.value(6).toString(),
//                              query.value(3).toString(),
//                              query.value(5).toBool(),
//                              query.value(7).toBool(),
//                              query.value(4).toInt(),
//                              query.value(8).toInt(),
//                              query.value(9).toInt(),
//                              query.value(10).toInt(),
//                              query.value(11).toInt(),
//                              query.value(12).toInt(),
//                              query.value(13).toInt(),
//                              query.value(14).toInt(),
//                              query.value(15).toInt(),
//                              query.value(16).toInt(),
//                              query.value(17).toInt(),
//                              query.value(18).toInt(),
//                              query.value(19).toInt(),
//                              query.value(20).toInt()
//                              );
//        animals[i] = r;
//    }
}

bool DatabaseAdapter::seed() {
    for (int i = 0; i < 5; i++) {
        Animal* a = AnimalData().getAnimals()[i];
        if (!insertAnimal(a)) {
            qDebug() << "Failed to insert";
           return false;
        }
    }

    return true;
}
