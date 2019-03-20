#ifndef USER_H
#define USER_H

#include <QString>
#include <ActiveObject/ActiveObject.h>

class User : public ActiveObject<User> {
public:
    User(QString name, QString password, QString type);
    User(QSqlRecord* record);
    ~User();

    const QString toCommaSeparated();
    static const QString className();

    QString name;

protected:
    QString getUsername();

private:
    QString username;
    QString password;
    QString type;

    const QString generateUsername(QString fullName);
};

#endif // USER_H
