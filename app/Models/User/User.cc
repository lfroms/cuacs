#include "User.h"

User::User(
        QString name,
        QString password,
        QString type,
        bool isAdmin
        ) {
    this->name = name;
    this->username = generateUsername(name);
    this->password = password;
    this->type = type;
    this->isAdmin = isAdmin;
}

User::~User() {}

// Define how the SQL record should be decomposed into this object.
User::User(QSqlRecord* record) :
    User(record->field("name").value().toString(),
         record->field("password").value().toString(),
         record->field("type").value().toString(),
         record->field("admin").value().toBool()) {
    this->id = record->field("id").value().toInt();
}

const QString User::toCommaSeparated() {
    QString formatted = QString("'%1', '%2', '%3', '%4', %5")
            .arg(name)
            .arg(username)
            .arg(password)
            .arg(type)
            .arg(isAdmin);

    return formatted;
}

const QString User::className() {
    return "user";
}

const QString User::generateUsername(QString fullName) {
    return fullName.toLower().simplified().replace(" ", "");
}

void User::setName(QString newName) {
    this->username = generateUsername(newName);
    this->name = newName;
}

const QString User::getName() {
    return this->name;
}

const QString User::getPassword() {
    return password;
}

bool User::getIsAdmin()  {
    return isAdmin;
}

const QString User::getUsername() {
    return username;
}
