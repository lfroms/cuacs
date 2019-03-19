#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <ActiveObject/AttributedObject.h>

using namespace std;

class Client : public AttributedObject<Client> {
public:
    Client(
            QString name,
            int age,
            QString phoneNumber,
            QString email
            );

    Client(
            QString name,
            int age,
            QString phoneNumber,
            QString email,
            int idealAnimalId
            );

    Client(QSqlRecord* record);
    Client();
    ~Client();

    const QString getName();
    int getAge();
    const QString getPhoneNumber();
    const QString getEmail();

    const QString toCommaSeparated();
    static const QString className();

private:
    QString name;
    int age;
    QString phoneNumber;
    QString email;

    // Set to -1 so that we can insert NULL into the database.
    // See source file.
    int idealAnimalId = -1;
};

Q_DECLARE_METATYPE(Client*)
#endif // CLIENT_H
