#include "Client.h"

Client::Client(
        QString name,
        int age,
        QString phoneNumber,
        QString email,
        int homeSqFoot,
        bool ownedAnimal,
        bool ownsAnimal,
        int salary,
        int hrsDedication,
        bool hasChildren,
        int idealAnimalId
        ) {
    this->name = name;
    this->age = age;
    this->phoneNumber = phoneNumber;
    this->email = email;
    this->homeSqFoot = homeSqFoot;
    this->ownedAnimal = ownedAnimal;
    this->ownsAnimal = ownsAnimal;
    this->salary = salary;
    this->hrsDedication = hrsDedication;
    this->hasChildren = hasChildren;
    this->idealAnimalId = idealAnimalId;
}

// Define how the SQL record should be decomposed into this object.
Client::Client(QSqlRecord* record) :
    Client(record->field("name").value().toString(),
           record->field("age").value().toInt(),
           record->field("phone_number").value().toString(),
           record->field("email").value().toString(),
           record->field("home_sq_foot").value().toInt(),
           record->field("owned_animal").value().toBool(),
           record->field("owns_animal").value().toBool(),
           record->field("salary").value().toInt(),
           record->field("hrs_dedication").value().toInt(),
           record->field("has_children").value().toBool()
           ) {
    this->id = record->field("id").value().toInt();

    bool dbIdealAnimalIdNull = record->field("ideal_animal_id").isNull();
    this->idealAnimalId = dbIdealAnimalIdNull ? -1 : record->field("ideal_animal_id").value().toInt();
}

Client::Client() {}

Client::~Client() {}

const QString Client::toCommaSeparated() {
    QString idealAsString = "'" + QString(idealAnimalId) + "'";
    QString idealAnimalNullable =
            idealAnimalId == -1 ?
                "null" :
                idealAsString;

    QString formatted = QString("'%1', %2, '%3', '%4', %5, %6, %7, %8, %9, %10, %11")
            .arg(name)
            .arg(age)
            .arg(phoneNumber)
            .arg(email)
            .arg(homeSqFoot)
            .arg(ownedAnimal)
            .arg(ownsAnimal)
            .arg(salary)
            .arg(hrsDedication)
            .arg(hasChildren)
            .arg(idealAnimalNullable);

    return formatted;
}

const QString Client::className() {
    return "client";
}
