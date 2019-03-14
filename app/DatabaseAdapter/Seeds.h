#ifndef SEEDS_H
#define SEEDS_H

#include <Models/Animal/Animal.h>
#include <Models/Client/Client.h>
#include <Models/Attribute/Attribute.h>

class Seeds {
private:
    Animal* animals[25];
    Client* clients[5];
    Attribute* attributes[12];

public:
    Seeds();
    Animal** getAnimals();
    Client** getClients();
    Attribute** getAttributes();
};

#endif // SEEDS_H
