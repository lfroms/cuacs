#include "dog.h"
Dog::Dog(int nFriendlinessDogs,
         int nHouseTrained,
         int nBarkTendency,
         QString nGender,
         QString nMainColor,
         QString nName,
         QString nBreed,
         bool nNeuteredorSpayed,
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
             nNeuteredorSpayed,
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
    friendlinessDogs = nFriendlinessDogs;
    houseTrained = nHouseTrained;
    barkTendency = nBarkTendency;
}

Dog::~Dog(){}

void Dog::toCommaSeperated(QString& outStr){
    QString animal;
    Animal::toCommaSeperated(animal);
    QString s = animal + QString(", ")
      + QString("'") + friendlinessDogs + QString("', ")
      + QString("'") + houseTrained + QString("', ")
      + QString("'") + barkTendency + QString("'");
    outStr = s;
}

QString Dog::getSpecies() {
    return QString("Dog");
}

QString Dog::getTableName() {
    return QString("dogs");
}

void Dog::update(int nFriendlinessDogs,
                 int nHouseTrained,
                 int nBarkTendency,
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

    friendlinessDogs = nFriendlinessDogs;
    houseTrained = nHouseTrained;
    barkTendency = nBarkTendency;
}
