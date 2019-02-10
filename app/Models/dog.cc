#include "dog.h"
#include <QDebug>
Dog::Dog(int nFriendlinessDogs,
         int nHouseTrained,
         int nBarkTendency,
         string nGender,
         string nMainColor,
         string nName,
         string nBreed,
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

void Dog::toCommaSeperated(string& outStr){
    stringstream s;
    string animal;
    Animal::toCommaSeperated(animal);
    s << animal << ", "
      << "'" << friendlinessDogs << "', "
      << "'" << houseTrained << "', "
      << "'" << barkTendency << "'";
    outStr = s.str();
}

string Dog::getSpecies() {
    return "Dog";
}

string Dog::getTableName() {
    return "dogs";
}

void Dog::update(int nFriendlinessDogs,
                 int nHouseTrained,
                 int nBarkTendency,
                 string nGender,
                 string nMainColor,
                 string nName,
                 string nBreed,
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
