#include "Seeds.h"
using namespace std;

Seeds::Seeds() {
    animals[0] = new Dog("male", "brown", "Yorkshire Terrier", 1, false, false, "Timothy", false, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0);
    animals[1] = new Dog("female", "yellow", "Labrador Retriever", 1, false, false, "Holly", false, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0);
    animals[2] = new Cat("male", "orange", "Tabby", 1, false, false, "Whiskers", false, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0);
    animals[3] = new Cat("female", "black", "American Shorthair", 1, false, false, "Salem", false, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0);
    animals[4] = new Rabbit("male", "grey", "Britannia Petite", 1, false, false, "Bugs", false, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0);

    clients[0] = new Client("Johnny Appleseed", 24, "613-928-5235", "johnny@cuacs.ca");
}

Animal** Seeds::getAnimals() {
    return animals;
}

Client** Seeds::getClients() {
    return clients;
}
