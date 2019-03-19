#ifndef SEEDS_H
#define SEEDS_H

#include <Models/Animal/Animal.h>
#include <Models/Client/Client.h>
#include <Models/Attribute/Attribute.h>
#include <Models/User/User.h>

#include <QVectorIterator>

class Seeds {
private:
    Seeds();

public:
    static void runAll();
};

#endif // SEEDS_H
