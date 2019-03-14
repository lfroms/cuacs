#include "Client.h"
#include <DatabaseAdapter/Schema.h>

Client::Client(
        QString name,
        int age,
        QString phoneNumber,
        QString email
        ) {
    update(name, age, phoneNumber, email);
}

void Client::update(
        QString nName,
        int nAge,
        QString nPhoneNumber,
        QString nEmail
        ) {
    name = nName;
    age = nAge;
    phoneNumber = nPhoneNumber;
    email = nEmail;
}

void Client::getName(QString& outStr) {
    outStr = name;
}

void Client::getAge(int &outInt) {
    outInt = age;
}

void Client::getPhoneNumber(QString &outStr) {
    outStr = phoneNumber;
}

void Client::getEmail(QString& outStr) {
    outStr = email;
}

void Client::toCommaSeparated(QString &outStr) {
    stringstream a;

    a << "'" << name.toStdString() << "', "
      << "'" << age << "', "
      << "'" << phoneNumber.toStdString() << "', "
      << "'" << email.toStdString() << "', "
      << "null";

    outStr = QString::fromStdString(a.str());
}

void Client::getTableName(QString &outStr) {
    outStr = CLIENT_TABLE;
}
