#include "dog.h"

Dog::Dog(int fD, int hT, int bTY, string g, string mC, string n, bool nOS,
         bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
         int s, int eL, int cV, int cH, int eT)
    : Animal(g, mC, n, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT)

{
    friendlinessDogs = fD;
    houseTrained = hT;
    barkTendency = bTY;
}

Dog::~Dog()
{}
void Dog::update(int fD, int hT, int bTY, string g, string mC, string n, bool nOS,
                 bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                 int s, int eL, int cV, int cH, int eT)
{
    Animal::update(g, mC, n, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT);
    friendlinessDogs = fD;
    houseTrained= hT;
    barkTendency = bTY;
}
