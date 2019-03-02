#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <iostream>
#include <sstream>

using namespace std;

class Client {
public:
    Client(
            QString name,
            int age,
            QString phoneNumber,
            QString email
            );
    void update(
            QString name,
            int age,
            QString phoneNumber,
            QString email
            );
    void getName(QString& outStr);

    QString getTableName();
    void toCommaSeperated(QString& outStr);

private:
    QString name;
    int age;
    QString phoneNumber;
    QString email;
};

#endif // CLIENT_H
