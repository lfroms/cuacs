#ifndef SEEDS_H
#define SEEDS_H

#include <Repository/Animal/Animal.h>
#include <Repository/Client/Client.h>
#include <Repository/Attribute/Attribute.h>
#include <Repository/User/User.h>

#include <QVectorIterator>

class Seeds {
private:
    Seeds();
    static const QString randPass();

public:
    static void runAll();
};

#endif // SEEDS_H
