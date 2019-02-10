#include "cat.h"

Cat::Cat(bool nIndoorOutdoor,
         int nLitterTrained,
         int nFriendlinessCats,
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

void Cat::toCommaSeperated(string& outStr){
    stringstream s;
    string animal;
    Animal::toCommaSeperated(animal);
    s << animal << ","
      << "'" << indoorOutdoor << "', "
      << "'" << litterTrained << "', "
      << "'" << friendlinessCats << "'";

    outStr = s.str();
}

string Cat::getSpecies() {
    return "Cat";
}

string Cat::getTableName() {
    return "cats";
}

void Cat::update(bool nIndoorOutdoor,
                 int nLitterTrained,
                 int nFriendlinessCats,
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

    indoorOutdoor = nIndoorOutdoor;
    litterTrained = nLitterTrained;
    friendlinessCats = nFriendlinessCats;
}
