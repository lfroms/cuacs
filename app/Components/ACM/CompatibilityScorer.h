#ifndef COMPATIBILITYSCORER_H
#define COMPATIBILITYSCORER_H

#include <QString>
#include <QHash>
#include <QVector>
#include <QtMath>
#include <Components/ACM/Match.h>
#include <Repository/Animal/Animal.h>
#include <Repository/Client/Client.h>

using namespace std;

class CompatibilityScorer {
public:
    static QHash<Animal*, QVector<Match*>> calculate_scores();

private:
    static float calculateClientWantScore(Animal*, Client*, Match*);
    static float calculatePhysicalCompatibility(Animal*, Animal*, Match*);
    static float calculateNonPhysicalCompatibility(Animal*, Animal*);

    static float calculateClientPersonalityScore(Animal*, Client*);
    static void applyClientSituationHeuristics(Animal*, Client*, Match*);
};

#endif // COMPATIBILITYSCORER_H
