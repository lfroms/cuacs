#include "rabbit.h"

Rabbit::Rabbit(int nAL, int i, string g, string mC, string n, string b, bool nOS,
         bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
         int s, int eL, int cV, int cH, int eT)
    : Animal(i, g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT)

{
    nightActivityLevel = nAL;
}

Rabbit::~Rabbit(){}

string Rabbit::toCommaSeperated()
{
    stringstream s;
    s << Animal::toCommaSeperated() << "," << nightActivityLevel;

    return s.str();
}

void Rabbit::update(int nAL, int i, string g, string mC, string n, string b, bool nOS,
                 bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                 int s, int eL, int cV, int cH, int eT)
{
    Animal::update(i, g, mC, n, b, nOS, h, a, bT, sT, fA, fC, nL, aC, lBS, s, eL, cV, cH, eT);
    nightActivityLevel = nAL;
}
