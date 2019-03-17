#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setStyleSheet("QTabBar::tab::disabled {width: 0; height: 0; margin: 0; padding: 0; border: none;}");

    connect(ui->animalsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onAnimalClicked(QListWidgetItem*)));
    connect(ui->clientSubmit, SIGNAL (released()), this, SLOT (handleAddClientSubmit()));
    connect(ui->staffOrClientSelector, SIGNAL (currentIndexChanged(const QString&)), this, SLOT(onUserPermissionsChanged(const QString&)));
    connect(ui->clientsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onClientClicked(QListWidgetItem*)));

    renderListItems();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onUserPermissionsChanged(const QString& permissionLevel) {
    if (permissionLevel == "Client") {
        ui->tabWidget->setCurrentIndex(0);
        ui->tabWidget->setTabEnabled(3, false);
        ui->tabWidget->setTabEnabled(2, false);
        ui->tabWidget->setTabEnabled(1, false);
    } else {
        ui->tabWidget->setTabEnabled(3, true);
        ui->tabWidget->setTabEnabled(2, true);
        ui->tabWidget->setTabEnabled(1, true);
    }

}

void MainWindow::onAnimalClicked(QListWidgetItem* animalWidgetItem) {
    QVariant var = animalWidgetItem->data(Qt::UserRole);
    Animal* animal = var.value<Animal*>();

    AnimalDetailsModal modal(animal, false);
    modal.setModal(true);
    modal.exec();
}

void MainWindow::onClientClicked(QListWidgetItem* clientWidgetItem) {
    QVariant var = clientWidgetItem->data(Qt::UserRole);
    Client* client = var.value<Client*>();

    ClientDetailsModal modal(client);
    modal.setModal(true);
    modal.exec();
}

void MainWindow::renderAnimalList() {
    ui->animalsListWidget->clear();

    QVector<Animal*>* animalVector = Animal::all();
    QVectorIterator<Animal*> i(*animalVector);

    while (i.hasNext()) {
        Animal* currentAnimal = i.next();
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->animalsListWidget);

        DetailListWidgetItem *animalWidget = new DetailListWidgetItem;
        animalWidget->setTitle(currentAnimal->getName());
        animalWidget->setSubtitle(currentAnimal->getBreed());

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
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->clientsListWidget);

        DetailListWidgetItem *clientWidget = new DetailListWidgetItem;
        clientWidget->setTitle(currentClient->getName());
        clientWidget->setSubtitle(currentClient->getEmail());

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

void MainWindow::handleAddClientSubmit() {
    Client* client = new Client(
                ui->clientNameEdit->text(),
                ui->clientAgeEdit->text().toInt(),
                ui->clientPhoneNumberEdit->text(),
                ui->clientEmailEdit->text()
                );

    bool clientSaved = client->create();

    if (!clientSaved) {
        qDebug() << "Failed to add client to database.";
        return;
    }

    ui->clientNameEdit->clear();
    ui->clientAgeEdit->clear();
    ui->clientPhoneNumberEdit->clear();
    ui->clientEmailEdit->clear();

    renderClientList();
}
