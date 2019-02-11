#include "DatabaseAdapter.h"

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

    return createDogs.exec(dogQuery) &&
           createCats.exec(catQuery) &&
           createRabbits.exec(rabbitQuery);
}

/* === Public-Facing Database Operation Methods === */

bool DatabaseAdapter::insertDog(Dog * dog) {
    QSqlQuery addDog;

    string dogCommaSeparated;
    dog->toCommaSeperated(dogCommaSeparated);

    QString addDogQuery =
            QString("INSERT INTO %1 VALUES(null, %2)")
            .arg("dogs")
            .arg(QString::fromStdString(dogCommaSeparated));

    return addDog.exec(addDogQuery);
}

bool DatabaseAdapter::insertCat(Cat * cat) {
    QSqlQuery addCat;

    string catCommaSeparated;
    cat->toCommaSeperated(catCommaSeparated);

    QString addCatQuery =
            QString("INSERT INTO %1 VALUES(null, %2)")
            .arg("cats")
            .arg(QString::fromStdString(catCommaSeparated));

    return addCat.exec(addCatQuery);
}

bool DatabaseAdapter::insertRabbit(Rabbit * rabbit) {
    QSqlQuery addRabbit;

    string rabbitCommaSeparated;
    rabbit->toCommaSeperated(rabbitCommaSeparated);

    QString addRabbitQuery =
            QString("INSERT INTO %1 VALUES(null, %2)")
            .arg("rabbits")
            .arg(QString::fromStdString(rabbitCommaSeparated));

    return addRabbit.exec(addRabbitQuery);
}
