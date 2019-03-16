#include "MatchCreator.h"
#include <QDebug>

void MatchCreator::computeOptimalMatches(QHash<Animal*, QVector<Match*>> inputHash) {
    QHashIterator<Animal*, QVector<Match*>> inputHash_i(inputHash);

    QHash<Animal*, QVector<Match*>> sortedMatchesHash;

    // Sorting every animal's matches in descending order
    while(inputHash_i.hasNext()) {
        inputHash_i.next();
        sortedMatchesHash[inputHash_i.key()] = sortAndThresholdMatches(inputHash_i.value());
    }
}

QVector<Match*> MatchCreator::sortAndThresholdMatches(QVector<Match*> inputMatchVector) {
    QVectorIterator<Match*> input_i(inputMatchVector);

    qDebug() << "Unsorted";
    // Apply thresholding to reject matches
    QVector<Match*> thresholdedMatches;
    while(input_i.hasNext()) {
        Match* currentMatch = input_i.next();
        qDebug() << currentMatch->getScore();

        if(currentMatch->getScore() >= MATCH_SCORE_THRESHOLD){
            thresholdedMatches.append(currentMatch);
        }
    }

    sort(thresholdedMatches.begin(), thresholdedMatches.end(), [](Match* a, Match* b){
        return a->getScore() > b->getScore();
    });

    QVectorIterator<Match*> thresholdI(thresholdedMatches);
    qDebug() << "Sorted";
    while(thresholdI.hasNext()){
        Match* match = thresholdI.next();
        qDebug() << match->getScore();
    }

    return thresholdedMatches;
}

QHash<Animal*, QVector<Match*>> MatchCreator::computeMatches(QHash<Animal*, QVector<Match*>> inputHash)
{
}
