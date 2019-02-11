#include "AnimalData.h"
using namespace std;

AnimalData::AnimalData() {
    animals[0] = new Dog(6,10,5,"male", "brown", "yorkshireterrier","Timothy", true, true,0,4,2,6,8,3,1,7,5,9,3,7,2);
    animals[1] = new Dog(8,7,4,"female", "yellow", "labradorretriever", "Holly", 2, 1,0,1,3,9,7,6,3,2,8,6,3,6,4);
    animals[2] = new Cat(8,9,6,"male", "orange", "tabby", "Whiskers", 3, 1, 0,1,6,2,7,3,9,7,4,6,7,2,7);
    animals[3] = new Cat(2,9,7,"female", "black", "AmericanShorthair", "Salem", 11, 1,0,1,8,7,8,1,5,9,3,4,3,2,2);
    animals[4] = new Rabbit(6,"male", "grey", "BritanniaPetite", "Bugs", 2, 1,1,2,1,6,7,2,8,1,3,6,7,8,9);
}

Animal** AnimalData::getAnimals() {
    return animals;
}
