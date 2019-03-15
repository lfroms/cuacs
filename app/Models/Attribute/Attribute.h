#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QString>
#include <ActiveObject/ActiveObject.h>

using namespace std;

class Attribute : public ActiveObject<Attribute> {
public:
    Attribute(QString name);
    Attribute(QString name, QString description);
    Attribute(QSqlRecord* record);

    Attribute();
    ~Attribute();

    void getName(QString& outStr);
    void getDescription(QString& outStr);

    void toCommaSeparated(QString& outStr);
    static void getTableName(QString& outStr);

private:
    QString name;
    QString description;
};

#endif // ATTRIBUTE_H
