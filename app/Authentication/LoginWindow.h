#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <Repository/User/User.h>
#include <Repository/CurrentUser/Session.h>

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
