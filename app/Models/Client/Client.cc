#include "Client.h"
#include <DatabaseAdapter/Schema.h>

Client::Client(
        QString name,
        int age,
        QString phoneNumber,
        QString email
        ) {
    this->name = name;
    this->age = age;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

Client::Client(
        QString name,
        int age,
        QString phoneNumber,
        QString email,
        int idealAnimalId
        ) {
    this->name = name;
    this->age = age;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->idealAnimalId = idealAnimalId;
}

// Define how the SQL record should be decomposed into this object.
Client::Client(QSqlRecord* record) :
    Client(record->field("name").value().toString(),
           record->field("age").value().toInt(),
           record->field("phone_number").value().toString(),
           record->field("email").value().toString()
           ) {
    this->id = record->field("id").value().toInt();
    this->idealAnimalId = record->field("ideal_animal_id").value().toInt();
}

Client::~Client() {}

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
    QString idealAsString = "'" + QString(idealAnimalId) + "'";
    QString idealAnimalNullable =
            idealAnimalId == -1 ?
                "null" :
                idealAsString;

    QString formatted = QString("'%1', %2, '%3', '%4', %5")
            .arg(name)
            .arg(age)
            .arg(phoneNumber)
            .arg(email)
            .arg(idealAnimalNullable);

    outStr = formatted;
}

void Client::getTableName(QString &outStr) {
    outStr = CLIENT_TABLE;
}
