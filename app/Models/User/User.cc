#include "User.h"

User::User(
        QString username,
        QString password
        ) {
    this->username = username;
    this->password = password;
}

User::~User() {}

// Define how the SQL record should be decomposed into this object.
User::User(QSqlRecord* record) :
    User(record->field("username").value().toString(),
         record->field("password").value().toString()) {}

const QString User::toCommaSeparated() {
    QString formatted = QString("'%1', '%2'")
            .arg(username)
            .arg(password);

    return formatted;
}

const QString User::className() {
    return "user";
}
