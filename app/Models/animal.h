#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>
#include <QTextStream>
#include <iostream>
#include <sstream>
#include <QObject>
using namespace std;

class Animal {
public:
    Animal(
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

    Animal();
    Animal(const Animal&);

    ~Animal();

    virtual void toCommaSeperated(QString& outStr) = 0;

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
            int escapeTendency
            );

    void getGender(QString& outStr);
    void getMainColor(QString& outStr);
    void getName(QString& outStr);
    void getBreed(QString& outStr);
    int  getAge();
    bool getNeuteredOrSpayed();
    int getBiteTendency();
    int getScratchTendency();
    int getFriendlinessAdults();
    int getFriendlinessChildren();
    int getNoiseLevel();
    int getAloneComfort();
    bool getLikesBedSleep();
    bool getSnores();
    int getEnergyLevel();
    int getComfortableVet();
    int getComfortableHandled();
    int getEscapeTendency();

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

Q_DECLARE_METATYPE(Animal*)
#endif // ANIMAL_H
