#include "MainWindow/MainWindow.h"
#include "Models/animal.h"
#include "Models/rabbit.h"
#include "DatabaseAdapter/DatabaseAdapter.h"
#include "DatabaseAdapter/AnimalData.h"
#include <stdio.h>
#include <iomanip>

#include <QApplication>

int main(int argc, char *argv[])
{
    DatabaseAdapter* db = DatabaseAdapter::getInstance();
    Animal ** animals;
    int num;
    db->getAnimals(animals, num);

    QString test;
    animals[1]->getName(test);

    qInfo() << test;
    qDebug() << "Testing";

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
