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

    string animalCommaSeparated;
    animal->toCommaSeperated(animalCommaSeparated);

    QString addAnimalQuery =
            QString("INSERT INTO %1 VALUES(null, %2)")
            .arg(QString::fromStdString(animal->getTableName()))
            .arg(QString::fromStdString(animalCommaSeparated));

    return addAnimal.exec(addAnimalQuery);
}

bool DatabaseAdapter::getAnimals(Animal** animal){
    QSqlQuery query;
    QString countQuery = QString("SELECT COUNT(*) FROM %1");

    query.exec(countQuery.arg("rabbits"));
    int rabbitCount = query.value(1).toInt();
    query.exec(countQuery.arg("dogs"));
    int dogCount = query.value(1).toInt();
    query.exec(countQuery.arg("cats"));
    int catCount = query.value(1).toInt();
    cout << rabbitCount << "\n" << dogCount << "\n" << catCount << endl;
//    Animal** loadedAnimals = new Animal*[rabb];

//    query.exec()
//    // Loading all rabbits
//    while(query.next()){
//        Rabbit r = new Rabbit(query.value(1).toString(),
//                              query.value());
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
