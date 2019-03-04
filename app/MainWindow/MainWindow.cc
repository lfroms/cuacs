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

    db = DatabaseAdapter::getInstance();

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
    Animal * animal = var.value<Animal *>();

    AnimalDetailsModal modal(animal);
    modal.setModal(true);
    modal.exec();
}

void MainWindow::renderAnimalList() {
    ui->animalsListWidget->clear();

    int numAnimals = db->getTotalAnimals();
    Animal * animals[numAnimals];
    db->getAnimals(animals);

    for (int i = 0; i < numAnimals; i++) {
        QString name, breed;
        animals[i]->getName(name);
        animals[i]->getBreed(breed);

        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->animalsListWidget);

        DetailListWidgetItem *animalWidget = new DetailListWidgetItem;
        animalWidget->setTitle(name);
        animalWidget->setSubtitle(breed);

        //Sizing list widget appropriately
        listWidgetItem->setSizeHint(animalWidget->sizeHint());

        //Turn Animal to QVariant to attach it to listWidgetItem
        QVariant var = QVariant::fromValue(animals[i]);
        listWidgetItem->setData(Qt::UserRole, var);

        //Finally attach animalWidget to listItem
        ui->animalsListWidget->setItemWidget(listWidgetItem, animalWidget);
    }
}

void MainWindow::renderClientList() {
    ui->clientsListWidget->clear();

    int numClients = db->getClientCount();
    Client * clients[numClients];
    db->getClients(clients);

    for (int i = 0; i < numClients; i++) {
        QString name, email;
        clients[i]->getName(name);
        clients[i]->getEmail(email);

        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->clientsListWidget);

        DetailListWidgetItem *clientWidget = new DetailListWidgetItem;
        clientWidget->setTitle(name);
        clientWidget->setSubtitle(email);

        listWidgetItem->setSizeHint(clientWidget->sizeHint());

        QVariant var = QVariant::fromValue(clients[i]);
        listWidgetItem->setData(Qt::UserRole, var);

        ui->clientsListWidget->setItemWidget(listWidgetItem, clientWidget);
    }
}


void MainWindow::renderListItems() {
    renderAnimalList();
    renderClientList();
}


void MainWindow::handleAddAnimalSubmit() {
    QString animalType = ui->animalTypeBox->currentText();
    Animal* animal;
    if (animalType == "Dog") {
        animal = new Dog(
                    ui->genderEdit->text(),
                    ui->colorEdit->text(),
                    ui->breedEdit->text(),
                    ui->ageEdit->text().toInt(),
                    ui->neuteredCheckBox->isChecked(),
                    ui->medicalCheckbox->isChecked(),
                    ui->nameEdit->text(),
                    false,
                    ui->biteSlider->value(),
                    ui->scratchSlider->value(),
                    ui->dominanceSlider->value(),
                    ui->adultFriendlinessSlider->value(),
                    ui->childFriendlinessSlider->value(),
                    ui->animalFriendlinessSlider->value(),
                    ui->noisinessSlider->value(),
                    ui->independenceSlider->value(),
                    ui->affectionSlider->value(),
                    ui->energySlider->value(),
                    ui->anxietySlider->value(),
                    ui->curiositySlider->value()
                    );

    } else if (animalType == "Cat") {
        animal = new Cat(
                    ui->genderEdit->text(),
                    ui->colorEdit->text(),
                    ui->breedEdit->text(),
                    ui->ageEdit->text().toInt(),
                    ui->neuteredCheckBox->isChecked(),
                    ui->medicalCheckbox->isChecked(),
                    ui->nameEdit->text(),
                    false,
                    ui->biteSlider->value(),
                    ui->scratchSlider->value(),
                    ui->dominanceSlider->value(),
                    ui->adultFriendlinessSlider->value(),
                    ui->childFriendlinessSlider->value(),
                    ui->animalFriendlinessSlider->value(),
                    ui->noisinessSlider->value(),
                    ui->independenceSlider->value(),
                    ui->affectionSlider->value(),
                    ui->energySlider->value(),
                    ui->anxietySlider->value(),
                    ui->curiositySlider->value()
                    );

    } else if (animalType == "Rabbit") {
        animal = new Rabbit(
                    ui->genderEdit->text(),
                    ui->colorEdit->text(),
                    ui->breedEdit->text(),
                    ui->ageEdit->text().toInt(),
                    ui->neuteredCheckBox->isChecked(),
                    ui->medicalCheckbox->isChecked(),
                    ui->nameEdit->text(),
                    false,
                    ui->biteSlider->value(),
                    ui->scratchSlider->value(),
                    ui->dominanceSlider->value(),
                    ui->adultFriendlinessSlider->value(),
                    ui->childFriendlinessSlider->value(),
                    ui->animalFriendlinessSlider->value(),
                    ui->noisinessSlider->value(),
                    ui->independenceSlider->value(),
                    ui->affectionSlider->value(),
                    ui->energySlider->value(),
                    ui->anxietySlider->value(),
                    ui->curiositySlider->value()
                    );
    }

    if (!db->insertAnimal(animal)) {
        qDebug() << "Failed to add animal to database.";
        return;
    }

    renderAnimalList();
}

void MainWindow::handleAddClientSubmit() {
    Client* client = new Client(
                ui->clientNameEdit->text(),
                ui->clientAgeEdit->text().toInt(),
                ui->clientPhoneNumberEdit->text(),
                ui->clientEmailEdit->text()
                );

    if (!db->saveClient(client)) {
        qDebug() << "Failed to add client to database.";
        return;
    }

    ui->clientNameEdit->clear();
    ui->clientAgeEdit->clear();
    ui->clientPhoneNumberEdit->clear();
    ui->clientEmailEdit->clear();

    renderClientList();
}
