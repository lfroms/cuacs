#ifndef CAT_H
#define CAT_H
#include "Models/Animal.h"
#include <iostream>
#include <QString>
using namespace std;

class Cat : public Animal {
public:
    Cat(QString gender = QString("female"),
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

    Cat(const Cat&);
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

Q_DECLARE_METATYPE(Cat)
#endif // CAT_H
