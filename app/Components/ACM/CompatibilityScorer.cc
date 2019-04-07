#include "CompatibilityScorer.h"

const QHash CompatibilityScorer::compute_scores() {
	QVector<Animal*>* animalVector = Animal::all();
	QVectorIterator<Animal*> animal_i(*animalVector);

	QVector<Client*>* clientVector = Client::all();
	QVectorIterator<Client*> client_i(*clientVector);
	QHash<Animal*, QVector<Match*>> result;

	while(animal_i.hasNext()) {
		Animal* currentAnimal = animal_i.next();
		QVector<Match*> matchVector;
		while(client_i.hasNext()) {
			Client* currentClient = client_i.next();
			Match* match = new Match(currentAnimal, currentClient);

			float want_score = calculate_client_want_score(currentAnimal, currentClient);
			float personality_score = calculate_client_personality_score(currentAnimal, currentClient);
			float total_score = 40*want_score + 50*personality_score;
			match->set_score(total_score);

            calculate_client_situation_score(currentAnimal, CurrentClient, match);
			matchVector.append(match);
		}
		result[currentAnimal] = matchVector;
	}

    return result;
}

const float CompatibilityScorer::calculate_client_want_score(Animal* animal, Client* client) {
	if (client->idealAnimalId == -1) {
		return 0;
	}

	Animal * idealAnimal = Animal::findBy(client->idealAnimalId);

	float physical_score = calculate_physical_compatibility(animal, idealAnimal);
	float non_physical_score = calculate_non_physical_compatibility(animal, idealAnimal);
	return physical_score/2 + non_physical_score/2;
}

const float CompatibilityScorer::calculate_physical_compatibility(Animal* animal, Animal* idealAnimal) {
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

	if (animal->requiresMedicalAttn != idealAnimal->requiresMedicalAttn) {
		difference += 10;
		// add the rule here?
	}

	difference += qFabs(animal->age - idealAnimal->age);

	return 1 - difference/33;
}

const float CompatibilityScorer::calculate_non_physical_compatibility(Animal* animal, Animal* idealAnimal) {
	int difference = 0;
	QHash animalAttributes = animal->attributes;
	QHash idealAnimalAttributes = idealAnimalAttributes->attributes;
	QHashIterator<QString, int> i(animalAttributes);

	while (i.hasNext()) {
		i.next();
		difference += qFabs(i.value() - idealAnimalAttributes[i.key()]);
	}
	return 1 - difference/108;
}

const float calculate_client_personality_score(Animal* animal, Client* client) {
	int difference = 0;
	QHash animalAttributes = animal->attributes;
	QHash clientAttributes = client->attributes;
	QHashIterator<QString, int> i(clientAttributes);
	
	// animal attribute preprocessing
	float aggression = (animalAttributes["bite_tendency"] +
			    animalAttributes["scratch_tendency"] +
			    animalAttributes["assert_dominance_tendency"])/3; 
	animalAttributes["aggressiveness"] = aggression;

	float social = (animalAttributes["friendliness_children"] +
			animalAttributes["friendliness_animals"] +
			animalAttributes["friendliness_adults"])/3; 
	animalAttributes["socialness"] = social;

	while (i.hasNext()) {
		i.next();
		difference += qFabs(i.value() - animalAttributes[i.key()]);
	}
	return 1 - difference/108;
}

const float calculate_client_situation_score(Animal* animal, Client* client, Match* match) {
	QHash animalAttributes = animal->attributes;
	
	// heuristic no1
	if (client->ownedAnimal && animalAttributes["assert_dominance_tendency"] > 7 &&
			animalAttributes["energy"] > 6) {
		match->addRule("Since the client has never owned an animal before and the "
				"shelter animals tendency to assert dominance is above 7 "
				"and its energy level is above 6, the compatibility score of "
				"the match was decreased by 5%.");
		match->setScore(match->getScore - 5);
	}
	// heuristic no2
	if (client->homeSqFoot < 300 && animal->age < 12 && animal->species == "Dog") {
		// stopped here
		match->addRule("Since the client lives in a home that is less than 300 square feet, "
				"the shelter animal is of species dog, and the animal’s age is "
				"lower than 12, the compatibility score of the match was decreased by 5%.");
		match->setScore(match->getScore - 5);
	}
	// heuristic no3
	if (client->ownsAnimal && animalAttributes["friendliness_animals"] < 5) {
		match->addRule("Since the client currently owns an animal at home and "
				"the shelter animal’s friendliness towards other animals "
				"is lower than 5, the compatibility score of the match was decrease by 5%.");
		match->setScore(match->getScore - 5);
	}
	// heuristic no4
	if (client->salary > 70000) {
		match->addRule("Since the client’s annual salary is above $70k, "
				"the compatibility score was increased by 5%.");
		match->setScore(match->getScore + 5);
	}
	// heuristic no5
	if (client->hrsDedication < 1 && animal->species != "Dog") {
		match->addRule("Since the client’s estimated number of hours per day "
				"dedicated to the animal is lower than 1 hour and the "
				"animal is not of species dog, the compatibility score "
				"of the match was increased by 5%.");
		match->setScore(match->getScore + 5);
	}
	// heuristic no6
	if (client->hasChildren && animalAttributes["friendliness_children"] > 7 && animalAttributes["affection"] > 6
			&& animalAttributes["energy"] > 6
            && (animalAttributes["scratch_tendency"] > 8 || animalAttributes["bite_tendency"] > 8)) {
		match->addRule("Since the client has children, the animal has a friendliness with children "
				"greater than 7, has affection greater than 6, and "
				"energy level greater than 6, with a scratch tendency "
				"greater than 8 or bite tendency greater than 8, "
				"the compatibility score of the match was decreased by 5%.");
		match->setScore(match->getScore - 5);
	}
	// heuristic no7
    if (client->has_children &&
            (animalAttributes["noise"] < 5 || animalAttributes["independence"] > 6)) {
		match->addRule("Since the client has children and the animal has a "
				"noise level below 5 or has independence above 6, "
				"the compatibility score of the match was increased "
				"by 5%.");
		match->setScore(match->getScore + 5);
	}
}

