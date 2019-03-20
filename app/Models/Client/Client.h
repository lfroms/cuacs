#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <ActiveObject/AttributedObject.h>

using namespace std;

class Client : public AttributedObject<Client> {
public:
    Client(
            int userId,
            int age,
            QString phoneNumber,
            QString email,
            int homeSqFoot,
            bool ownedAnimal,
            bool ownsAnimal,
            int salary,
            int hrsDedication,
            bool hasChildren,
            int idealAnimalId = -1
            );

    Client(QSqlRecord* record);
    Client();
    ~Client();

    const QString toCommaSeparated();
    static const QString className();

    int age;
    QString phoneNumber;
    QString email;
    int homeSqFoot;
    bool ownedAnimal;
    bool ownsAnimal;
    int salary;
    int hrsDedication;
    bool hasChildren;

    // Set to -1 so that we can insert NULL into the database.
    // See source file.
    int idealAnimalId = -1;

    int userId = -1;
};

Q_DECLARE_METATYPE(Client*)
#endif // CLIENT_H
