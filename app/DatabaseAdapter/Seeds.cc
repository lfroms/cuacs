#include "Seeds.h"
using namespace std;

Seeds::Seeds() {
    animals[0] = new Animal("Timothy", "Dog", "male", "Yorkshire Terrier", 1, false, false, "brown", false);
    animals[1] = new Animal("Holly", "Dog", "female", "Labrador Retriever", 10, false, false, "yellow", false);
    animals[2] = new Animal("Whiskers", "Cat", "male", "Tabby", 6, false, false, "orange", false);
    animals[3] = new Animal("Salem", "Cat", "female", "American Shorthair", 11, false, false, "black", false);
    animals[4] = new Animal("Bugs", "Rabbit", "male", "Britannia Petite", 3, false, false, "grey", false);

    animals[5] = new Animal("Charles", "Dog", "male", "Husky", 8, false, false, "grey", false);
    animals[6] = new Animal("Jamie", "Dog", "female", "German Shepherd", 3, false, false, "yellow", false);
    animals[7] = new Animal("Patrick", "Cat", "male", "Russian Blue", 2, false, false, "grey", false);
    animals[8] = new Animal("Nibbles", "Cat", "female", "Persian", 6, false, false, "white", false);
    animals[9] = new Animal("Pickles", "Rabbit", "male", "Dutch", 2, false, false, "grey", false);

    animals[10] = new Animal("Spot", "Dog", "male", "Dalmation", 1, false, false, "black and white", false);
    animals[11] = new Animal("Ivy", "Dog", "female", "Pug", 2, false, false, "black", false);
    animals[12] = new Animal("Bill", "Cat", "male", "Siamese", 4, false, false, "beige", false);
    animals[13] = new Animal("Caroline", "Cat", "female", "Scottish Fold", 8, false, false, "brown", false);
    animals[14] = new Animal("BoJack", "Rabbit", "male", "Dwarf Hotot", 16, false, false, "brown", false);

    animals[15] = new Animal("Harold", "Dog", "male", "Chihuahua", 2, false, false, "white", false);
    animals[16] = new Animal("Nadeen", "Dog", "female", "Shih Tzu", 4, false, false, "brown and white", false);
    animals[17] = new Animal("Dirk", "Cat", "male", "British Shorthair", 5, false, false, "yellow", false);
    animals[18] = new Animal("Alexandra", "Cat", "female", "Sphynx", 7, false, false, "pink", false);
    animals[19] = new Animal("Sunny", "Rabbit", "male", "Himalayan", 9, false, false, "white", false);

    animals[20] = new Animal("Pearl", "Dog", "male", "Greyhound", 1, false, false, "grey", false);
    animals[21] = new Animal("Carol", "Dog", "female", "Cocker Spaniel", 3, false, false, "yellow", false);
    animals[22] = new Animal("Floyd", "Cat", "male", "Tabby", 1, false, false, "orange", false);
    animals[23] = new Animal("Hayley", "Cat", "female", "American Shorthair", 4, false, false, "white", false);
    animals[24] = new Animal("Reese", "Rabbit", "male", "Holland Lop", 4, false, false, "grey", false);

    clients[0] = new Client("Johnny Appleseed", 24, "613-928-5235", "johnny@cuacs.ca");
    clients[1] = new Client("Niko Kouloufakos", 19, "613-413-5276", "niko.kouloufakos@shopify.com");
    clients[2] = new Client("William Lu", 42, "613-765-9265", "william@wildfox.ca");
    clients[3] = new Client("Lulu Sheng", 34, "613-067-8564", "lulusheng@cmail.carleton.ca");
    clients[4] = new Client("Lukas Romsicki", 64, "613-341-0696", "lukas@gmail.com");

    attributes[0] = new Attribute("bite_tendency");
    attributes[1] = new Attribute("scratch_tendency");
    attributes[2] = new Attribute("asssert_dominance_tendency");
    attributes[3] = new Attribute("friendliness_humans");

    attributes[4] = new Attribute("friendliness_children");
    attributes[5] = new Attribute("friendliness_animals");
    attributes[6] = new Attribute("noise_level");
    attributes[7] = new Attribute("independence_level");

    attributes[8] = new Attribute("affection_level");
    attributes[9] = new Attribute("energy_level");
    attributes[10] = new Attribute("anxiety_level");
    attributes[11] = new Attribute("curiosity_level");
}

Animal** Seeds::getAnimals() {
    return animals;
}

Client** Seeds::getClients() {
    return clients;
}

Attribute** Seeds::getAttributes() {
    return attributes;
}
