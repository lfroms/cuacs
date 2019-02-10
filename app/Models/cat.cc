#include "cat.h"

Cat::Cat(bool iO, int lT, int fLC, int i, string g, string mC, string n, string b, bool nOS,
         bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
         int s, int eL, int cV, int cH, int eT)
    : Animal(i, g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT)

{
    indoorOutdoor = iO;
    litterTrained = lT;
    friendlinessCats = fLC;
}

Cat::~Cat(){}

string Cat::toCommaSeperated()
{
    stringstream s;
    s << Animal::toCommaSeperated() << "," << indoorOutdoor << "," << litterTrained << "," << friendlinessCats;

    return s.str();
}

void Cat::update(bool iO, int lT, int fLC, int i, string g, string mC, string n, string b, bool nOS,
                 bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                 int s, int eL, int cV, int cH, int eT)
{
    Animal::update(i, g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT);
    indoorOutdoor = iO;
    litterTrained = lT;
    friendlinessCats = fLC;
}
