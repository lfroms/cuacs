#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QObject>
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
    void getAge(int& outInt);
    void getPhoneNumber(QString& outStr);
    void getEmail(QString& outStr);

    QString getTableName();
    void toCommaSeperated(QString& outStr);

private:
    QString name;
    int age;
    QString phoneNumber;
    QString email;
};

Q_DECLARE_METATYPE(Client*)
#endif // CLIENT_H
