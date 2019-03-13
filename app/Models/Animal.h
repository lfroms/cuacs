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
            QString name,
            QString species,
            QString gender,
            QString breed,
            int age,
            bool neuteredOrSpayed,
            bool requiresMedicalAttn,
            QString color,
            bool isHypothetical
            );

    Animal();
    Animal(const Animal&);

    ~Animal();

    void toCommaSeperated(QString& outStr);

    void getName(QString& outStr);
    void getSpecies(QString& outStr);
    void getGender(QString& outStr);
    void getBreed(QString& outStr);
    int getAge();
    bool getNeuteredOrSpayed();
    bool getRequiresMedicalAttn();
    void getColor(QString& outStr);
    bool getIsHypothetical();

    void setId(int id);
    int getId();

private:
    int id;
    QString name;
    QString species;
    QString gender;
    QString breed;
    int age;
    bool neuteredOrSpayed;
    bool requiresMedicalAttn;
    QString color;
    bool isHypothetical;
};

Q_DECLARE_METATYPE(Animal*)

#endif // ANIMAL_H
