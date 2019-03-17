#include "AnimalDetailsModal.h"
#include "ui_AnimalDetailsModal.h"

AnimalDetailsModal::AnimalDetailsModal(Animal* a, bool readOnly, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailsModal) {

    ui->setupUi(this);

    animal = a;
    this->readOnly = readOnly;

    if (a != nullptr) {
        setupViews();
    }

    configureWindow();
    setFieldsEnabled();
}

AnimalDetailsModal::~AnimalDetailsModal() {
    delete ui;
}

void AnimalDetailsModal::configureWindow() {
    QString windowTitle;

    if (animal != nullptr) {
        windowTitle = QString("%1's Details").arg(animal->getName());
    } else {
        windowTitle = QString("New Animal");
    }


    this->setWindowTitle(windowTitle);
}

void AnimalDetailsModal::setupViews() {
    int typeIndex = ui->animalType->findText(animal->getSpecies());
    ui->animalType->setCurrentIndex(typeIndex);

    ui->nameEdit->setText(animal->getName());
    ui->breedEdit->setText(animal->getBreed());

    int genderIndex = ui->gender->findText(animal->getGender());
    ui->gender->setCurrentIndex(genderIndex);

    ui->colorEdit->setText(animal->getColor());
    ui->ageEdit->setValue(animal->getAge());

    ui->neuteredCheckBox->setChecked(animal->getNeuteredOrSpayed());
    ui->medicalCheckbox->setChecked(animal->getRequiresMedicalAttn());

    ui->bite->setValue(animal->attr("bite_tendency"));
    ui->scratch->setValue(animal->attr("scratch_tendency"));
    ui->assertDominance->setValue(animal->attr("assert_dominance_tendency"));
    ui->adultFriendliness->setValue(animal->attr("friendliness_adults"));
    ui->childFriendliness->setValue(animal->attr("friendliness_children"));
    ui->animalFriendliness->setValue(animal->attr("friendliness_animals"));
    ui->noise->setValue(animal->attr("noise_level"));
    ui->independence->setValue(animal->attr("independence_level"));
    ui->affection->setValue(animal->attr("affection_level"));
    ui->energy->setValue(animal->attr("energy_level"));
    ui->anxiety->setValue(animal->attr("anxiety_level"));
    ui->curiosity->setValue(animal->attr("curiosity_level"));
}

void AnimalDetailsModal::setFieldsEnabled() {
    bool enabled = !readOnly;

    ui->animalType->setEnabled(enabled);
    ui->nameEdit->setEnabled(enabled);
    ui->breedEdit->setEnabled(enabled);
    ui->gender->setEnabled(enabled);
    ui->colorEdit->setEnabled(enabled);
    ui->ageEdit->setEnabled(enabled);
    ui->neuteredCheckBox->setEnabled(enabled);
    ui->medicalCheckbox->setEnabled(enabled);
    ui->bite->setEnabled(enabled);
    ui->scratch->setEnabled(enabled);
    ui->assertDominance->setEnabled(enabled);
    ui->adultFriendliness->setEnabled(enabled);
    ui->childFriendliness->setEnabled(enabled);
    ui->animalFriendliness->setEnabled(enabled);
    ui->noise->setEnabled(enabled);
    ui->independence->setEnabled(enabled);
    ui->affection->setEnabled(enabled);
    ui->energy->setEnabled(enabled);
    ui->anxiety->setEnabled(enabled);
    ui->curiosity->setEnabled(enabled);
}
