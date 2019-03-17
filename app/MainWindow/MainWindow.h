#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QListWidgetItem>
#include <QVectorIterator>
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
    void handleAddClientSubmit();
    void onAnimalClicked(QListWidgetItem*);
    void onUserPermissionsChanged(const QString&);
    void onClientClicked(QListWidgetItem*);

private:
    Ui::MainWindow *ui;
    void renderListItems();
    void renderAnimalList();
    void renderClientList();
};

#endif // MAINWINDOW_H
