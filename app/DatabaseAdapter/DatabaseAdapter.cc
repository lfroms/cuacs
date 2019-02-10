#include "DatabaseAdapter.h"

static const QString DATABASE_PATH = "cuacs.db";

QSqlDatabase DatabaseAdapter::db;

DatabaseAdapter::DatabaseAdapter() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DATABASE_PATH);

    if (!db.open()) {
        qDebug() << "Failed to connect to database.";
    } else {
        qDebug() << "Database connection succeeded.";
    }
}

DatabaseAdapter::~DatabaseAdapter() {
    db.close();

    if (instance != nullptr) {
        delete instance;
    }
}

DatabaseAdapter* DatabaseAdapter::instance = nullptr;

DatabaseAdapter* DatabaseAdapter::getInstance() {
    static DatabaseAdapter instance;

    return &instance;
}

bool DatabaseAdapter::init() {
    // Set up the database.

    return true;
}
