#ifndef CAT_H
#define CAT_H
#include "Models/animal.h"
#include <iostream>
#include <string>
using namespace std;

class Cat : public Animal
{
public:
    Cat(bool nIndoorOutdoor,
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
        int nEscapeTendency);

    ~Cat();

    void toCommaSeperated(string& outStr);

    string getSpecies();

    void update(bool nIndoorOutdoor,
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
                int nEscapeTendency);


    string getTableName();

private:
    bool indoorOutdoor;
    int litterTrained;
    int friendlinessCats;
};

#endif // CAT_H
