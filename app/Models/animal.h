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

    void toCommaSeperated(string& outStr);

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

    void getGender(string& outStr){
        outStr = gender;
    }

    void getMainColor(string& outStr){
        outStr = mainColor;
    }

    void getName(string& outStr){
        outStr = name;
    }

    void getBreed(string& outStr){
        outStr = breed;
    }

    void getNeutredOrSprayed(bool& outBool){
        outBool = neuteredOrSpayed;
    }

    void getHypothetical(bool& outBool){
        outBool = hypothetical;
    }

    void getId(int& outInt){
        outInt = id;
    }

    void getAge(int& outInt){
        outInt = age;
    }

    void getBiteTendency(int& outInt){
        outInt = biteTendency;
    }

    void getScratchTendency(int& outInt){
        outInt = scratchTendency;
    }

    void getFriendlinessAdults(int& outInt){
        outInt = friendlinessAdults;
    }

    void getFriendlinessChildren(int& outInt){
        outInt = friendlinessChildren;
    }

    void getNoiseLevel(int& outInt){
        outInt = noiseLevel;
    }

    void getAloneComfort(int& outInt){
        outInt = aloneComfort;
    }

    void getLikesBedSleep(int& outInt){
        outInt = likesBedSleep;
    }

    void getSnores(int& outInt){
        outInt = snores;
    }

    void getEnergylevel(int& outInt){
        outInt = energyLevel;
    }

    void getComfortableVet(int& outInt){
        outInt = comfortableVet;
    }

    void getComfortableHandled(int& outInt){
        outInt = comfortableHandled;
    }

    void getEscapeTendency(int& outInt){
        outInt = escapeTendency;
    }

    virtual string getTableName() = 0;

    int id;

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
