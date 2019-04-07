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
		static const QHash calculate_scores();
	private:
		const float calculate_client_want_score(Animal*, Client*);
		const float calculate_client_personality_score(Animal*, Client*);
		// Match() might not return a pointer...
		const float calculate_client_situation_score(Animal*, Client*, Match*);
};

#endif // COMPATIBILITYSCORER_H
