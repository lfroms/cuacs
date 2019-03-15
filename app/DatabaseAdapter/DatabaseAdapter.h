#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include <Models/Animal/Animal.h>
#include <Models/Client/Client.h>

#include <DatabaseAdapter/Seeds.h>

#include <vector>

class DatabaseAdapter {
public:
    static bool init();

private:
    DatabaseAdapter();
    ~DatabaseAdapter();

    static QSqlDatabase db;

    static bool setup();
    static void seed();
};

#endif // DATABASEADAPTER_H
