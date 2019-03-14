#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QObject>
#include <iostream>
#include <sstream>

using namespace std;

#include <Models/ActiveObject/ActiveObject.h>

class Client : public ActiveObject<Client> {
public:
    Client(
            QString name,
            int age,
            QString phoneNumber,
            QString email
            );

    Client(QSqlRecord* record);

    ~Client();

    void getName(QString& outStr);
    void getAge(int& outInt);
    void getPhoneNumber(QString& outStr);
    void getEmail(QString& outStr);

    void toCommaSeparated(QString& outStr);
    static void getTableName(QString& outStr);

private:
    QString name;
    int age;
    QString phoneNumber;
    QString email;
};

Q_DECLARE_METATYPE(Client*)
#endif // CLIENT_H
