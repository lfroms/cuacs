#include "animal.h"

Animal::Animal(string g, string mC, string n, bool nOS, bool h, int a,
               int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
               int s, int eL, int cV, int cH, int eT)
{
    update(g, mC, n, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT);
}

Animal::~Animal()
{}

void Animal::update(string g, string mC, string n, bool nOS, bool h, int a,
           int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
           int s, int eL, int cV, int cH, int eT)
{
    gender = g;
    mainColor = mC;
    name = n;

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
