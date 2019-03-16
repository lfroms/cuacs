#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <ActiveObject/ActiveObject.h>

using namespace std;

class Client : public ActiveObject<Client> {
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
    ~Client();

    void getName(QString& outStr);
    void getAge(int& outInt);
    void getPhoneNumber(QString& outStr);
    void getEmail(QString& outStr);

    void toCommaSeparated(QString& outStr);
    static void getTableName(QString& outStr);

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
