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
        )
{
    update(
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
           );
}

Animal::Animal() {}

Animal::~Animal(){}

void Animal::getName(QString& outStr) {
    outStr = name;
};

void Animal::toCommaSeperated(QString& outStr){
    QString s;
    s = QString("'") + gender + QString("', ")
      + QString("'") + mainColor + QString("', ")
      + QString("'") + breed + QString("', ")
      + QString("'") + name + QString("', ")
      + QString("'") + QString::number(neuteredOrSpayed) + QString("', ")
      + QString("'") + QString::number(hypothetical) + QString("', ")
      + QString("'") + QString::number(age) + QString("', ")
      + QString("'") + QString::number(biteTendency) + QString("', ")
      + QString("'") + QString::number(scratchTendency) + QString("', ")
      + QString("'") + QString::number(friendlinessAdults) + QString("', ")
      + QString("'") + QString::number(friendlinessChildren) + QString("', ")
      + QString("'") + QString::number(noiseLevel) + QString("', ")
      + QString("'") + QString::number(aloneComfort) + QString("', ")
      + QString("'") + QString::number(likesBedSleep) + QString("', ")
      + QString("'") + QString::number(snores) + QString("', ")
      + QString("'") + QString::number(energyLevel) + QString("', ")
      + QString("'") + QString::number(comfortableVet) + QString("', ")
      + QString("'") + QString::number(comfortableHandled) + QString("', ")
      + QString("'") + QString::number(escapeTendency) + QString("'");

    outStr = s;
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
