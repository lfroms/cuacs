#ifndef ANIMAL_H
#define ANIMAL_H
#include <string.h>
#include <iostream>
#include <istream>
#include <sstream>
using namespace std;

class Animal
{
public:
    Animal(string nGender,
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
           int nEscapeTendency);

    Animal();

    ~Animal();

    virtual void toCommaSeperated(string& outStr) = 0;

    void update(string nGender,
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
                int nEscapeTendency);

    void getName(string& outStr);

    virtual string getSpecies() = 0;

    string getTableName();

private:
    string gender;
    string mainColor;
    string name;
    string breed;

    bool neuteredOrSpayed;
    bool hypothetical;

    int age;
    int biteTendency;
    int scratchTendency;
    int friendlinessAdults;
    int friendlinessChildren;
    int noiseLevel;
    int aloneComfort;
    int likesBedSleep;
    int snores;
    int energyLevel;
    int comfortableVet;
    int comfortableHandled;
    int escapeTendency;
};

#endif // ANIMAL_H
