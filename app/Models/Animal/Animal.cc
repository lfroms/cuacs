#include "Animal.h"
using namespace std;

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

//Copy Constructor
Animal::Animal(const Animal &animal) {
    name = animal.name;
    species = animal.species;
    gender = animal.gender;
    breed = animal.breed;
    age = animal.age;
    neuteredOrSpayed = animal.neuteredOrSpayed;
    requiresMedicalAttn = animal.requiresMedicalAttn;
    color = animal.color;
    isHypothetical = animal.isHypothetical;
}

Animal::Animal() {}

Animal::~Animal() {}

void Animal::setId(int id) {
    this->id = id;
}

int Animal::getId() {
    return id;
}

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

void Animal::toCommaSeperated(QString& outStr){
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
