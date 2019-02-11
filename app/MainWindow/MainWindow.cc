#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->submitButton, SIGNAL (released()), this, SLOT (handleAddAnimalSubmit()));
    // Unused, this line is present to test the database initialization.
    db = DatabaseAdapter::getInstance();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handleAddAnimalSubmit() {
    qDebug() << "Hey, the button was pushed";
    qDebug() << ui->biteSlider->value() << " bite strength";

    QString animalType = ui->animalTypeBox->currentText();
    Animal* animal;
    if (animalType == "Dog") {
        animal = new Dog(4,
                      6,
                      7,
                      ui->nameEdit->text().toStdString(),
                      ui->genderEdit->text().toStdString(),
                      ui->breedEdit->text().toStdString(),
                      ui->colorEdit->text().toStdString(),
                      ui->neuteredCheckBox->isChecked(),
                      false,

                      ui->ageEdit->text().toInt(),
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
        animal = new Cat("indoor",
                      4,
                      8,
                      ui->nameEdit->text().toStdString(),
                      ui->genderEdit->text().toStdString(),
                      ui->breedEdit->text().toStdString(),
                      ui->colorEdit->text().toStdString(),
                      ui->neuteredCheckBox->isChecked(),
                      false,

                      ui->ageEdit->text().toInt(),
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
        animal = new Rabbit(7,
                      ui->nameEdit->text().toStdString(),
                      ui->genderEdit->text().toStdString(),
                      ui->breedEdit->text().toStdString(),
                      ui->colorEdit->text().toStdString(),
                      ui->neuteredCheckBox->isChecked(),
                      false,

                      ui->ageEdit->text().toInt(),
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
    qDebug() << "hey the animal was created";
    if (db->insertAnimal(animal)) {
        qDebug() << "success";
    } else {
        qDebug() << "failure";
    }

}
