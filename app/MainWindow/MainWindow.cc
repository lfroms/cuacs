#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setStyleSheet("QTabBar::tab::disabled {width: 0; height: 0; margin: 0; padding: 0; border: none;}");

    connect(ui->submitButton, SIGNAL (released()), this, SLOT (handleAddAnimalSubmit()));
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
    if (permissionLevel == QString("Client")) {
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
    Animal animal = var.value<Animal>();

    AnimalDetailsModal modal(&animal);
    modal.setModal(true);
    modal.exec();
}

void MainWindow::onClientClicked(QListWidgetItem* clientWidgetItem) {
    QVariant var = clientWidgetItem->data(Qt::UserRole);
    Client client = var.value<Client>();

    ClientDetailsModal modal(&client);
    modal.setModal(true);
    modal.exec();
}

void MainWindow::renderAnimalList() {
    ui->animalsListWidget->clear();

    QVector<Animal>* animalVector = Animal::all();
    QVectorIterator<Animal> i(*animalVector);

    while (i.hasNext()) {
        Animal currentAnimal = i.next();

        QString name, breed;
        currentAnimal.getName(name);
        currentAnimal.getBreed(breed);

        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->animalsListWidget);

        DetailListWidgetItem *animalWidget = new DetailListWidgetItem;
        animalWidget->setTitle(name);
        animalWidget->setSubtitle(breed);

        listWidgetItem->setSizeHint(animalWidget->sizeHint());

        QVariant var = QVariant::fromValue(currentAnimal);
        listWidgetItem->setData(Qt::UserRole, var);

        ui->animalsListWidget->setItemWidget(listWidgetItem, animalWidget);
    }
}

void MainWindow::renderClientList() {
    ui->clientsListWidget->clear();

    QVector<Client>* clientVector = Client::all();
    QVectorIterator<Client> i(*clientVector);

    while (i.hasNext()) {
        Client currentClient = i.next();

        QString name, email;
        currentClient.getName(name);
        currentClient.getEmail(email);

        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->clientsListWidget);

        DetailListWidgetItem *clientWidget = new DetailListWidgetItem;
        clientWidget->setTitle(name);
        clientWidget->setSubtitle(email);

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

void MainWindow::handleAddAnimalSubmit() {
    Animal* animal;
    animal = new Animal(
                ui->nameEdit->text(),
                ui->animalTypeBox->currentText(),
                ui->genderEdit->text(),
                ui->breedEdit->text(),
                ui->ageEdit->text().toInt(),
                ui->neuteredCheckBox->isChecked(),
                ui->medicalCheckbox->isChecked(),
                ui->colorEdit->text(),
                false
                );

    bool animalSaved = animal->create();

    if (!animalSaved) {
        qDebug() << "Failed to add animal to database.";
        return;
    }

    animal
            ->setAttr("bite_tendency", ui->bite->value())
            ->setAttr("scratch_tendency", ui->scratch->value())
            ->setAttr("assert_dominance_tendency", ui->dominance->value())
            ->setAttr("friendliness_adults", ui->adultFriendliness->value())
            ->setAttr("friendliness_children", ui->childFriendliness->value())
            ->setAttr("friendliness_animals", ui->animalFriendliness->value())
            ->setAttr("noise_level", ui->noise->value())
            ->setAttr("independence_level", ui->independence->value())
            ->setAttr("affection_level", ui->affection->value())
            ->setAttr("energy_level", ui->energy->value())
            ->setAttr("anxiety_level", ui->anxiety->value())
            ->setAttr("curiosity_level", ui->curiosity->value());

    ui->nameEdit->clear();
    ui->genderEdit->clear();
    ui->colorEdit->clear();
    ui->breedEdit->clear();
    ui->ageEdit->clear();
    ui->neuteredCheckBox->setChecked(false);
    ui->medicalCheckbox->setChecked(false);
    ui->bite->setValue(5);
    ui->scratch->setValue(5);
    ui->dominance->setValue(5);
    ui->adultFriendliness->setValue(5);
    ui->childFriendliness->setValue(5);
    ui->animalFriendliness->setValue(5);
    ui->noise->setValue(5);
    ui->independence->setValue(5);
    ui->affection->setValue(5);
    ui->energy->setValue(5);
    ui->anxiety->setValue(5);
    ui->curiosity->setValue(5);

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
