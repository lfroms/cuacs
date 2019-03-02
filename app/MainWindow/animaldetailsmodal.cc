#include "animaldetailsmodal.h"
#include "ui_animaldetailsmodal.h"

AnimalDetailsModal::AnimalDetailsModal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailsModal)
{
    ui->setupUi(this);
}

AnimalDetailsModal::~AnimalDetailsModal()
{
    delete ui;
}

void AnimalDetailsModal::setAnimal(Animal* a) {
    animal = a;
}

void AnimalDetailsModal::setupViews() {
    QString name, gender, mainColor, breed;
    animal->getName(name);
    animal->getGender(gender);
    animal->getMainColor(mainColor);
    animal->getBreed(breed);
    ui->nameEdit->setText(name);
    ui->breedEdit->setText(breed);
    ui->genderEdit->setText(gender);
    ui->colorEdit->setText(mainColor);
    ui->ageEdit->setText(QString::number(animal->getAge()));
}
