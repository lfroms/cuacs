#ifndef SEEDS_H
#define SEEDS_H

#include <Models/Cat.h>
#include <Models/Dog.h>
#include <Models/Rabbit.h>
#include <Models/Animal.h>
#include <Models/Client.h>

using namespace std;

class Seeds {
    private:
        Animal* animals[25];
        Client* clients[1];

    public:
        Seeds();
        Animal** getAnimals();
        Client** getClients();
};

#endif // SEEDS_H
