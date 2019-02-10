#ifndef ANIMAL_H
#define ANIMAL_H
#include <string.h>
#include <iostream>
#include <istream>
#include <sstream>
using namespace std;

class Animal
{
public:
    Animal(int i, string g, string mC, string n, string b, bool nOS, bool h, int a,
           int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
           int s, int eL, int cV, int cH, int eT);

    ~Animal();

    string toCommaSeperated();

    void update(int i, string g, string mC, string n, string b, bool nOS, bool h, int a,
                int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                int s, int eL, int cV, int cH, int eT);

    string getGender(){
        return gender;
    }

    string getMainColor(){
        return mainColor;
    }

    string getName(){
        return name;
    }

    string getBreed(){
        return breed;
    }

    bool getNeutredOrSprayed(){
        return neuteredOrSprayed;
    }

    bool getHypothetical(){
        return hypothetical;
    }

    int getId(){
        return id;
    }

    int getAge(){
        return age;
    }

    int getBiteTendency(){
        return biteTendency;
    }

    int getScratchTendency(){
        return scratchTendency;
    }

    int getFriendlinessAdults(){
        return friendlinessAdults;
    }

    int getFriendlinessChildren(){
        return friendlinessChildren;
    }

    int getNoiseLevel(){
        return noiseLevel;
    }

    int getAloneComfort(){
        return aloneComfort;
    }

    int getLikesBedSleep(){
        return likesBedSleep;
    }

    int getSnores(){
        return snores;
    }

    int getEnergylevel(){
        return energyLevel;
    }

    int getComfortableVet(){
        return comfortableVet;
    }

    int getComfortableHandled(){
        return comfortableHandled;
    }

    int getEscapeTendency(){
        return escapeTendency;
    }
private:
    string gender;
    string mainColor;
    string name;
    string breed;

    bool neuteredOrSprayed;
    bool hypothetical;

    int id;
    int age;
    int biteTendency;
    int scratchTendency;
    int friendlinessAdults;
    int friendlinessChildren;
    int noiseLevel;
    int aloneComfort;
    int likesBedSleep;
    int snores;
    int energyLevel;
    int comfortableVet;
    int comfortableHandled;
    int escapeTendency;
};

#endif // ANIMAL_H
