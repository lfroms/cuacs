#include "LoginWindow.h"
#include "ui_LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow) {
    ui->setupUi(this);

    this->setWindowTitle("cuACS Login");
    StyleUtil().updateStyle(this);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::handleLogInAction() {
    QMessageBox messageBox;
    messageBox.setWindowTitle("Login Error");
    messageBox.setText("Incorrect username or password.");

    QString enteredUsername = ui->username->text();
    QString enteredPassword = ui->password->text();

    QVector<User*>* usernameMatches = User::where("username", enteredUsername);

    if (usernameMatches->isEmpty()) {
        messageBox.exec();
        return;
    }

    QVector<User*>* passwordMatches = User::where("password", enteredPassword);

    if (passwordMatches->isEmpty()) {
        messageBox.exec();
        return;
    }

    Session::currentUser = usernameMatches->first();
    this->accept();
}
