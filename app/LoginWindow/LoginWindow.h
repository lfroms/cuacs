#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <Models/User/User.h>
#include <Models/CurrentUser/CurrentUser.h>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog {
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void handleLogInAction();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H