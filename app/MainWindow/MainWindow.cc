#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <DatabaseAdapter/DatabaseAdapter.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Unused, this line is present to test the database initialization.
    DatabaseAdapter* db = DatabaseAdapter::getInstance();

    int a = 6;
}

MainWindow::~MainWindow() {
    delete ui;
}
