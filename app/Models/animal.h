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
    Animal(string g,
           string mC,
           string n,
           string b,
           bool nOS,
           bool h,
           int a,
           int bT,
           int sT,
           int fA,
           int fC,
           int nL,
           int aC,
           int lBS,
           int s,
           int eL,
           int cV,
           int cH,
           int eT);

    Animal();

    ~Animal();

    virtual void toCommaSeperated(string& outStr) = 0;

    void update(string g,
                string mC,
                string n,
                string b,
                bool nOS,
                bool h,
                int a,
                int bT,
                int sT,
                int fA,
                int fC,
                int nL,
                int aC,
                int lBS,
                int s,
                int eL,
                int cV,
                int cH,
                int eT);

    void getName(string& outStr);

    virtual string getSpecies() = 0;

    string getTableName();

private:
    string gender;
    string mainColor;
    string name;
    string breed;

    bool neuteredOrSpayed;
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
