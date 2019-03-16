#include "Components/MainWindow.h"
#include <Repository/DatabaseAdapter/DatabaseAdapter.h>
#include "Repository/Animal/Animal.h"
#include "Repository/Client/Client.h"
#include "ACM/Match.h"
#include "ACM/MatchCreator.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    // Initialize database
    DatabaseAdapter::init();

    if (argc > 1 && std::string(argv[1]) == "data-reset") {
        DatabaseAdapter::resetAll();
        return 0;
    }

    QHash<Animal*, QVector<Match*>> sampleHash;

    QVector<Animal*>* animalVector = Animal::all();
    QVector<Client*>* clientVector = Client::all();

    QVectorIterator<Animal*> animalIterator(*animalVector);

    int i = 0;

    while(animalIterator.hasNext() && i < 5) {
        QVector<Match*> matchVector;
        Animal* currentAnimal = animalIterator.next();

        QVectorIterator<Client*> clientIterator(*clientVector);

        int j = 0;
        while(clientIterator.hasNext() && j < 5) {
            Client* currentClient = clientIterator.next();
            QVector<QString> emptyVector;
            Match* newMatch = new Match(currentAnimal, currentClient, (j+1) * 20.0, emptyVector);
            matchVector.append(newMatch);
            j++;
        }

        sampleHash[currentAnimal] = matchVector;
        i++;
    }

    animalIterator.toFront();
    Animal* firstAnimal = animalIterator.next();

    MatchCreator::sortAndThresholdMatches(sampleHash[firstAnimal]);

    QApplication a(argc, argv);
    //MainWindow w;

    //w.show();

    return a.exec();
}
