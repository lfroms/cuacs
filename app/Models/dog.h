#ifndef DOG_H
#define DOG_H
#include "Models/animal.h"

class Dog : public Animal {
public:
    Dog(QString gender = QString("female"),
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

    Dog(const Dog&);
    ~Dog();

    void toCommaSeperated(QString& outStr);

    void update(QString nGender,
                QString nMainColor,
                QString nBreed,
                int nAge,
                bool nNeuteredOrSpayed,
                QString nName,
                bool nHypothetical,
                int nBiteTendency,
                int nScratchTendency,
                int nFriendlinessAdults,
                int nFriendlinessChildren,
                int nNoiseLevel,
                int nAloneComfort,
                bool nLikesBedSleep,
                bool nSnores,
                int nEnergyLevel,
                int nComfortableVet,
                int nComfortableHandled,
                int nEscapeTendency,
                int nFriendlinessDogs,
                bool nHouseTrained,
                int nBarkTendency);

    QString getSpecies();
    QString getTableName();

private:
    int friendlinessDogs;
    int houseTrained;
    int barkTendency;
};

Q_DECLARE_METATYPE(Dog)

#endif // DOG_H
