#include "animal.h"
using namespace std;

Animal::Animal(int i, string g, string mC, string n, string b, bool nOS, bool h, int a,
               int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
               int s, int eL, int cV, int cH, int eT)
{
    update(i, g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT);
}

Animal::~Animal(){}

string Animal::toCommaSeperated()
{
    stringstream a;
    a << gender << "," << mainColor << ","  << breed << "," << name << "," << neuteredOrSprayed << "," << hypothetical
      << "," << age << "," << biteTendency << "," << scratchTendency << "," << friendlinessAdults << "," << friendlinessChildren
      << "," << friendlinessAdults << "," << friendlinessChildren << "," << noiseLevel << "," << aloneComfort << ","
      << "," << likesBedSleep << "," << snores << "," << energyLevel << "," << comfortableVet << "," << comfortableHandled
      << "," << escapeTendency;

    return a.str();
}

void Animal::update(int i, string g, string mC, string n, string b, bool nOS, bool h, int a,
           int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
           int s, int eL, int cV, int cH, int eT)
{
    id = i;
    gender = g;
    mainColor = mC;
    name = n;
    breed = b;

    neuteredOrSprayed = nOS;
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
