#include "MatchCreator.h"

QVector<Match*> MatchCreator::computeOptimalMatches(QHash<Animal*, QVector<Match*>> inputHash) {
    QHashIterator<Animal*, QVector<Match*>> inputHashI(inputHash);

    QHash<Animal*, QVector<Match*>> sortedMatchesHash;

    // Sorting every animal's matches in descending order
    while(inputHashI.hasNext()) {
        inputHashI.next();
        sortedMatchesHash[inputHashI.key()] = sortAndThresholdMatches(inputHashI.value());
    }

    return computeMatches(sortedMatchesHash);
}

QVector<Match*> MatchCreator::sortAndThresholdMatches(QVector<Match*> inputMatchVector) {
    QVectorIterator<Match*> input_i(inputMatchVector);

    // Apply thresholding to reject matches
    QVector<Match*> thresholdedMatches;
    while(input_i.hasNext()) {
        Match* currentMatch = input_i.next();

        if(currentMatch->getScore() >= MATCH_SCORE_THRESHOLD){
            thresholdedMatches.append(currentMatch);
        }
    }

    sort(thresholdedMatches.begin(), thresholdedMatches.end(), [](Match* a, Match* b){
        return a->getScore() > b->getScore();
    });

    return thresholdedMatches;
}

QVector<Match*> MatchCreator::computeMatches(QHash<Animal*, QVector<Match*>> inputHash)
{
    QHash<Client*, Match*> clientsTopPick;
    QHashIterator<Animal*, QVector<Match*>> inputHashI(inputHash);

    // Getting all animals from inputHash
    QVector<Animal*> animalProposerQueue;

    while(inputHashI.hasNext()) {
        inputHashI.next();
        animalProposerQueue.append(inputHashI.key());
    }

    // Gale-Shapely's stable marriage algorithm, with the animals as the proposers, and the clients as the proposed.
    QVectorIterator<Animal*> animalProposerQueueI(animalProposerQueue);
    while(animalProposerQueueI.hasNext()) {
        Animal* currentAnimal = animalProposerQueueI.next();

        QVector<Match*> currentAnimalMatches = inputHash[currentAnimal];
        QVectorIterator<Match*> currentAnimalMatchesI(currentAnimalMatches);

        Match* currentMatch;
        while(currentAnimalMatchesI.hasNext()) {
            currentMatch = currentAnimalMatchesI.next();

            // If this animal hash a higher score with this client, then the client's current match, this animal will be assigned to that client, and the animal that was originally matched
            // will be re-enqued to the animalProposerQueue
            Match* clientPreviousTopMatch = clientsTopPick[currentMatch->getClient()];
            if (clientPreviousTopMatch == 0)
            {
                clientsTopPick[currentMatch->getClient()] = currentMatch;
            } else if(clientPreviousTopMatch->getScore() < currentMatch->getScore()){
                clientsTopPick[currentMatch->getClient()] = currentMatch;
                animalProposerQueue.append(clientPreviousTopMatch->getAnimal());
                break;
            }
        }

        // Delete all matches that the animal has already attempted
        if(currentMatch)
        {
            inputHash[currentAnimal].remove(0, currentAnimalMatches.indexOf(currentMatch) + 1);
        }
    }

    QHashIterator<Client*, Match*> clientsTopPickI(clientsTopPick);
    QVector<Match*> optimalMatches;

    while(clientsTopPickI.hasNext()){
        clientsTopPickI.next();
        Match* currentMatch = clientsTopPickI.value();

        if(currentMatch->getScore() > 0) {
            optimalMatches.append(currentMatch);
        }
    }

    return optimalMatches;
}
