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
        static DatabaseAdapter* getInstance();

        static bool getAnimals(Animal** animal);
        static int getTotalAnimals();

        static bool getClients(Client**);
        static int getClientCount();

        static bool insert(QString& tableName, QString& args);
        static bool update(int& id, QString& tableName, QString& args);
        static bool destroy(int& id, QString& tableName);

    private:
        DatabaseAdapter();
        ~DatabaseAdapter();
        static QSqlDatabase db;

        static bool init();
        static bool seed();
};

#endif // DATABASEADAPTER_H
