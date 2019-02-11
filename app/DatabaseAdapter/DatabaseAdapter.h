#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include <Models/dog.h>
#include <Models/cat.h>
#include <Models/rabbit.h>

#include <DatabaseAdapter/AnimalData.h>

class DatabaseAdapter {
    public:
        static DatabaseAdapter* getInstance();
        static bool insertDog(Dog*);
        static bool insertCat(Cat*);
        static bool insertAnimal(Animal*);

    private:
        DatabaseAdapter();
        ~DatabaseAdapter();
        static QSqlDatabase db;

        static bool init();
        static bool seed();
};

#endif // DATABASEADAPTER_H
