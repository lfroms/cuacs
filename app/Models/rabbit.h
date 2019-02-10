#ifndef RABBIT_H
#define RABBIT_H
#include "Models/animal.h"

class Rabbit : public Animal
{
public:
    Rabbit(int nAL, int i, string g, string mC, string n, string b, bool nOS,
        bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
        int s, int eL, int cV, int cH, int eT);

    ~Rabbit();

    string toCommaSeperated();

    void update(int nAL, int i, string g, string mC, string n, string b, bool nOS,
                bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                int s, int eL, int cV, int cH, int eT);

    int getNightActivityLevel(){
        return nightActivityLevel;
    }
private:
    int nightActivityLevel;
};

#endif // RABBIT_H
