#ifndef ANIMALDATA_H
#define ANIMALDATA_H
#include <Models/cat.h>
#include <Models/dog.h>
#include <Models/rabbit.h>
#include <Models/animal.h>
using namespace std;

class AnimalData {
    private:
        Animal* animals[5];
    public:
        AnimalData();
        Animal** getAnimals();
};

#endif // ANIMALDATA_H
