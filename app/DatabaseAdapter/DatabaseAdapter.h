#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <QString>
#include <QSqlDatabase>
#include <QDebug>

class DatabaseAdapter {
    public:
        static DatabaseAdapter* getInstance();

    private:
        DatabaseAdapter();
        ~DatabaseAdapter();
        static QSqlDatabase db;
        static DatabaseAdapter* instance;
};

#endif // DATABASEADAPTER_H
