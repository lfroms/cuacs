#include "rabbit.h"

Rabbit::Rabbit(int nAL, 
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
    nightActivityLevel = nAL;
}

Rabbit::~Rabbit(){}

void Rabbit::toCommaSeperated(string& outStr){
    stringstream s;
    string animal;
    Animal::toCommaSeperated(animal);
    s << animal << ", "
      << "'" << nightActivityLevel << "'";

    outStr = s.str();
}

void Rabbit::update(int nAL, 
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
    nightActivityLevel = nAL;
}
