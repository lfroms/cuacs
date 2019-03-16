#include "MainWindow/MainWindow.h"
#include <DatabaseAdapter/DatabaseAdapter.h>

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Initialize database
    DatabaseAdapter::init();

    MainWindow w;

    w.show();
    return a.exec();
}
