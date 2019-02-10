#ifndef RABBIT_H
#define RABBIT_H
#include "Models/animal.h"

class Rabbit : public Animal
{
public:
    Rabbit(int nAL, string g, string mC, string n, bool nOS,
        bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
        int s, int eL, int cV, int cH, int eT);
    ~Rabbit();
    void update(int nAL, string g, string mC, string n, bool nOS,
                bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                int s, int eL, int cV, int cH, int eT);

    int nightActivityLevel;
};

#endif // RABBIT_H
