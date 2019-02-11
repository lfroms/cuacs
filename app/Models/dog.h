#ifndef DOG_H
#define DOG_H
#include "Models/animal.h"

class Dog : public Animal
{
public:
    Dog(int nFriendlinessDogs,
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
        int nEscapeTendency);

    ~Dog();

    void toCommaSeperated(QString& outStr);

    void update(int nFriendlinessDogs,
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
                int nEscapeTendency);

    QString getSpecies();
    QString getTableName();

private:
    int friendlinessDogs;
    int houseTrained;
    int barkTendency;
};

#endif // DOG_H
