#ifndef RABBIT_H
#define RABBIT_H
#include "Models/animal.h"

class Rabbit : public Animal {
public:
    Rabbit(
            QString gender,
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
            int escapeTendency
            );

    ~Rabbit();

    void toCommaSeperated(QString& outStr);

    void update(
            QString gender,
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
            int escapeTendency,
            int nNightActivityLevel
            );

    QString getSpecies();
    QString getTableName();

private:
    int nightActivityLevel;
};

#endif // RABBIT_H
