#ifndef RABBIT_H
#define RABBIT_H
#include "Models/animal.h"

class Rabbit : public Animal
{
public:
    Rabbit(int nNightActivityLevel,
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

    ~Rabbit();

    void toCommaSeperated(QString& outStr);

    void update(int nNightActivityLevel,
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
    int nightActivityLevel;
};

#endif // RABBIT_H
