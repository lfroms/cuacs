#ifndef DOG_H
#define DOG_H
#include "Models/Animal.h"

class Dog : public Animal {
public:
    Dog(QString gender = QString("female"),
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
            int curiosityLevel = 0);

    Dog(const Dog&);
    ~Dog();

    void toCommaSeperated(QString& outStr);

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

    QString getSpecies();
    QString getTableName();

private:
    int friendlinessDogs;
    int houseTrained;
    int barkTendency;
};

Q_DECLARE_METATYPE(Dog)

#endif // DOG_H
