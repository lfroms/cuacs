#include "Animal.h"
using namespace std;

Animal::Animal(
        QString species,
        QString gender,
        QString mainColor,
        QString breed,
        int age,
        bool neuteredOrSpayed,
        bool requiresMedicalAttention,
        QString name,
        bool hypothetical,
        int biteTendency,
        int scratchTendency,
        int dominanceTendency,
        int friendlinessAdults,
        int friendlinessChildren,
        int friendlinessAnimals,
        int noiseLevel,
        int independence,
        bool affection,
        int energyLevel,
        int anxietyLevel,
        int curiosityLevel
        ) {

    update( species,
            gender,
            mainColor,
            breed,
            age,
            neuteredOrSpayed,
            requiresMedicalAttention,
            name,
            hypothetical,
            biteTendency,
            scratchTendency,
            dominanceTendency,
            friendlinessAdults,
            friendlinessChildren,
            friendlinessAnimals,
            noiseLevel,
            independence,
            affection,
            energyLevel,
            anxietyLevel,
            curiosityLevel
           );
}

//Copy Constructor
Animal::Animal(const Animal &animal) {
    update( animal.species,
            animal.gender,
            animal.mainColor,
            animal.breed,
            animal.age,
            animal.neuteredOrSpayed,
            animal.requiresMedicalAttention,
            animal.name,
            animal.hypothetical,
            animal.biteTendency,
            animal.scratchTendency,
            animal.dominanceTendency,
            animal.friendlinessAdults,
            animal.friendlinessChildren,
            animal.friendlinessAnimals,
            animal.noiseLevel,
            animal.independence,
            animal.affection,
            animal.energyLevel,
            animal.anxietyLevel,
            animal.curiosityLevel
           );
}

Animal::Animal() {}

Animal::~Animal(){}

void Animal::getSpecies(QString& outStr) {
    outStr = species;
}

void Animal::getName(QString& outStr) {
    outStr = name;
}

void Animal::getBreed(QString& outStr) {
    outStr = breed;
}

void Animal::getGender(QString& outStr) {
    outStr = gender;
}
void Animal::getMainColor(QString& outStr) {
    outStr = mainColor;
}

int Animal::getAge() { return age; }
bool Animal::getNeuteredOrSpayed() { return neuteredOrSpayed; }
bool Animal::getRequiresMedicalAttention() { return requiresMedicalAttention; }
int Animal::getBiteTendency() { return biteTendency; }
int Animal::getScratchTendency() { return scratchTendency; }
int Animal::getDominanceTendency() { return dominanceTendency; }
int Animal::getFriendlinessAdults() { return friendlinessAdults; }
int Animal::getFriendlinessChildren() { return friendlinessChildren; }
int Animal::getFriendlinessAnimals() { return friendlinessAnimals; }
int Animal::getNoiseLevel() { return noiseLevel; }
int Animal::getIndependence() { return independence; }
bool Animal::getAffection() { return affection; }
int Animal::getEnergyLevel() { return energyLevel; }
int Animal::getAnxietyLevel() { return anxietyLevel; }
int Animal::getCuriosityLevel() { return curiosityLevel; }

void Animal::toCommaSeperated(QString& outStr){
    stringstream a;

    a << "'" << species.toStdString() << "', "
      << "'" << gender.toStdString() << "', "
      << "'" << mainColor.toStdString() << "', "
      << "'" << breed.toStdString() << "', "
      << "'" << age << "', "
      << "'" << neuteredOrSpayed << "', "
      << "'" << requiresMedicalAttention << "', "
      << "'" << name.toStdString() << "', "
      << "'" << hypothetical << "', "
      << "'" << biteTendency << "', "
      << "'" << scratchTendency << "', "
      << "'" << dominanceTendency << "', "
      << "'" << friendlinessAdults << "', "
      << "'" << friendlinessChildren << "', "
      << "'" << friendlinessAnimals << "', "
      << "'" << noiseLevel << "', "
      << "'" << independence << "', "
      << "'" << affection << "', "
      << "'" << energyLevel << "', "
      << "'" << anxietyLevel << "', "
      << "'" << curiosityLevel << "'";

    outStr = QString::fromStdString(a.str());
}

void Animal::update(
            QString nSpecies,
            QString nGender,
            QString nMainColor,
            QString nBreed,
            int nAge,
            bool nNeuteredOrSpayed,
            bool nRequiresMedicalAttention,
            QString nName,
            bool nHypothetical,
            int nBiteTendency,
            int nScratchTendency,
            int nDominanceTendency,
            int nFriendlinessAdults,
            int nFriendlinessChildren,
            int nFriendlinessAnimals,
            int nNoiseLevel,
            int nIndependence,
            bool nAffection,
            int nEnergyLevel,
            int nAnxietyLevel,
            int nCuriosityLevel
            ) {

    species = nSpecies;
    gender = nGender;
    mainColor = nMainColor;
    name = nName;
    breed = nBreed;

    neuteredOrSpayed = nNeuteredOrSpayed;
    requiresMedicalAttention = nRequiresMedicalAttention;
    hypothetical = nHypothetical;

    age = nAge;
    biteTendency = nBiteTendency;
    scratchTendency = nScratchTendency;
    dominanceTendency = nDominanceTendency;
    friendlinessAdults = nFriendlinessAdults;
    friendlinessChildren = nFriendlinessChildren;
    friendlinessAnimals = nFriendlinessAnimals;
    noiseLevel = nNoiseLevel;
    independence = nIndependence;
    affection = nAffection;
    energyLevel = nEnergyLevel;
    anxietyLevel = nAnxietyLevel;
    curiosityLevel = nCuriosityLevel;
}
