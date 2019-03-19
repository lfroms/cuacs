#ifndef USER_H
#define USER_H

#include <QString>
#include <ActiveObject/ActiveObject.h>

class User : public ActiveObject<User> {
public:
    User(QString username, QString password);
    User(QSqlRecord* record);
    ~User();

    const QString toCommaSeparated();
    static const QString className();

protected:
    QString getUsername();

private:
    QString username;
    QString password;
};

#endif // USER_H
