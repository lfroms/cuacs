#include "cat.h"

Cat::Cat(bool nIndoorOutdoor,
         int nLitterTrained,
         int nFriendlinessCats,
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
    indoorOutdoor = nIndoorOutdoor;
    litterTrained = nLitterTrained;
    friendlinessCats = nFriendlinessCats;
}

Cat::~Cat(){}

void Cat::toCommaSeperated(QString& outStr){
    QString animal;
    Animal::toCommaSeperated(animal);
    QString s  = animal + QString(",")
	    + QString("'") + QString::number(indoorOutdoor) + QString("', ")
	    + QString("'") + QString::number(litterTrained) + QString("', ")
	    + QString("'") + QString::number(friendlinessCats) + QString("'");

    outStr = s;
}

QString Cat::getSpecies() {
    return QString("Cat");
}

QString Cat::getTableName() {
    return QString("cats");
}

void Cat::update(bool nIndoorOutdoor,
                 int nLitterTrained,
                 int nFriendlinessCats,
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

    indoorOutdoor = nIndoorOutdoor;
    litterTrained = nLitterTrained;
    friendlinessCats = nFriendlinessCats;
}
