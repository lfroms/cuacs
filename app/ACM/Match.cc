#include "match.h"

Match::Match(Animal* _animal, Client* _client, int _score, QVector<QString> _rules) :
    animal(_animal), client(_client), score(_score), rules(_rules)
{

}

void Match::setScore(int score) {
    this->score = score;
}

void Match::addRule(QString rule) {
    this->rules.append(rule);
}
