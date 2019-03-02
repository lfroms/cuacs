#include "rabbit.h"

Rabbit::Rabbit(QString gender,
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
               ) : Animal(
                       gender,
                       mainColor,
                       breed,
                       age,
                       neuteredOrSpayed,
                       name,
                       hypothetical,
                       biteTendency,
                       scratchTendency,
                       friendlinessAdults,
                       friendlinessChildren,
                       noiseLevel,
                       aloneComfort,
                       likesBedSleep,
                       snores,
                       energyLevel,
                       comfortableVet,
                       comfortableHandled,
                       escapeTendency
                       ) {}

Rabbit::Rabbit(const Rabbit & rabbit) : Animal(rabbit) {

}

Rabbit::~Rabbit(){}

void Rabbit::toCommaSeperated(QString& outStr){
    QString animal;
    Animal::toCommaSeperated(animal);
    outStr = animal;
}

QString Rabbit::getSpecies() {
    return QString("Rabbit");
}

QString Rabbit::getTableName() {
    return QString("rabbits");
}

void Rabbit::update(
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
        int escapeTendency,
        int nNightActivityLevel
        ) {

    Animal::update(gender,
                   mainColor,
                   breed,
                   age,
                   neuteredOrSpayed,
                   name,
                   hypothetical,
                   biteTendency,
                   scratchTendency,
                   friendlinessAdults,
                   friendlinessChildren,
                   noiseLevel,
                   aloneComfort,
                   likesBedSleep,
                   snores,
                   energyLevel,
                   comfortableVet,
                   comfortableHandled,
                   escapeTendency
                   );

    nightActivityLevel = nNightActivityLevel;
}
