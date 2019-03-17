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
    static bool resetAll();

private:
    DatabaseAdapter();
    ~DatabaseAdapter();

    static QSqlDatabase db;

    static bool setup();
};

#endif // DATABASEADAPTER_H
