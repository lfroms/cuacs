#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>
#include <ActiveObject/ActiveObject.h>
#include <ActiveObject/AttributedObject.h>

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
    ~Animal();

    const QString getName();
    const QString getSpecies();
    const QString getGender();
    const QString getBreed();
    int getAge();
    bool getNeuteredOrSpayed();
    bool getRequiresMedicalAttn();
    const QString getColor();
    bool getIsHypothetical();

    const QString toCommaSeparated();
    static const QString getTableName();

    static const QString getAttributeTableName();
    static const QString getAttributeIdColumnName();

private:
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
