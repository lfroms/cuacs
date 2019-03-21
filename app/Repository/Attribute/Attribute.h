#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QString>
#include <Repository/ActiveObject/ActiveObject.h>

using namespace std;

class Attribute : public ActiveObject<Attribute> {
public:
    Attribute(QString name);
    Attribute(QString name, QString description, QString type = "");
    Attribute(QSqlRecord* record);

    ~Attribute();

    const QString getName();
    const QString getDescription();

    const QString toCommaSeparated();
    static const QString className();

private:
    QString name;
    QString description;
    QString type;
};

#endif // ATTRIBUTE_H
