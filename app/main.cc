#include "MainWindow/MainWindow.h"
#include <QApplication>
#include "Models/animal.h"
#include "Models/cat.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
