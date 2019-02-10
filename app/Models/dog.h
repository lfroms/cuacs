#ifndef DOG_H
#define DOG_H
#include "Models/animal.h"

class Dog : public Animal
{
public:
    Dog(int fD, int hT, int bTY, string g, string mC, string n, bool nOS,
        bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
        int s, int eL, int cV, int cH, int eT);
    ~Dog();
    void update(int fD, int hT, int bTY, string g, string mC, string n, bool nOS,
                bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                int s, int eL, int cV, int cH, int eT);

    int friendlinessDogs;
    int houseTrained;
    int barkTendency;
};

#endif // DOG_H
