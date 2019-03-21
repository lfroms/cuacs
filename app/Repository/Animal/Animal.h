#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>
#include <Repository/ActiveObject/ActiveObject.h>
#include <Repository/ActiveObject/AttributedObject.h>

using namespace std;

class Animal : public AttributedObject<Animal> {
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

    Animal(QSqlRecord* record);
    Animal();
    ~Animal();

    const QString toCommaSeparated();
    static const QString className();

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
