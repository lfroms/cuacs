#include "dog.h"
Dog::Dog(
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
        ) : Animal(
                gender,
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
                ) {}

Dog::Dog(const Dog & dog) : Animal(dog) {

}

Dog::~Dog(){}

void Dog::toCommaSeperated(QString& outStr){
    QString animal;
    Animal::toCommaSeperated(animal);
    outStr = animal;
}

QString Dog::getSpecies() {
    return QString("Dog");
}

QString Dog::getTableName() {
    return QString("dogs");
}

void Dog::update(QString nGender,
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
                 int nEscapeTendency,
                 int nFriendlinessDogs,
                 bool nHouseTrained,
                 int nBarkTendency
                 ) {

    Animal::update(nGender,
                   nMainColor,
                   nBreed,
                   nAge,
                   nNeuteredOrSpayed,
                   nName,
                   nHypothetical,
                   nBiteTendency,
                   nScratchTendency,
                   nFriendlinessAdults,
                   nFriendlinessChildren,
                   nNoiseLevel,
                   nAloneComfort,
                   nLikesBedSleep,
                   nSnores,
                   nEnergyLevel,
                   nComfortableVet,
                   nComfortableHandled,
                   nEscapeTendency);

    friendlinessDogs = nFriendlinessDogs;
    houseTrained = nHouseTrained;
    barkTendency = nBarkTendency;
}
