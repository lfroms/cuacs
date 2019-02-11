#ifndef DOG_H
#define DOG_H
#include "Models/animal.h"

class Dog : public Animal
{
public:
    Dog(int fD, 
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
	int eT);

    ~Dog();

    void toCommaSeperated(string& outStr);

    void update(int fD, 
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
                int eT);

    string getSpecies();

private:
    int friendlinessDogs;
    int houseTrained;
    int barkTendency;
};

#endif // DOG_H
