#include "CompatibilityScorer.h"

QHash<Animal*, QVector<Match*>> CompatibilityScorer::calculate_scores() {
    QVector<Animal*>* animalVector = Animal::where("hypothetical", false);
    QVectorIterator<Animal*> animalI(*animalVector);

    QVector<Client*>* clientVector = Client::all();
    QVectorIterator<Client*> clientI(*clientVector);
    QHash<Animal*, QVector<Match*>> result;

    while(animalI.hasNext()) {
        clientI.toFront();
        Animal* currentAnimal = animalI.next();
        QVector<Match*> matchVector;

        while(clientI.hasNext()) {
            Client* currentClient = clientI.next();
            Match* match = new Match(currentAnimal, currentClient);

            float wantScore = calculate_client_want_score(currentAnimal, currentClient, match);
            match->addRule(
                        QString("The client's matching preferences is %1% similar to the animal.")
                        .arg(double(wantScore * 100))
                        );

            float personalityScore = calculate_client_personality_score(currentAnimal, currentClient);
            match->addRule(
                        QString("The client's personality is %1% similar to the animal's personality.")
                        .arg(double(personalityScore * 100))
                        );

            float total_score = (40 * wantScore) + (50 * personalityScore);
            match->addRule(
                        QString("Since the ideal animal similarity is weighted to 40% "
                                "of the total score and the personality similarity is "
                                "weighted to 60% of the score, the resulting score is %1%.")
                        .arg(double(total_score))
                        );

            match->setScore(total_score);

            apply_client_situation_heuristics(currentAnimal, currentClient, match);
            match->addRule(
                        QString("After applying the modifications above, the final compatibility "
                                "score is %1%.")
                        .arg(double(match->getScore()))
                        );

            matchVector.append(match);
        }

        result[currentAnimal] = matchVector;
    }

    return result;
}

float CompatibilityScorer::calculate_client_want_score(Animal* animal, Client* client, Match* match) {
    if (client->idealAnimalId == -1) {
        return 0;
    }

    Animal* idealAnimal = Animal::findBy(client->idealAnimalId);

    float physicalScore = calculate_physical_compatibility(animal, idealAnimal, match);
    float nonPhysicalScore = calculate_non_physical_compatibility(animal, idealAnimal);

    return physicalScore / 2 + nonPhysicalScore / 2;
}

float CompatibilityScorer::calculate_physical_compatibility(
        Animal* animal,
        Animal* idealAnimal,
        Match* match) {
    int difference = 0;

    if (animal->species != idealAnimal->species) {
        difference += 1;
    }

    if (animal->gender != idealAnimal->gender) {
        difference += 1;
    }

    if (animal->breed != idealAnimal->breed) {
        difference += 1;
    }

    if (animal->neuteredOrSpayed != idealAnimal->neuteredOrSpayed) {
        difference += 1;
    }

    if (animal->color != idealAnimal->color) {
        difference += 1;
    }

    if (animal->requiresMedicalAttn != idealAnimal->requiresMedicalAttn) {
        match->addRule(
                    QString("Since the client specified that they would ideally not "
                            "adopt an animal that needs medical attention, approximately "
                            "%1% was deducted from the match score.")
                    .arg(double((10.f / 33) * 20)));

        difference += 10;
    }

    difference += qFabs(animal->age - idealAnimal->age);

    return 1.f - difference / 33.f;
}

float CompatibilityScorer::calculate_non_physical_compatibility(Animal* animal, Animal* idealAnimal) {
    int difference = 0;
    QHash<QString, float> animalAttributes = animal->attributes();
    QHash<QString, float> idealAnimalAttributes = idealAnimal->attributes();
    QHashIterator<QString, float> i(animalAttributes);

    while (i.hasNext()) {
        i.next();

        const float newValue = i.value() - idealAnimalAttributes[i.key()];
        difference += qFabs(double(newValue));
    }

    return 1.f - difference/108.f;
}

float CompatibilityScorer::calculate_client_personality_score(Animal* animal, Client* client) {
    int difference = 0;
    QHash<QString, float> animalAttributes = animal->attributes();
    QHash<QString, float> clientAttributes = client->attributes();
    QHashIterator<QString, float> i(clientAttributes);

    // animal attribute preprocessing
    float aggression = (
                animalAttributes["bite_tendency"]
            + animalAttributes["scratch_tendency"]
            + animalAttributes["assert_dominance_tendency"]
            ) / 3;

    animalAttributes["aggressiveness"] = aggression;

    float social = (
                animalAttributes["friendliness_children"]
            + animalAttributes["friendliness_animals"]
            + animalAttributes["friendliness_adults"]
            ) / 3;

    animalAttributes["socialness"] = social;

    while (i.hasNext()) {
        i.next();

        const float newValue = i.value() - animalAttributes[i.key()];
        difference += qFabs(double(newValue));
    }

    return 1.f - difference/108.f;
}

void CompatibilityScorer::apply_client_situation_heuristics(Animal* animal, Client* client, Match* match) {
    QHash<QString, float> animalAttributes = animal->attributes();

    // Heuristic 1
    if (client->ownedAnimal
            && animalAttributes["assert_dominance_tendency"] > 7
            && animalAttributes["energy"] > 6) {

        match->addRule("Since the client has never owned an animal before and the "
                       "shelter animals tendency to assert dominance is above 7 "
                       "and its energy level is above 6, the compatibility score of "
                       "the match was decreased by 5%.");
        match->setScore(match->getScore() - 5);
    }

    // Heuristic 2
    if (client->homeSqFoot < 300
            && animal->age < 12
            && animal->species == "Dog"
            ) {

        match->addRule("Since the client lives in a home that is less than 300 square feet, "
                       "the shelter animal is of species dog, and the animal’s age is "
                       "lower than 12, the compatibility score of the match was decreased by 5%.");
        match->setScore(match->getScore() - 5);
    }

    // Heuristic 3
    if (client->ownsAnimal
            && animalAttributes["friendliness_animals"] < 5) {
        match->addRule("Since the client currently owns an animal at home and "
                       "the shelter animal’s friendliness towards other animals "
                       "is lower than 5, the compatibility score of the match was decrease by 5%.");
        match->setScore(match->getScore() - 5);
    }

    // Heuristic 4
    if (client->salary > 70000) {
        match->addRule("Since the client’s annual salary is above $70k, "
                       "the compatibility score was increased by 5%.");
        match->setScore(match->getScore() + 5);
    }

    // Heuristic 5
    if (client->hrsDedication <= 1
            && animal->species != "Dog") {

        match->addRule("Since the client’s estimated number of hours per day "
                       "dedicated to the animal is lower than 1 hour and the "
                       "animal is not of species dog, the compatibility score "
                       "of the match was increased by 5%.");
        match->setScore(match->getScore() + 5);
    }

    // Heuristic 6
    if (client->hasChildren
            && animalAttributes["friendliness_children"] > 7
            && animalAttributes["affection"] > 6
            && animalAttributes["energy"] > 6
            && (animalAttributes["scratch_tendency"] > 8 || animalAttributes["bite_tendency"] > 8)) {

        match->addRule("Since the client has children, the animal has a friendliness with children "
                       "greater than 7, has affection greater than 6, and "
                       "energy level greater than 6, with a scratch tendency "
                       "greater than 8 or bite tendency greater than 8, "
                       "the compatibility score of the match was decreased by 5%.");
        match->setScore(match->getScore() - 5);
    }

    // Heuristic 7
    if (client->hasChildren
            && (animalAttributes["noise"] < 5 || animalAttributes["independence"] > 6)) {

        match->addRule("Since the client has children and the animal has a "
                       "noise level below 5 or has independence above 6, "
                       "the compatibility score of the match was increased "
                       "by 5%.");
        match->setScore(match->getScore() + 5);
    }
}
