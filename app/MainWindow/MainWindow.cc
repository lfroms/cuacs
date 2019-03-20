#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setStyleSheet("QTabBar::tab::disabled {width: 0; height: 0; margin: 0; padding: 0; border: none;}");

    connect(ui->animalsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onAnimalClicked(QListWidgetItem*)));
    connect(ui->clientsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onClientClicked(QListWidgetItem*)));

    connect(ui->staffOrClientSelector, SIGNAL (currentIndexChanged(const QString&)), this, SLOT(onUserPermissionsChanged(const QString&)));

    renderListItems();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onUserPermissionsChanged(const QString& permissionLevel) {
    readOnly = permissionLevel == "Client" ? true : false;
    setReadOnlyEnabled();
}

void MainWindow::setReadOnlyEnabled() {
    bool enabled = !readOnly;

    ui->actionAdd_Animal->setEnabled(enabled);
    ui->actionAdd_Client->setEnabled(enabled);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(3, enabled);
    ui->tabWidget->setTabEnabled(2, enabled);
    ui->tabWidget->setTabEnabled(1, enabled);
}

void MainWindow::onAnimalClicked(QListWidgetItem* animalWidgetItem) {
    QVariant var = animalWidgetItem->data(Qt::UserRole);
    Animal* animal = var.value<Animal*>();

    AnimalDetailsModal modal(animal, readOnly);
    modal.setModal(true);
    modal.exec();
    renderAnimalList();
}

void MainWindow::onClientClicked(QListWidgetItem* clientWidgetItem) {
    QVariant var = clientWidgetItem->data(Qt::UserRole);
    Client* client = var.value<Client*>();

    ClientDetailsModal modal(client, readOnly);
    modal.setModal(true);
    modal.exec();
    renderClientList();
}

void MainWindow::renderAnimalList() {
    ui->animalsListWidget->clear();

    QVector<Animal*>* animalVector = Animal::all();
    QVectorIterator<Animal*> i(*animalVector);

    while (i.hasNext()) {
        Animal* currentAnimal = i.next();
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->animalsListWidget);

        DetailListWidgetItem *animalWidget = new DetailListWidgetItem;
        animalWidget->setTitle(currentAnimal->name);
        animalWidget->setSubtitle(currentAnimal->breed);

        listWidgetItem->setSizeHint(animalWidget->sizeHint());

        QVariant var = QVariant::fromValue(currentAnimal);
        listWidgetItem->setData(Qt::UserRole, var);

        ui->animalsListWidget->setItemWidget(listWidgetItem, animalWidget);
    }
}

void MainWindow::renderClientList() {
    ui->clientsListWidget->clear();

    QVector<Client*>* clientVector = Client::all();
    QVectorIterator<Client*> i(*clientVector);

    while (i.hasNext()) {
        Client* currentClient = i.next();
        User* currentUser = User::findBy(currentClient->userId);
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->clientsListWidget);

        DetailListWidgetItem *clientWidget = new DetailListWidgetItem;
        clientWidget->setTitle(currentUser->name);
        clientWidget->setSubtitle(currentClient->email);

        listWidgetItem->setSizeHint(clientWidget->sizeHint());

        QVariant var = QVariant::fromValue(currentClient);
        listWidgetItem->setData(Qt::UserRole, var);

        ui->clientsListWidget->setItemWidget(listWidgetItem, clientWidget);
    }
}

void MainWindow::renderListItems() {
    renderAnimalList();
    renderClientList();
}

void MainWindow::handleAddAnimalAction() {
    AnimalDetailsModal modal(nullptr, false);
    modal.exec();
    renderAnimalList();
}


void MainWindow::handleAddClientAction() {
    ClientDetailsModal modal(nullptr, false);
    modal.exec();
    renderClientList();
}
