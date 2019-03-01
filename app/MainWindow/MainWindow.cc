#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->submitButton, SIGNAL (released()), this, SLOT (handleAddAnimalSubmit()));
    db = DatabaseAdapter::getInstance();

    renderListItems();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::renderListItems() {
    ui->animalsListWidget->clear();

    int numAnimals = db->getTotalAnimals();
    Animal * animals[numAnimals];
    db->getAnimals(animals);

    for (int i = 0; i < numAnimals; i++) {
        QString name, breed;
        animals[i]->getName(name);
        animals[i]->getBreed(breed);

        //Creating a new list widget item whose parent is the listwidget itself
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->animalsListWidget);

        //Creating an object of the designed widget which is to be added to the listwidget
        AnimalWidgetItem *theWidgetItem = new AnimalWidgetItem;
        theWidgetItem->setName(name);
        theWidgetItem->setBreed(breed);
        //Making sure that the listWidgetItem has the same size as the TheWidgetItem
        QSize a = theWidgetItem->sizeHint();
        listWidgetItem->setSizeHint (theWidgetItem->sizeHint ());

        //Finally adding the itemWidget to the list
        ui->animalsListWidget->setItemWidget (listWidgetItem, theWidgetItem);

        //Adding the item to the listwidget
        //ui->animalsListWidget->addItem (label);
    }
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
