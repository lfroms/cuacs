#ifndef RABBIT_H
#define RABBIT_H
#include "Models/Animal.h"

class Rabbit : public Animal {
public:
    Rabbit(QString gender = QString("female"),
           QString mainColor = QString("brown"),
           QString breed = QString("Siberian Default"),
           int age = 0,
           bool neuteredOrSpayed = false,
           QString name = QString("Johanna"),
           bool hypothetical = false,
           int biteTendency = 0,
           int scratchTendency = 0,
           int friendlinessAdults = 0,
           int friendlinessChildren = 0,
           int noiseLevel = 0,
           int aloneComfort = 0,
           bool likesBedSleep = 0,
           bool snores = 0,
           int energyLevel = 0,
           int comfortableVet = 0,
           int comfortableHandled = 0,
           int escapeTendency = 0);

    Rabbit(const Rabbit&);
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

Q_DECLARE_METATYPE(Rabbit)
#endif // RABBIT_H
