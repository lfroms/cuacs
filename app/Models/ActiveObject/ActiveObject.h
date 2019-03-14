#ifndef ACTIVEOBJECT_H
#define ACTIVEOBJECT_H

#include <QString>

class ActiveObject {
public:
    bool create();
    bool save();
    bool destroy();

protected:
    ActiveObject();
    ActiveObject(int id);
    virtual ~ActiveObject() = 0;

    virtual void toCommaSeparated(QString& outStr) = 0;
    virtual void getTableName(QString& outStr) = 0;

private:
    int id;
};

#endif // ACTIVEOBJECT_H
