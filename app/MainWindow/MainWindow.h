#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <DatabaseAdapter/DatabaseAdapter.h>
#include <MainWindow/animalwidgetitem.h>

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

private:
    Ui::MainWindow *ui;
    DatabaseAdapter* db;
    void renderListItems();
};

#endif // MAINWINDOW_H
