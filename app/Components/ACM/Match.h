#ifndef MATCH_H
#define MATCH_H

#include <Repository/Animal/Animal.h>
#include <Repository/Client/Client.h>
#include <QVector>
#include <QString>

class Match
{
public:
    Match(Animal*, Client*, float = 0, QVector<QString> = QVector<QString>());
    void setScore(float);
    void addRule(QString);
    Animal* getAnimal();
    Client* getClient();
    float getScore();
    QVector<QString> getRules();

private:
    Animal* animal;
    Client* client;
    float score;
    QVector<QString> rules;
};

Q_DECLARE_METATYPE(Match*)
#endif // MATCH_H
