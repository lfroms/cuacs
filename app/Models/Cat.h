#ifndef CAT_H
#define CAT_H
#include "Models/Animal.h"
#include <iostream>
#include <QString>
using namespace std;

class Cat : public Animal {
public:
    Cat(    QString gender = QString("female"),
            QString mainColor = QString("brown"),
            QString breed = QString("Siberian Default"),
            int age = 0,
            bool neuteredOrSpayed = false,
            bool requiresMedicalAttention = false,
            QString name = QString("Johanna"),
            bool hypothetical = false,
            int biteTendency = 0,
            int scratchTendency = 0,
            int dominanceTendency = 0,
            int friendlinessAdults = 0,
            int friendlinessChildren = 0,
            int friendlinessAnimals = 0,
            int noiseLevel = 0,
            int independence = 0,
            bool affection = 0,
            int energyLevel = 0,
            int anxietyLevel = 0,
            int curiosityLevel = 0
            );

    Cat(const Cat&);
    ~Cat();

    void toCommaSeperated(QString& outStr);

    QString getSpecies();

    void update(bool nIndoorOutdoor,
                int nLitterTrained,
                int nFriendlinessCats,
                QString nGender,
                QString nMainColor,
                QString nBreed,
                int nAge,
                bool nNeuteredOrSpayed,
                bool nRequiresMedicalAttention,
                QString nName,
                bool nHypothetical,
                int nBiteTendency,
                int nScratchTendency,
                int nDominanceTendency,
                int nFriendlinessAdults,
                int nFriendlinessChildren,
                int nFriendlinessAnimals,
                int nNoiseLevel,
                int nIndependence,
                bool nAffection,
                int nEnergyLevel,
                int nAnxietyLevel,
                int nCuriosityLevel);


    QString getTableName();

private:
    bool indoorOutdoor;
    int litterTrained;
    int friendlinessCats;
};

Q_DECLARE_METATYPE(Cat)
#endif // CAT_H
