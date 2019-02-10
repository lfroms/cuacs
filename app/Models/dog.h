#ifndef DOG_H
#define DOG_H
#include "Models/animal.h"

class Dog : public Animal
{
public:
    Dog(int fD, int hT, int bTY, int i, string g, string mC, string n, string b, bool nOS,
        bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
        int s, int eL, int cV, int cH, int eT);

    ~Dog();

    string toCommaSeperated();

    void update(int fD, int hT, int bTY, int i, string g, string mC, string n, string b, bool nOS,
                bool h, int a, int bT, int sT, int fA, int fC, int nL, int aC, int lBS,
                int s, int eL, int cV, int cH, int eT);

    int getFriendlinessDogs(){
        return friendlinessDogs;
    }

    int getHouseTrained(){
        return houseTrained;
    }

    int getBarkTendency(){
        return barkTendency;
    }

private:
    int friendlinessDogs;
    int houseTrained;
    int barkTendency;
};

#endif // DOG_H
