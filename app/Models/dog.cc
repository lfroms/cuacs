#include "dog.h"

Dog::Dog(int fD, int hT, int bTY, int i, string g, string mC, string n, string b, bool nOS,
         bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
         int s, int eL, int cV, int cH, int eT)
    : Animal(i, g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT)

{
    friendlinessDogs = fD;
    houseTrained = hT;
    barkTendency = bTY;
}

Dog::~Dog(){}

string Dog::toCommaSeperated()
{
    stringstream s;
    s << Animal::toCommaSeperated() << "," << friendlinessDogs << "," << houseTrained << "," << barkTendency;

    return s.str();
}

void Dog::update(int fD, int hT, int bTY, int i, string g, string mC, string n, string b, bool nOS,
                 bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                 int s, int eL, int cV, int cH, int eT)
{
    Animal::update(i, g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT);
    friendlinessDogs = fD;
    houseTrained= hT;
    barkTendency = bTY;
}
