#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QListWidgetItem>
#include <DatabaseAdapter/DatabaseAdapter.h>
#include <MainWindow/DetailListWidgetItem.h>
#include <MainWindow/AnimalDetailsModal.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleAddAnimalSubmit();
    void onAnimalClicked(QListWidgetItem*);

private:
    Ui::MainWindow *ui;
    DatabaseAdapter* db;
    void renderListItems();
    void renderAnimalList();
    void renderClientList();
};

#endif // MAINWINDOW_H
