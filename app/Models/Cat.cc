#include "Cat.h"

Cat::Cat(QString gender,
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

Cat::Cat(const Cat & cat) : Animal(cat) {

}

Cat::~Cat(){}

void Cat::toCommaSeperated(QString& outStr){
    QString animal;
    Animal::toCommaSeperated(animal);
    outStr = animal;
}

QString Cat::getSpecies() {
    return QString("Cat");
}

QString Cat::getTableName() {
    return QString("cats");
}

void Cat::update(
            bool nIndoorOutdoor,
            int nLitterTrained,
            int nFriendlinessCats,
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
            int nCuriosityLevel ) {

    Animal::update(
            nGender,
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

    indoorOutdoor = nIndoorOutdoor;
    litterTrained = nLitterTrained;
    friendlinessCats = nFriendlinessCats;
}
