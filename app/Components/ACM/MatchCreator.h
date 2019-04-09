#ifndef MATCHCREATOR_H
#define MATCHCREATOR_H
#include <Components/ACM/Match.h>
#include "QHash"
#include "QHashIterator"
#include "QVector"
#include "QVectorIterator"
#include "Repository/Animal/Animal.h"
#include "Repository/Client/Client.h"
#include "algorithm"
using namespace std;

#define MATCH_SCORE_THRESHOLD 70

class MatchCreator {
public:
    static QVector<Match*> computeOptimalMatches(QHash<Animal*, QVector<Match*>>);

private:
    static QVector<Match*> sortAndThresholdMatches(QVector<Match*>);
    static QVector<Match*> computeMatches(QHash<Animal*, QVector<Match*>>);
};

#endif // MATCHCREATOR_H
