#ifndef CAT_H
#define CAT_H
#include "Models/animal.h"
#include <iostream>
#include <string>
using namespace std;

class Cat : public Animal
{
public:
    Cat(bool iO,
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
        int eT);

    ~Cat();

    void toCommaSeperated(string& outStr);

    string getSpecies();

    void update(bool iO, 
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
                int eT);


    string getTableName() {
        return "cats";
    }

private:
    bool indoorOutdoor;
    int litterTrained;
    int friendlinessCats;
};

#endif // CAT_H
