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
        "friendliness_dogs INTEGER,"
        "house_trained INTEGER,"
        "bark_tendency INTEGER";

static const QString catAttributes =
        "indoor_outdoor TEXT,"
        "litter_trained INTEGER,"
        "friendliness_cats INTEGER";

static const QString rabbitAttributes =
        "night_activity_level INTEGER";

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

    qDebug() << "Adding";
    QString addAnimalQuery =
            QString("INSERT INTO %1 VALUES(null, %2, null, null, null)")
            .arg(animal->getTableName())
            .arg(animalCommaSeparated);

    return addAnimal.exec(addAnimalQuery);
}

bool DatabaseAdapter::getAnimals(Animal** animals, int& numAnimals){

    QSqlQuery rabbitCountQ("SELECT COUNT(*) FROM rabbits;");
    rabbitCountQ.first();
    int rabbitCount = rabbitCountQ.value(0).toInt();

    QSqlQuery catCountQ("SELECT COUNT(*) FROM cats;");
    catCountQ.first();
    int catCount = catCountQ.value(0).toInt();

    QSqlQuery dogCountQ("SELECT COUNT(*) FROM dogs;");
    dogCountQ.first();
    int dogCount = dogCountQ.value(0).toInt();

    numAnimals = rabbitCount + dogCount + catCount;

    animals = new Animal*[numAnimals];

    QSqlQuery query;
    query.exec("SELECT * FROM rabbits");
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

bool DatabaseAdapter::seed() {
    for (int i = 0; i < 5; i++) {
        Animal* a = AnimalData().getAnimals()[i];
        if (!insertAnimal(a)) {
            qDebug() << "Failed to insert";
            return false;
        }
    }

    qDebug() << "Succeded seeding";
    return true;
}
