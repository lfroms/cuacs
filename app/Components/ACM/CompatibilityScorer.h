#ifndef COMPATIBILITYSCORER_H
#define COMPATIBILITYSCORER_H

#include <QString>
#include <QHash>
#include <QVector>
#include <QtMath>
#include <ACM/Match.h>
#include <Repository/Animal/Animal.h>
#include <Repository/Client/Client.h>

using namespace std;

class CompatibilityScorer {
	public:
        static QHash<Animal*, QVector<Match*>> calculate_scores();
    private:
        static float calculate_client_want_score(Animal*, Client*);
        static float calculate_physical_compatibility(Animal*, Animal*);
        static float calculate_non_physical_compatibility(Animal*, Animal*);

        static float calculate_client_personality_score(Animal*, Client*);
        static void apply_client_situation_heuristics(Animal*, Client*, Match*);
};

#endif // COMPATIBILITYSCORER_H
