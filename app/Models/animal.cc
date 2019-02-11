#include "animal.h"
using namespace std;

Animal::Animal(string g, 
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
               int eT)
{
    update(g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT);
}

Animal::Animal() {}

Animal::~Animal(){}

void Animal::getName(string& outStr) {
    outStr = name;
};

void Animal::toCommaSeperated(string& outStr){
    stringstream a;
    a << "'" << gender << "', "
      << "'" << mainColor << "', "
      << "'" << breed << "', "
      << "'" << name << "', "
      << "'" << neuteredOrSpayed << "', "
      << "'" << hypothetical << "', "
      << "'" << age << "', "
      << "'" << biteTendency << "', "
      << "'" << scratchTendency << "', "
      << "'" << friendlinessAdults << "', "
      << "'" << friendlinessChildren << "', "
      << "'" << noiseLevel << "', "
      << "'" << aloneComfort << "', "
      << "'" << likesBedSleep << "', "
      << "'" << snores << "', "
      << "'" << energyLevel << "', "
      << "'" << comfortableVet << "', "
      << "'" << comfortableHandled << "', "
      << "'" << escapeTendency << "'";

    outStr = a.str();
}

void Animal::update(string g, 
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
                    int eT)
{
    gender = g;
    mainColor = mC;
    name = n;
    breed = b;

    neuteredOrSpayed = nOS;
    hypothetical = h;

    age = a;
    biteTendency = bT;
    scratchTendency = sT;
    friendlinessAdults = fA;
    friendlinessChildren = fC;
    noiseLevel = nL;
    aloneComfort = aC;
    likesBedSleep = lBS;
    snores = s;
    energyLevel = eL;
    comfortableVet = cV;
    comfortableHandled = cH;
    escapeTendency = eT;
}
