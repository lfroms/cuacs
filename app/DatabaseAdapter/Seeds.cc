#include "Seeds.h"
using namespace std;

Seeds::Seeds() {
    animals[0] = new Dog("male", "brown", "Yorkshire Terrier", 1, false, false, "Timothy", false, 8, 9, 8, 9, 2, 10, 5, 9, 1, 5, 5, 5);
    animals[1] = new Dog("female", "yellow", "Labrador Retriever", 10, false, false, "Holly", false, 5, 9, 1, 5, 5, 5, 8, 9, 8, 9, 2, 10);
    animals[2] = new Cat("male", "orange", "Tabby", 6, false, false, "Whiskers", false, 2, 5, 7, 10, 2, 5, 4, 9, 7, 8, 6, 10);
    animals[3] = new Cat("female", "black", "American Shorthair", 11, false, false, "Salem", false, 4, 9, 7, 8, 6, 10, 2, 5, 7, 10, 2, 5);
    animals[4] = new Rabbit("male", "grey", "Britannia Petite", 3, false, false, "Bugs", false, 9, 2, 10, 10, 5, 1, 6, 5, 2, 9, 1, 0);
    
    animals[5] = new Dog("male", "grey", "Husky", 8, false, false, "Charles", false, 2, 2, 6, 5, 2, 9, 7, 1, 9, 10, 7, 1);
    animals[6] = new Dog("female", "yellow", "German Shepherd", 3, false, false, "Jamie", false, 7, 1, 9, 10, 7, 4, 2, 6, 5, 2, 9, 7);
    animals[7] = new Cat("male", "grey", "Russian Blue", 2, false, false, "Patrick", false, 1, 4, 8, 7, 3, 2, 1, 10, 6, 3, 3, 2);
    animals[8] = new Cat("female", "white", "Persian", 6, false, false, "Nibbles", false, 1, 10, 6, 3, 3, 2, 1, 4, 8, 7, 3, 2);
    animals[9] = new Rabbit("female", "grey", "Dutch", 2, false, false, "Pickles", false, 1, 5, 7, 9, 3, 6, 3, 8, 10, 7, 7, 10);
    
    animals[10] = new Dog("male", "black and white", "Dalmation", 1, false, false, "Spot", false, 3, 8, 10, 7, 7, 10, 5, 2, 1, 9, 2, 5);
    animals[11] = new Dog("female", "black", "Pug", 2, false, false, "Ivy", false, 5, 2, 1, 9, 2, 5, 7, 10, 5, 2, 1, 9);
    animals[12] = new Cat("male", "beige", "Siamese", 4, false, false, "Bill", false, 5, 10, 10, 6, 7, 10, 3, 1, 7, 5, 4, 5);
    animals[13] = new Cat("female", "brown", "Scottish Fold", 8, false, false, "Caroline", false, 10, 3, 1, 7, 5, 4, 5, 10, 10, 6, 7, 10);
    animals[14] = new Rabbit("male", "brown", "Dwarf Hotot", 16, false, false, "BoJack", false, 3, 1, 5, 1, 2, 1, 7, 5, 4, 5, 10, 10);

    animals[15] = new Dog("male", "white", "Chihuahua", 2, false, false, "Harold", false, 6, 3, 7, 10, 9, 2, 2, 8, 3, 10, 8, 3);
    animals[16] = new Dog("female", "brown and white", "Shih Tzu", 4, false, false, "Nadeen", false, 2, 8, 3, 10, 8, 3, 6, 3, 7, 10, 9, 2);
    animals[17] = new Cat("male", "yellow", "British Shorthair", 5, false, false, "Dirk", false, 3, 2, 8, 5, 8, 8, 1, 3, 9, 3, 2, 4);
    animals[18] = new Cat("female", "pink", "Sphynx", 7, false, false, "Alexandra", false, 1, 3, 9, 3, 2, 4, 3, 2, 8, 5, 8, 8);
    animals[19] = new Rabbit("male", "white", "Himalayan", 9, false, false, "Sunny", false, 10, 7, 5, 1, 10, 9, 3, 2, 4, 3, 2, 8);

    animals[20] = new Dog("male", "grey", "Greyhound", 1, false, false, "Pearl", false, 2, 5, 8, 7, 5, 9, 5, 3, 4, 9, 5, 8);
    animals[21] = new Dog("female", "yellow", "Cocker Spaniel", 3, false, false, "Carol", false, 5, 2, 5, 3, 4, 9, 5, 8, 7, 5, 9, 1);
    animals[22] = new Cat("male", "orange", "Tabby", 1, false, false, "Floyd", false, 9, 2, 6, 3, 1, 6, 8, 5, 3, 5, 7, 4);
    animals[23] = new Cat("female", "white", "American Shorthair", 4, false, false, "Hayley", false, 8, 5, 3, 5, 7, 4, 9, 2, 6, 3, 1, 6);
    animals[24] = new Rabbit("male", "grey", "Holland Lop", 14, false, false, "Reese", false, 4, 10, 7, 4, 2, 3, 5, 3, 5, 7, 4, 9);

    clients[0] = new Client("Johnny Appleseed", 24, "613-928-5235", "johnny@cuacs.ca");
    clients[1] = new Client("Niko Kouloufakos", 19, "613-413-5276", "niko.kouloufakos@shopify.com");
    clients[2] = new Client("William Lu", 42, "613-765-9265", "william@wildfox.ca");
    clients[3] = new Client("Lulu Sheng", 34, "613-067-8564", "lulusheng@cmail.carleton.ca");
    clients[4] = new Client("Lukas Romsicki", 64, "613-341-0696", "lukas@gmail.com");
}

Animal** Seeds::getAnimals() {
    return animals;
}

Client** Seeds::getClients() {
    return clients;
}
