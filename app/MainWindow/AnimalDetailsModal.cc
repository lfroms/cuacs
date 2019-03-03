#include "AnimalDetailsModal.h"
#include "ui_AnimalDetailsModal.h"

AnimalDetailsModal::AnimalDetailsModal(Animal* a, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailsModal)
{
    ui->setupUi(this);
    animal = a;
    setupViews();
}

AnimalDetailsModal::~AnimalDetailsModal()
{
    delete ui;
}

void AnimalDetailsModal::setupViews() {
    QString name, gender, mainColor, breed;
    animal->getName(name);
    animal->getGender(gender);
    animal->getMainColor(mainColor);
    animal->getBreed(breed);

    //Setup Window properties
    this->setWindowTitle(name + QString("'s")+ QString(" Details"));

    //Setup UI elements
    ui->nameEdit->setText(name);
    ui->breedEdit->setText(breed);
    ui->genderEdit->setText(gender);
    ui->colorEdit->setText(mainColor);
    ui->ageEdit->setText(QString::number(animal->getAge()));
    ui->biteSlider->setValue(animal->getBiteTendency());
    ui->scratchSlider->setValue(animal->getScratchTendency());
    ui->adultFriendlinessSlider->setValue(animal->getFriendlinessAdults());
    ui->childFriendlinessSlider->setValue(animal->getFriendlinessChildren());
    ui->noiseSlider->setValue(animal->getNoiseLevel());
    ui->independenceSlider->setValue(animal->getAloneComfort());
    ui->bedSleepSlider->setValue(animal->getLikesBedSleep());
    ui->snoreSlider->setValue(animal->getSnores());
    ui->energySlider->setValue(animal->getEnergyLevel());
    ui->vetComfortSlider->setValue(animal->getComfortableVet());
    ui->handledComfortSlider->setValue(animal->getComfortableHandled());
    ui->escapeSlider->setValue(animal->getEscapeTendency());
    ui->neuteredCheckBox->setChecked(animal->getNeuteredOrSpayed());
    ui->neuteredCheckBox->setEnabled(false);
    ui->animalTypeLabel->setText(animal->getTableName());
}
