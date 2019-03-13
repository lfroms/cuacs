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
            QString species,
            QString gender,
            QString mainColor,
            QString breed,
            int age,
            bool neuteredOrSpayed,
            bool requiresMedicalAttention,
            QString name,
            bool hypothetical,
            int biteTendency,
            int scratchTendency,
            int dominanceTendency,
            int friendlinessAdults,
            int friendlinessChildren,
            int friendlinessAnimals,
            int noiseLevel,
            int independence,
            bool affection,
            int energyLevel,
            int anxietyLevel,
            int curiosityLevel
            );

    Animal();
    Animal(const Animal&);

    ~Animal();

    void toCommaSeperated(QString& outStr);

    void update(
            QString species,
            QString gender,
            QString mainColor,
            QString breed,
            int age,
            bool neuteredOrSpayed,
            bool requiresMedicalAttention,
            QString name,
            bool hypothetical,
            int biteTendency,
            int scratchTendency,
            int dominanceTendency,
            int friendlinessAdults,
            int friendlinessChildren,
            int friendlinessAnimals,
            int noiseLevel,
            int independence,
            bool affection,
            int energyLevel,
            int anxietyLevel,
            int curiosityLevel
            );

    void getSpecies(QString& outStr);
    void getGender(QString& outStr);
    void getMainColor(QString& outStr);
    void getName(QString& outStr);
    void getBreed(QString& outStr);
    int  getAge();
    bool getNeuteredOrSpayed();
    bool getRequiresMedicalAttention();
    int getBiteTendency();
    int getScratchTendency();
    int getDominanceTendency();
    int getFriendlinessAdults();
    int getFriendlinessChildren();
    int getFriendlinessAnimals();
    int getNoiseLevel();
    int getIndependence();
    bool getAffection();
    int getEnergyLevel();
    int getAnxietyLevel();
    int getCuriosityLevel();

private:
    QString species;
    QString gender;
    QString mainColor;
    QString name;
    QString breed;

    bool neuteredOrSpayed;
    bool requiresMedicalAttention;
    bool hypothetical;

    int age;
    int biteTendency;
    int scratchTendency;
    int dominanceTendency;
    int friendlinessAdults;
    int friendlinessChildren;
    int friendlinessAnimals;
    int noiseLevel;
    int independence;
    int affection;
    int energyLevel;
    int anxietyLevel;
    int curiosityLevel;
};

Q_DECLARE_METATYPE(Animal*)
#endif // ANIMAL_H
