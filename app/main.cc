#include "MainWindow/MainWindow.h"
#include "Models/animal.h"
#include "Models/rabbit.h"
#include "DatabaseAdapter/DatabaseAdapter.h"
#include "DatabaseAdapter/AnimalData.h"
#include <stdio.h>
#include <iomanip>

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
