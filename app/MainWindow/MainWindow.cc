#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->submitButton, SIGNAL (released()), this, SLOT (handleAddAnimalSubmit()));
    db = DatabaseAdapter::getInstance();
}

MainWindow::~MainWindow() {
    delete ui;
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

    if (db->insertAnimal(animal)) {
        qDebug() << "success";
    } else {
        qDebug() << "failure";
    }

}
