#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include <Models/Dog.h>
#include <Models/Cat.h>
#include <Models/Rabbit.h>
#include <Models/Client.h>

#include <DatabaseAdapter/Seeds.h>

#include <vector>

class DatabaseAdapter {
    public:
        static DatabaseAdapter* getInstance();

        static bool insertDog(Dog*);
        static bool insertCat(Cat*);
        static bool insertAnimal(Animal*);
        static bool getAnimals(Animal** animal);
        static int getTotalAnimals();

        static bool saveClient(Client*);
        static bool deleteClient(int);
        static bool getClients(Client**);
        static int getClientCount();

    private:
        DatabaseAdapter();
        ~DatabaseAdapter();
        static QSqlDatabase db;

        static bool init();
        static bool seed();
};

#endif // DATABASEADAPTER_H
