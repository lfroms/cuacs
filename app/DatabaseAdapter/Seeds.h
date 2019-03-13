#ifndef SEEDS_H
#define SEEDS_H

#include <Models/Animal/Animal.h>
#include <Models/Client/Client.h>

using namespace std;

class Seeds {
    private:
        Animal* animals[25];
        Client* clients[5];

    public:
        Seeds();
        Animal** getAnimals();
        Client** getClients();
};

#endif // SEEDS_H
