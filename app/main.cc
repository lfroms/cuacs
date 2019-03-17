#include "MainWindow/MainWindow.h"
#include <DatabaseAdapter/DatabaseAdapter.h>

#include <QApplication>

int main(int argc, char *argv[]) {
    // Initialize database
    DatabaseAdapter::init();

    if (argc > 1 && std::string(argv[1]) == "data-reset") {
        DatabaseAdapter::resetAll();
        return 0;
    }

    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
