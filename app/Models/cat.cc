#include "cat.h"

Cat::Cat(bool iO, 
         int lT,
         int fLC,
         string g,
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
    : Animal(g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT)

{
    indoorOutdoor = iO;
    litterTrained = lT;
    friendlinessCats = fLC;
}

Cat::~Cat(){}

void Cat::toCommaSeperated(string& outStr){
    stringstream s;
    string animal;
    Animal::toCommaSeperated(animal);
    s << animal << ","
      << "'" << indoorOutdoor << "', "
      << "'" << litterTrained << "', "
      << "'" << friendlinessCats << "'";

    outStr = s.str();
}

string Cat::getSpecies() {
    return "Cat"
}

void Cat::update(bool iO, 
                 int lT,
                 int fLC,
                 string g,
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
    Animal::update(g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT);
    indoorOutdoor = iO;
    litterTrained = lT;
    friendlinessCats = fLC;
}
