#include "Animal.h"
#include <DatabaseAdapter/Schema.h>

Animal::Animal(
        QString name,
        QString species,
        QString gender,
        QString breed,
        int age,
        bool neuteredOrSpayed,
        bool requiresMedicalAttn,
        QString color,
        bool isHypothetical
        ) {
    this->name = name;
    this->species = species;
    this->gender = gender;
    this->breed = breed;
    this->age = age;
    this->neuteredOrSpayed = neuteredOrSpayed;
    this->requiresMedicalAttn = requiresMedicalAttn;
    this->color = color;
    this->isHypothetical = isHypothetical;
}

// Define how the SQL record should be decomposed into this object.
Animal::Animal(QSqlRecord* record) :
    Animal(record->field("name").value().toString(),
           record->field("species").value().toString(),
           record->field("gender").value().toString(),
           record->field("breed").value().toString(),
           record->field("age").value().toInt(),
           record->field("neutered_or_spayed").value().toBool(),
           record->field("required_medical").value().toInt(),
           record->field("main_color").value().toString(),
           record->field("hypothetical").value().toBool()
           ) {
    this->id = record->field("id").value().toInt();
}

Animal::~Animal() {}

void Animal::getName(QString& outStr) {
    outStr = name;
}

void Animal::getSpecies(QString &outStr) {
    outStr = species;
}

void Animal::getGender(QString& outStr) {
    outStr = breed;
}

void Animal::getBreed(QString& outStr) {
    outStr = breed;
}
void Animal::getColor(QString& outStr) {
    outStr = color;
}

int Animal::getAge() { return age; }
bool Animal::getNeuteredOrSpayed() { return neuteredOrSpayed; }
bool Animal::getRequiresMedicalAttn() { return requiresMedicalAttn; }
bool Animal::getIsHypothetical() { return isHypothetical; }

void Animal::toCommaSeparated(QString& outStr){
    stringstream a;

    a << "'" << name.toStdString() << "', "
      << "'" << species.toStdString() << "', "
      << "'" << gender.toStdString() << "', "
      << "'" << breed.toStdString() << "', "
      << "'" << age << "', "
      << "'" << neuteredOrSpayed << "', "
      << "'" << requiresMedicalAttn << "', "
      << "'" << color.toStdString() << "', "
      << "'" << isHypothetical << "'";

    outStr = QString::fromStdString(a.str());
}

void Animal::getTableName(QString &outStr) {
    outStr = ANIMAL_TABLE;
}
