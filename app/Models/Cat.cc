#include "Cat.h"

Cat::Cat(QString gender,
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

Cat::Cat(const Cat & cat) : Animal(cat) {

}

Cat::~Cat(){}

void Cat::toCommaSeperated(QString& outStr){
    QString animal;
    Animal::toCommaSeperated(animal);
    outStr = animal;
}

QString Cat::getSpecies() {
    return QString("Cat");
}

QString Cat::getTableName() {
    return QString("cats");
}

void Cat::update(bool nIndoorOutdoor,
                 int nLitterTrained,
                 int nFriendlinessCats,
                 QString nGender,
                 QString nMainColor,
                 QString nName,
                 QString nBreed,
                 bool nNeuteredOrSpayed,
                 bool nHypothetical,
                 int nAge,
                 int nBiteTendency,
                 int nScratchTendency,
                 int nFriendlinessAdults,
                 int nFriendlinessChildren,
                 int nNoiseLevel,
                 int nAloneComfort,
                 int nLikesBedSleep,
                 int nSnores,
                 int nEnergyLevel,
                 int nComfortableVet,
                 int nComfortableHandled,
                 int nEscapeTendency
                 ) {

    Animal::update(nGender,
                   nMainColor,
                   nBreed,
                   nAge,
                   nNeuteredOrSpayed,
                   nName,
                   nHypothetical,
                   nBiteTendency,
                   nScratchTendency,
                   nFriendlinessAdults,
                   nFriendlinessChildren,
                   nNoiseLevel,
                   nAloneComfort,
                   nLikesBedSleep,
                   nSnores,
                   nEnergyLevel,
                   nComfortableVet,
                   nComfortableHandled,
                   nEscapeTendency);

    indoorOutdoor = nIndoorOutdoor;
    litterTrained = nLitterTrained;
    friendlinessCats = nFriendlinessCats;
}
