#include "animal.h"
using namespace std;

Animal::Animal(
        QString gender,
        QString mainColor,
        QString breed,
        int age,
        bool neuteredOrSpayed,
        QString name,
        bool hypothetical,
        int biteTendency,
        int scratchTendency,
        int friendlinessAdults,
        int friendlinessChildren,
        int noiseLevel,
        int aloneComfort,
        bool likesBedSleep,
        bool snores,
        int energyLevel,
        int comfortableVet,
        int comfortableHandled,
        int escapeTendency
        ) {

    update(gender,
           mainColor,
           breed,
           age,
           neuteredOrSpayed,
           name,
           hypothetical,
           biteTendency,
           scratchTendency,
           friendlinessAdults,
           friendlinessChildren,
           noiseLevel,
           aloneComfort,
           likesBedSleep,
           snores,
           energyLevel,
           comfortableVet,
           comfortableHandled,
           escapeTendency
           );
}

Animal::Animal(const Animal &animal) {
    update(animal.gender,
           animal.mainColor,
           animal.breed,
           animal.age,
           animal.neuteredOrSpayed,
           animal.name,
           animal.hypothetical,
           animal.biteTendency,
           animal.scratchTendency,
           animal.friendlinessAdults,
           animal.friendlinessChildren,
           animal.noiseLevel,
           animal.aloneComfort,
           animal.likesBedSleep,
           animal.snores,
           animal.energyLevel,
           animal.comfortableVet,
           animal.comfortableHandled,
           animal.escapeTendency
           );
}

Animal::Animal() {}

Animal::~Animal(){}

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
int Animal::getBiteTendency() { return biteTendency; }
int Animal::getScratchTendency() { return scratchTendency; }
int Animal::getFriendlinessAdults() { return friendlinessAdults; }
int Animal::getFriendlinessChildren() { return friendlinessChildren; }
int Animal::getNoiseLevel() { return noiseLevel; }
int Animal::getAloneComfort() { return aloneComfort; }
bool Animal::getLikesBedSleep() { return likesBedSleep; }
bool Animal::getSnores() { return snores; }
int Animal::getEnergyLevel() { return energyLevel; }
int Animal::getComfortableVet() { return comfortableVet; }
int Animal::getComfortableHandled() { return comfortableHandled; }
int Animal::getEscapeTendency() { return escapeTendency; }

void Animal::toCommaSeperated(QString& outStr){
    stringstream a;

    a << "'" << gender.toStdString() << "', "
      << "'" << mainColor.toStdString() << "', "
      << "'" << breed.toStdString() << "', "
      << "'" << age << "', "
      << "'" << neuteredOrSpayed << "', "
      << "'" << name.toStdString() << "', "
      << "'" << hypothetical << "', "
      << "'" << biteTendency << "', "
      << "'" << scratchTendency << "', "
      << "'" << friendlinessAdults << "', "
      << "'" << friendlinessChildren << "', "
      << "'" << noiseLevel << "', "
      << "'" << aloneComfort << "', "
      << "'" << likesBedSleep << "', "
      << "'" << snores << "', "
      << "'" << energyLevel << "', "
      << "'" << comfortableVet << "', "
      << "'" << comfortableHandled << "', "
      << "'" << escapeTendency << "'";

    outStr = QString::fromStdString(a.str());
}

void Animal::update(
        QString nGender,
        QString nMainColor,
        QString nBreed,
        int nAge,
        bool nNeuteredOrSpayed,
        QString nName,
        bool nHypothetical,
        int nBiteTendency,
        int nScratchTendency,
        int nFriendlinessAdults,
        int nFriendlinessChildren,
        int nNoiseLevel,
        int nAloneComfort,
        bool nLikesBedSleep,
        bool nSnores,
        int nEnergyLevel,
        int nComfortableVet,
        int nComfortableHandled,
        int nEscapeTendency
        ) {

    gender = nGender;
    mainColor = nMainColor;
    name = nName;
    breed = nBreed;

    neuteredOrSpayed = nNeuteredOrSpayed;
    hypothetical = nHypothetical;

    age = nAge;
    biteTendency = nBiteTendency;
    scratchTendency = nScratchTendency;
    friendlinessAdults = nFriendlinessAdults;
    friendlinessChildren = nFriendlinessChildren;
    noiseLevel = nNoiseLevel;
    aloneComfort = nAloneComfort;
    likesBedSleep = nLikesBedSleep;
    snores = nSnores;
    energyLevel = nEnergyLevel;
    comfortableVet = nComfortableVet;
    comfortableHandled = nComfortableHandled;
    escapeTendency = nEscapeTendency;
}
