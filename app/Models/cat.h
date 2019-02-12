#ifndef CAT_H
#define CAT_H
#include "Models/animal.h"
#include <iostream>
#include <QString>
using namespace std;

class Cat : public Animal
{
public:
    Cat(QString gender,
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
        int escapeTendency);

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
