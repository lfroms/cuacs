#include "Client.h"

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

QString Client::getTableName() {
    return QString("clients");
}

void Client::toCommaSeperated(QString &outStr) {
    stringstream a;

    a << "'" << name.toStdString() << "', "
      << "'" << age << "', "
      << "'" << phoneNumber.toStdString() << "', "
      << "'" << email.toStdString() << "'";

    outStr = QString::fromStdString(a.str());
}
