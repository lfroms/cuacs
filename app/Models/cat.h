#ifndef CAT_H
#define CAT_H
#include "Models/animal.h"
#include <iostream>
#include <QString>
using namespace std;

class Cat : public Animal
{
public:
    Cat(bool nIndoorOutdoor,
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
        int nEscapeTendency);

    ~Cat();

    void toCommaSeperated(QString& outStr);

    QString getSpecies();

    void update(bool nIndoorOutdoor,
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
                int nEscapeTendency);


    QString getTableName();

private:
    bool indoorOutdoor;
    int litterTrained;
    int friendlinessCats;
};

#endif // CAT_H
