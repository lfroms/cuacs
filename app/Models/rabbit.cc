#include "rabbit.h"

Rabbit::Rabbit(int nNightActivityLevel,
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
    nightActivityLevel = nNightActivityLevel;
}

Rabbit::~Rabbit(){}

void Rabbit::toCommaSeperated(string& outStr){
    stringstream s;
    string animal;
    Animal::toCommaSeperated(animal);
    s << animal << ", "
      << "'" << nightActivityLevel << "'";

    outStr = s.str();
}

string Rabbit::getSpecies() {
    return "Rabbit";
}

string Rabbit::getTableName() {
    return "rabbits";
}

void Rabbit::update(int nNightActivityLevel,
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

    nightActivityLevel = nNightActivityLevel;
}
