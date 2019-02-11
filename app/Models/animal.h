#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>
#include <QTextStream>
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal(QString nGender,
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

    Animal();

    ~Animal();

    virtual void toCommaSeperated(QString& outStr) = 0;

    void update(QString nGender,
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

    void getName(QString& outStr);

    virtual QString getSpecies() = 0;

    virtual QString getTableName() = 0;

private:
    QString gender;
    QString mainColor;
    QString name;
    QString breed;

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
