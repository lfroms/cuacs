#include "rabbit.h"

Rabbit::Rabbit(int nNightActivityLevel,
               QString nGender,
               QString nMainColor,
               QString nName,
               QString nBreed,
               bool nNeuteredOrSpayed,
               bool nHypothetical,
               int nAge,
               int nBiteTendency,
               int nScratchTendency,
               int nFriendlinessAdults,
               int nFriendlinessChildren,
               int nNoiseLevel,
               int nAloneComfort,
               int nLikesBedSleep,
               int nSnores,
               int nEnergyLevel,
               int nComfortableVet,
               int nComfortableHandled,
               int nEscapeTendency)
    : Animal(nGender,
             nMainColor,
             nName,
             nBreed,
             nNeuteredOrSpayed,
             nHypothetical,
             nAge,
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
             nEscapeTendency)
{
    nightActivityLevel = nNightActivityLevel;
}

Rabbit::~Rabbit(){}

void Rabbit::toCommaSeperated(QString& outStr){
    QString animal;
    Animal::toCommaSeperated(animal);
    QString s = animal + QString(", ")
        + QString("'") + QString::number(nightActivityLevel) + QString("'");

    outStr = s;
}

QString Rabbit::getSpecies() {
    return QString("Rabbit");
}

QString Rabbit::getTableName() {
    return QString("rabbits");
}

void Rabbit::update(int nNightActivityLevel,
                    QString nGender,
                    QString nMainColor,
                    QString nName,
                    QString nBreed,
                    bool nNeuteredOrSpayed,
                    bool nHypothetical,
                    int nAge,
                    int nBiteTendency,
                    int nScratchTendency,
                    int nFriendlinessAdults,
                    int nFriendlinessChildren,
                    int nNoiseLevel,
                    int nAloneComfort,
                    int nLikesBedSleep,
                    int nSnores,
                    int nEnergyLevel,
                    int nComfortableVet,
                    int nComfortableHandled,
                    int nEscapeTendency)
{
    Animal::update(nGender,
                   nMainColor,
                   nName,
                   nBreed,
                   nNeuteredOrSpayed,
                   nHypothetical,
                   nAge,
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

    nightActivityLevel = nNightActivityLevel;
}
