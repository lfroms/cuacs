#include "Seeds.h"
using namespace std;

Seeds::Seeds() {}

void Seeds::runAll() {
    qDebug() << "Seeding animals...";
    Animal("Timothy", "Dog", "male", "Yorkshire Terrier", 1, false, false, "brown", false).create();
    Animal("Holly", "Dog", "female", "Labrador Retriever", 10, false, false, "yellow", false).create();
    Animal("Whiskers", "Cat", "male", "Tabby", 6, false, false, "orange", false).create();
    Animal("Salem", "Cat", "female", "American Shorthair", 11, false, false, "black", false).create();
    Animal("Bugs", "Rabbit", "male", "Britannia Petite", 3, false, false, "grey", false).create();

    Animal("Charles", "Dog", "male", "Husky", 8, false, false, "grey", false).create();
    Animal("Jamie", "Dog", "female", "German Shepherd", 3, false, false, "yellow", false).create();
    Animal("Patrick", "Cat", "male", "Russian Blue", 2, false, false, "grey", false).create();
    Animal("Nibbles", "Cat", "female", "Persian", 6, false, false, "white", false).create();
    Animal("Pickles", "Rabbit", "male", "Dutch", 2, false, false, "grey", false).create();

    Animal("Spot", "Dog", "male", "Dalmation", 1, false, false, "black and white", false).create();
    Animal("Ivy", "Dog", "female", "Pug", 2, false, false, "black", false).create();
    Animal("Bill", "Cat", "male", "Siamese", 4, false, false, "beige", false).create();
    Animal("Caroline", "Cat", "female", "Scottish Fold", 8, false, false, "brown", false).create();
    Animal("BoJack", "Rabbit", "male", "Dwarf Hotot", 16, false, false, "brown", false).create();

    Animal("Harold", "Dog", "male", "Chihuahua", 2, false, false, "white", false).create();
    Animal("Nadeen", "Dog", "female", "Shih Tzu", 4, false, false, "brown and white", false).create();
    Animal("Dirk", "Cat", "male", "British Shorthair", 5, false, false, "yellow", false).create();
    Animal("Alexandra", "Cat", "female", "Sphynx", 7, false, false, "pink", false).create();
    Animal("Sunny", "Rabbit", "male", "Himalayan", 9, false, false, "white", false).create();

    Animal("Pearl", "Dog", "male", "Greyhound", 1, false, false, "grey", false).create();
    Animal("Carol", "Dog", "female", "Cocker Spaniel", 3, false, false, "yellow", false).create();
    Animal("Floyd", "Cat", "male", "Tabby", 1, false, false, "orange", false).create();
    Animal("Hayley", "Cat", "female", "American Shorthair", 4, false, false, "white", false).create();
    Animal("Reese", "Rabbit", "male", "Holland Lop", 4, false, false, "grey", false).create();

    qDebug() << "Seeding clients...";
    Client("Johnny Appleseed", 24, "613-928-5235", "johnny@cuacs.ca").create();
    Client("Niko Kouloufakos", 19, "613-413-5276", "niko.kouloufakos@shopify.com").create();
    Client("William Lu", 42, "613-765-9265", "william@wildfox.ca").create();
    Client("Lulu Sheng", 34, "613-067-8564", "lulusheng@cmail.carleton.ca").create();
    Client("Lukas Romsicki", 64, "613-341-0696", "lukas@gmail.com").create();


    qDebug() << "Seeding attributes...";

    QString animalType = Animal::className();

    Attribute("bite_tendency", "Tendency to Bite", animalType).create();
    Attribute("scratch_tendency", "Tendency to Scratch", animalType).create();
    Attribute("assert_dominance_tendency", "Tendency to Assert Dominance", animalType).create();
    Attribute("friendliness_adults", "Friendliness towards Adults", animalType).create();

    Attribute("friendliness_children", "Friendlienss towards Children", animalType).create();
    Attribute("friendliness_animals", "Friendliness towards Animals", animalType).create();
    Attribute("noisiness", "Noise Level").create();
    Attribute("independence", "Level of Independence").create();

    Attribute("affection", "Level of Affection").create();
    Attribute("energy", "Energy Level", animalType).create();
    Attribute("anxiety", "Anxiety Level").create();
    Attribute("curiosity", "Curiosity Level").create();


    QString clientType = Client::className();

    Attribute("assertiveness", "Level of Assertiveness", clientType).create();
    Attribute("socialness", "Level of Socialness", clientType).create();
    Attribute("fitness", "Fitness Level", clientType).create();


    // SEED ANIMAL ATTRIBUTES
    qDebug() << "Seeding animal attributes...";

    QVector<Animal*>* animalsVector = Animal::all();
    QVectorIterator<Animal*> animals(*animalsVector);

    QVector<Attribute*>* animalAttributesVector = Attribute::where("type", animalType, true);
    QVectorIterator<Attribute*> animalAttributes(*animalAttributesVector);

    bool animalVectorsNotEmpty = !animalsVector->isEmpty() && !animalAttributesVector->isEmpty();

    if (animalVectorsNotEmpty) {
        while (animals.hasNext()) {
            Animal* currentAnimal = animals.next();
            animalAttributes.toFront();

            while (animalAttributes.hasNext()) {
                Attribute* currentAttribute = animalAttributes.next();

                int randomValue = rand() % 11;
                currentAnimal->setAttr(currentAttribute->getName(), randomValue);
            }
        }
    }

    // SEED CLIENT ATTRIBUTES
    qDebug() << "Seeding client attributes...";

    QVector<Client*>* clientsVector = Client::all();
    QVectorIterator<Client*> clients(*clientsVector);

    QVector<Attribute*>* clientAttributesVector = Attribute::where("type", clientType, true);
    QVectorIterator<Attribute*> clientAttributes(*clientAttributesVector);

    bool clientVectorsNotEmpty = !clientsVector->isEmpty() && !clientAttributesVector->isEmpty();

    if (clientVectorsNotEmpty) {
        while (clients.hasNext()) {
            Client* currentClient = clients.next();
            clientAttributes.toFront();

            while (clientAttributes.hasNext()) {
                Attribute* currentAttribute = clientAttributes.next();

                int randomValue = rand() % 11;
                currentClient->setAttr(currentAttribute->getName(), randomValue);
            }
        }
    }
}

