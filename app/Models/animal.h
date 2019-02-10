#ifndef ANIMAL_H
#define ANIMAL_H
#include <string.h>
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal(string g, string mC, string n, bool nOS, bool h, int a,
           int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
           int s, int eL, int cV, int cH, int eT);
    ~Animal();
    void update(string g, string mC, string n, bool nOS, bool h, int a,
                int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                int s, int eL, int cV, int cH, int eT);

    string gender;
    string mainColor;
    string name;

    bool neuteredOrSprayed;
    bool hypothetical;

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
