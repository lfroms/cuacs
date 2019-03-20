#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QListWidgetItem>
#include <QVectorIterator>
#include <QShowEvent>
#include <QTimer>
#include <Models/CurrentUser/CurrentUser.h>
#include <LoginWindow/LoginWindow.h>
#include <MainWindow/DetailListWidgetItem.h>
#include <MainWindow/AnimalDetailsModal.h>
#include <MainWindow/ClientDetailsModal.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleAddAnimalAction();
    void handleAddClientAction();
    void onAnimalClicked(QListWidgetItem*);
    void onUserPermissionsChanged(const QString&);
    void onClientClicked(QListWidgetItem*);

private:
    Ui::MainWindow *ui;
    void renderListItems();
    void renderAnimalList();
    void renderClientList();

    void setReadOnlyEnabled();
    bool readOnly = false;

    void showEvent(QShowEvent *event);
};

#endif // MAINWINDOW_H
