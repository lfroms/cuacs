#ifndef SEEDS_H
#define SEEDS_H

#include <Models/cat.h>
#include <Models/dog.h>
#include <Models/rabbit.h>
#include <Models/animal.h>
#include <Models/Client.h>

using namespace std;

class Seeds {
    private:
        Animal* animals[5];
        Client* clients[1];

    public:
        Seeds();
        Animal** getAnimals();
        Client** getClients();
};

#endif // SEEDS_H
