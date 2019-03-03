#include "Dog.h"
Dog::Dog(
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
        ) : Animal(
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
                int nFriendlinessDogs,
                bool nHouseTrained,
                int nBarkTendency
                ) {

    Animal::update(nGender,
            nMainColor,
            nBreed,
            nAge,
            nNeuteredOrSpayed,
            nRequiresMedicalAttention,
            nName,
            nHypothetical,
            nBiteTendency,
            nScratchTendency,
            nDominanceTendency,
            nFriendlinessAdults,
            nFriendlinessChildren,
            nFriendlinessAnimals,
            nNoiseLevel,
            nIndependence,
            nAffection,
            nEnergyLevel,
            nAnxietyLevel,
            nCuriosityLevel);

    friendlinessDogs = nFriendlinessDogs;
    houseTrained = nHouseTrained;
    barkTendency = nBarkTendency;
}
