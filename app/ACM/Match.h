#ifndef MATCH_H
#define MATCH_H

#include <Repository/Animal/Animal.h>
#include <Repository/Client/Client.h>
#include <QVector>
#include <QString>

class Match
{
public:
    Match(Animal*, Client*, int = 0, QVector<QString> = QVector<QString>());
    void setScore(int);
    void addRule(QString);
private:
    Animal* animal;
    Client* client;
    float score;
    QVector<QString> rules;
};

#endif // MATCH_H
