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
    Animal();

    ~Animal();

    void getName(QString& outStr);
    void getSpecies(QString& outStr);
    void getGender(QString& outStr);
    void getBreed(QString& outStr);
    int getAge();
    bool getNeuteredOrSpayed();
    bool getRequiresMedicalAttn();
    void getColor(QString& outStr);
    bool getIsHypothetical();

    void toCommaSeparated(QString& outStr);
    static void getTableName(QString& outStr);

    static void getAttributeTableName(QString& outStr);
    static void getAttributeIdColumnName(QString& outStr);

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

Q_DECLARE_METATYPE(Animal)

#endif // ANIMAL_H
