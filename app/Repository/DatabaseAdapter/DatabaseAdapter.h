#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include <Repository/Animal/Animal.h>
#include <Repository/Client/Client.h>

#include <Repository/DatabaseAdapter/Seeds.h>

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
