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

    ~Attribute();

    const QString getName();
    const QString getDescription();

    const QString toCommaSeparated();
    static const QString getTableName();

private:
    QString name;
    QString description;
};

#endif // ATTRIBUTE_H
