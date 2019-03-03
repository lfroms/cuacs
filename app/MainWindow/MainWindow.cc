#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->submitButton, SIGNAL (released()), this, SLOT (handleAddAnimalSubmit()));
    connect(ui->animalsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onAnimalClicked(QListWidgetItem*)));
    db = DatabaseAdapter::getInstance();

    renderListItems();
}

MainWindow::~MainWindow() {
    delete ui;
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
                    ui->nameEdit->text(),
                    false,
                    ui->biteSlider->value(),
                    ui->scratchSlider->value(),
                    ui->adultFriendlinessSlider->value(),
                    ui->childFriendlinessSlider->value(),
                    ui->noiseSlider->value(),
                    ui->independenceSlider->value(),
                    ui->bedSleepSlider->value(),
                    ui->snoreSlider->value(),
                    ui->energySlider->value(),
                    ui->vetComfortSlider->value(),
                    ui->handledComfortSlider->value(),
                    ui->escapeSlider->value()
                    );

    } else if (animalType == "Cat") {
        animal = new Cat(
                    ui->genderEdit->text(),
                    ui->colorEdit->text(),
                    ui->breedEdit->text(),
                    ui->ageEdit->text().toInt(),
                    ui->neuteredCheckBox->isChecked(),
                    ui->nameEdit->text(),
                    false,
                    ui->biteSlider->value(),
                    ui->scratchSlider->value(),
                    ui->adultFriendlinessSlider->value(),
                    ui->childFriendlinessSlider->value(),
                    ui->noiseSlider->value(),
                    ui->independenceSlider->value(),
                    ui->bedSleepSlider->value(),
                    ui->snoreSlider->value(),
                    ui->energySlider->value(),
                    ui->vetComfortSlider->value(),
                    ui->handledComfortSlider->value(),
                    ui->escapeSlider->value()
                    );

    } else if (animalType == "Rabbit") {
        animal = new Rabbit(
                    ui->genderEdit->text(),
                    ui->colorEdit->text(),
                    ui->breedEdit->text(),
                    ui->ageEdit->text().toInt(),
                    ui->neuteredCheckBox->isChecked(),
                    ui->nameEdit->text(),
                    false,
                    ui->biteSlider->value(),
                    ui->scratchSlider->value(),
                    ui->adultFriendlinessSlider->value(),
                    ui->childFriendlinessSlider->value(),
                    ui->noiseSlider->value(),
                    ui->independenceSlider->value(),
                    ui->bedSleepSlider->value(),
                    ui->snoreSlider->value(),
                    ui->energySlider->value(),
                    ui->vetComfortSlider->value(),
                    ui->handledComfortSlider->value(),
                    ui->escapeSlider->value()
                    );
    }

    if (!db->insertAnimal(animal)) {
        qDebug() << "Failed to add animal to database.";
    }

    renderListItems();
}
