#include "dog.h"
#include <QDebug>
Dog::Dog(int fD, 
         int hT,
         int bTY,
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
    friendlinessDogs = fD;
    houseTrained = hT;
    barkTendency = bTY;
}

Dog::~Dog(){}

void Dog::toCommaSeperated(string& outStr){
    stringstream s;
    string animal;
    Animal::toCommaSeperated(animal);
    qDebug() << "dog being added";
    s << animal << ", "
      << "'" << friendlinessDogs << "', "
      << "'" << houseTrained << "', "
      << "'" << barkTendency << "'";
    outStr = s.str();
}

string Dog::getSpecies() {
    return "Dog"
}

void Dog::update(int fD, 
		 int hT, 
		 int bTY, 
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
    friendlinessDogs = fD;
    houseTrained= hT;
    barkTendency = bTY;
}
