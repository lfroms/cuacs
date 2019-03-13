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
    QString species, name, gender, color, breed;
    animal->getName(name);
    animal->getGender(gender);
    animal->getColor(color);
    animal->getBreed(breed);
    animal->getSpecies(species);

    //Setup Window properties
    this->setWindowTitle(name + QString("'s")+ QString(" Details"));

    //Setup UI elements
    ui->nameEdit->setText(name);
    ui->breedEdit->setText(breed);
    ui->genderEdit->setText(gender);
    ui->colorEdit->setText(color);
    ui->animalTypeLabel->setText(species);
    ui->ageEdit->setText(QString::number(animal->getAge()));

    // Temporarily set to 5 because these don't exist yet.
    ui->biteSlider->setValue(5);
    ui->scratchSlider->setValue(5);
    ui->dominanceSlider->setValue(5);
    ui->adultFriendlinessSlider->setValue(5);
    ui->childFriendlinessSlider->setValue(5);
    ui->animalFriendlinessSlider->setValue(5);
    ui->noisinessSlider->setValue(5);
    ui->independenceSlider->setValue(5);
    ui->affectionSlider->setValue(5);
    ui->energySlider->setValue(5);
    ui->anxietySlider->setValue(5);
    ui->curiositySlider->setValue(5);
    ui->neuteredCheckBox->setChecked(animal->getNeuteredOrSpayed());
    ui->neuteredCheckBox->setEnabled(false);
    ui->medicalCheckbox->setChecked(animal->getRequiresMedicalAttn());
}
