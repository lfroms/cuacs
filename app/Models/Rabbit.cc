#include "Rabbit.h"

Rabbit::Rabbit(QString gender,
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

Rabbit::Rabbit(const Rabbit & rabbit) : Animal(rabbit) {

}

Rabbit::~Rabbit(){}

void Rabbit::toCommaSeperated(QString& outStr){
    QString animal;
    Animal::toCommaSeperated(animal);
    outStr = animal;
}

QString Rabbit::getSpecies() {
    return QString("Rabbit");
}

QString Rabbit::getTableName() {
    return QString("rabbits");
}

void Rabbit::update(
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
        int nCuriosityLevel,
        int nNightActivityLevel
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
            nCuriosityLevel
                   );

    nightActivityLevel = nNightActivityLevel;
}
