#ifndef USER_H
#define USER_H

#include <QString>
#include <Repository/ActiveObject/ActiveObject.h>

class User : public ActiveObject<User> {
public:
    User(QString name, QString password, QString type, bool isAdmin = false);
    User(QSqlRecord* record);
    ~User();

    const QString toCommaSeparated();
    static const QString className();

    void setName(QString newName);
    const QString getName();

    const QString getPassword();
    bool getIsAdmin();
    const QString getUsername();

private:
    QString username;
    QString password;
    QString type;
    QString name;
    bool isAdmin;

    const QString generateUsername(QString fullName);
};

#endif // USER_H
