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

    ui->biteSlider->setValue(animal->attr("bite_tendency"));
    ui->scratchSlider->setValue(animal->attr("scratch_tendency"));
    ui->dominanceSlider->setValue(animal->attr("assert_dominance_tendency"));
    ui->adultFriendlinessSlider->setValue(animal->attr("friendliness_humans"));
    ui->childFriendlinessSlider->setValue(animal->attr("friendliness_children"));
    ui->animalFriendlinessSlider->setValue(animal->attr("friendliness_animals"));
    ui->noisinessSlider->setValue(animal->attr("noise_level"));
    ui->independenceSlider->setValue(animal->attr("independence_level"));
    ui->affectionSlider->setValue(animal->attr("affection_level"));
    ui->energySlider->setValue(animal->attr("energy_level"));
    ui->anxietySlider->setValue(animal->attr("anxiety_level"));
    ui->curiositySlider->setValue(animal->attr("curiosity_level"));
    ui->neuteredCheckBox->setChecked(animal->getNeuteredOrSpayed());
    ui->neuteredCheckBox->setEnabled(false);
    ui->medicalCheckbox->setChecked(animal->getRequiresMedicalAttn());
}
