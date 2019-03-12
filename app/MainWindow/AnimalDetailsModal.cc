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
    QString species, name, gender, mainColor, breed;
    animal->getName(name);
    animal->getGender(gender);
    animal->getMainColor(mainColor);
    animal->getBreed(breed);
    animal->getSpecies(species);

    //Setup Window properties
    this->setWindowTitle(name + QString("'s")+ QString(" Details"));

    //Setup UI elements
    ui->nameEdit->setText(name);
    ui->breedEdit->setText(breed);
    ui->genderEdit->setText(gender);
    ui->colorEdit->setText(mainColor);
    ui->animalTypeLabel->setText(species);
    ui->ageEdit->setText(QString::number(animal->getAge()));
    ui->biteSlider->setValue(animal->getBiteTendency());
    ui->scratchSlider->setValue(animal->getScratchTendency());
    ui->dominanceSlider->setValue(animal->getDominanceTendency());
    ui->adultFriendlinessSlider->setValue(animal->getFriendlinessAdults());
    ui->childFriendlinessSlider->setValue(animal->getFriendlinessChildren());
    ui->animalFriendlinessSlider->setValue(animal->getFriendlinessAnimals());
    ui->noisinessSlider->setValue(animal->getNoiseLevel());
    ui->independenceSlider->setValue(animal->getIndependence());
    ui->affectionSlider->setValue(animal->getAffection());
    ui->energySlider->setValue(animal->getEnergyLevel());
    ui->anxietySlider->setValue(animal->getAnxietyLevel());
    ui->curiositySlider->setValue(animal->getCuriosityLevel());
    ui->neuteredCheckBox->setChecked(animal->getNeuteredOrSpayed());
    ui->neuteredCheckBox->setEnabled(false);
    ui->medicalCheckbox->setChecked(animal->getRequiresMedicalAttention());
    ui->medicalCheckbox->setEnabled(false);
}
