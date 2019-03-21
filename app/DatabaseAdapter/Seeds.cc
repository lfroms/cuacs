#include "Seeds.h"
using namespace std;

Seeds::Seeds() {}

void Seeds::runAll() {
    qDebug() << "Seeding shelter animals...";
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

    Animal("Angie", "Dog", "female", "Poodle", 1, false, false, "grey", false).create();
    Animal("Angel", "Rabbit", "female", "Dwarf", 3, false, false, "brown", false).create();
    Animal("Boo", "Cat", "male", "Tabby", 1, false, false, "orange", false).create();
    Animal("Ghost", "Dog", "male", "Pug", 4, false, false, "black", false).create();
    Animal("Fluffy", "Rabbit", "female", "Holland Lop", 4, false, false, "grey", false).create();


    qDebug() << "Seeding users...";
    User("Johnny Appleseed", randPass(), Client::className()).create();
    User("Niko Kouloufakos", randPass(), Client::className()).create();
    User("William Lu", randPass(), Client::className()).create();
    User("Lulu Sheng", randPass(), Client::className()).create();
    User("Lukas Romsicki", randPass(), Client::className()).create();

    User("Lady Gaga", randPass(), Client::className()).create();
    User("Daniel Radcliffe", randPass(), Client::className()).create();
    User("Prince James", randPass(), Client::className()).create();
    User("Jake Dagger", randPass(), Client::className()).create();
    User("Luke Yang", randPass(), Client::className()).create();

    User("Jesse Mccarthy", randPass(), Client::className()).create();
    User("Wyatt Fisher", randPass(), Client::className()).create();
    User("Melanie Smith", randPass(), Client::className()).create();
    User("Jessica Jones", randPass(), Client::className()).create();
    User("Matt Gordon", randPass(), Client::className()).create();

    User("Kate Middleton", randPass(), Client::className()).create();
    User("Tina Zhang", randPass(), Client::className()).create();
    User("Jaqueline Tan", randPass(), Client::className()).create();
    User("Emily WOng", randPass(), Client::className()).create();
    User("Helena Beat", randPass(), Client::className()).create();

    User("Nathan Witherspoon", randPass(), Client::className()).create();
    User("Timothy Jersey", randPass(), Client::className()).create();
    User("Rocky Williams", randPass(), Client::className()).create();
    User("Grace Smith", randPass(), Client::className()).create();
    User("John Smith", randPass(), Client::className()).create();


    qDebug() << "Seeding staff...";
    User("Christine Laurendeau", "1234", "staff", true).create();


    qDebug() << "Seeding clients...";
    Client(1, 24, "613-928-5235", "johnny@cuacs.ca", 400, true, false, 80000, 4, true).create();
    Client(2, 19, "613-413-5276", "niko.kouloufakos@shopify.com", 80, true, true, 60000, 4, false).create();
    Client(3, 42, "613-765-9265", "william@wildfox.ca", 400, true, false, 50000, 6, false).create();
    Client(4, 34, "613-067-8564", "lulusheng@cmail.carleton.ca", 600, false, true, 60000, 5, true).create();
    Client(5, 64, "613-341-0696", "lukas@gmail.com", 1200, true, false, 50000, 4, false).create();

    Client(6, 29, "613-432-5252", "ladygaga@hotmail.com", 1500, false, true, 200000, 4, true).create();
    Client(7, 39, "613-413-5555", "radcliffeD@gmail.com", 1600, false, false, 200000, 3, false).create();
    Client(8, 54, "613-765-9482", "prince@james.ca", 2000, true, false, 90000, 5, false).create();
    Client(9, 19, "613-493-8564", "theDagger@cmail.carleton.ca", 500, false, true, 80000, 2, true).create();
    Client(10, 22, "613-341-3248", "yukelang@gmail.com", 400, true, false, 75000, 1, false).create();

    Client(11, 24, "613-392-5235", "mccarthy@shopify.ca", 1000, true, true, 150000, 6, true).create();
    Client(12, 45, "613-413-3928", "wyattTheFish@shopify.com", 2000, true, true, 120000, 7, false).create();
    Client(13, 55, "613-444-9265", "melanie.smith@gmail.ca", 1600, false, false, 40000, 4, false).create();
    Client(14, 50, "613-067-0000", "jessicaJJ@cmail.carleton.ca", 1200, true, true, 60000, 3, true).create();
    Client(15, 28, "613-341-9282", "gordon.matt@gmail.com", 2000, false, true, 320000, 4, false).create();

    Client(16, 31, "613-324-9485", "middleton@cuacs.ca", 1300, true, true, 500000, 2, true).create();
    Client(17, 35, "613-098-5845", "Tina.zhang123@shopify.com", 800, true, true, 300000, 5, false).create();
    Client(18, 41, "613-492-0003", "jaqueline432@wildfox.ca", 900, false, false, 200000, 6, false).create();
    Client(19, 47, "613-067-3847", "emily.wong983@cmail.carleton.ca", 700, true, false, 100000, 7, true).create();
    Client(20, 44, "613-444-0696", "helena@hotmail.com", 1000, true, false, 70000, 4, false).create();

    Client(21, 51, "613-928-4491", "nathaniel@cuacs.ca", 4000, false, false, 70000, 4, true).create();
    Client(22, 58, "613-413-1912", "timothyGoesToSchool@shopify.com", 3000, true, false, 40000, 2, false).create();
    Client(23, 23, "613-111-9265", "rocky123@wildfox.ca", 3300, false, false, 80000, 1, false).create();
    Client(24, 22, "613-067-9583", "grace.smith@cmail.carleton.ca", 2100, true, true, 120000, 2, true).create();
    Client(25, 22, "613-341-2332", "boringJohnSmith@gmail.com", 1450, true, false, 80000, 1, false).create();


    qDebug() << "Seeding ideal animals..";

    QVector<Client*>* clientsVector = Client::all();
    QVectorIterator<Client*> clients(*clientsVector);

    while (clients.hasNext()) {
        Client* currentClient = clients.next();
        QString breeds[8] = {"German Shepherd", "Chihuahua", "Poodle", "Golden Retriever",
                             "Labrador", "Pug", "Boxer", "Greyhound"};
        QString genders[2] = {"female", "male"};
        int ages[5] = {1,3,5,10,15};
        QString colors[5] = {"black", "white", "yellow", "brown", "grey"};

        Animal("", "Dog", genders[rand() % 2],
                breeds[rand() % 8],
                ages[rand() % 5], false, false,
                colors[rand() % 5], true).create();

        currentClient->idealAnimalId = Animal::last()->getId();
        currentClient->save();
    }

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
    Attribute("energy", "Energy/Fitness Level").create();
    Attribute("anxiety", "Anxiety Level").create();
    Attribute("curiosity", "Curiosity Level").create();


    QString clientType = Client::className();

    Attribute("assertiveness", "Level of Assertiveness", clientType).create();
    Attribute("socialness", "Level of Socialness", clientType).create();


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

    clients.toFront();

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


const QString Seeds::randPass() {
    return QString::number(rand() % 200 + 100);
}
