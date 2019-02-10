#include "animal.h"
using namespace std;

Animal::Animal(string nGender,
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
    update(nGender,
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
}

Animal::Animal() {}

Animal::~Animal(){}

void Animal::getName(string& outStr) {
    outStr = name;
};

string Animal::getTableName() {
    return "animals";
}

void Animal::toCommaSeperated(string& outStr){
    stringstream a;
    a << "'" << gender << "', "
      << "'" << mainColor << "', "
      << "'" << breed << "', "
      << "'" << name << "', "
      << "'" << neuteredOrSpayed << "', "
      << "'" << hypothetical << "', "
      << "'" << age << "', "
      << "'" << biteTendency << "', "
      << "'" << scratchTendency << "', "
      << "'" << friendlinessAdults << "', "
      << "'" << friendlinessChildren << "', "
      << "'" << noiseLevel << "', "
      << "'" << aloneComfort << "', "
      << "'" << likesBedSleep << "', "
      << "'" << snores << "', "
      << "'" << energyLevel << "', "
      << "'" << comfortableVet << "', "
      << "'" << comfortableHandled << "', "
      << "'" << escapeTendency << "'";

    outStr = a.str();
}

void Animal::update(string nGender,
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
