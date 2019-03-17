#include "AnimalDetailsModal.h"
#include "ui_AnimalDetailsModal.h"

AnimalDetailsModal::AnimalDetailsModal(Animal* a, bool readOnly, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailsModal) {

    ui->setupUi(this);

    animal = a;
    this->readOnly = readOnly;

    if (a != nullptr) {
        loadProfileData();
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
        windowTitle = QString("%1's Details").arg(animal->name);
    } else {
        windowTitle = QString("New Animal");
    }

    this->setWindowTitle(windowTitle);
}

void AnimalDetailsModal::loadProfileData() {
    int typeIndex = ui->animalType->findText(animal->species);
    ui->animalType->setCurrentIndex(typeIndex);

    ui->nameEdit->setText(animal->name);
    ui->breedEdit->setText(animal->breed);

    int genderIndex = ui->gender->findText(animal->gender);
    ui->gender->setCurrentIndex(genderIndex);

    ui->colorEdit->setText(animal->color);
    ui->ageEdit->setValue(animal->age);

    ui->neuteredCheckBox->setChecked(animal->neuteredOrSpayed);
    ui->medicalCheckbox->setChecked(animal->requiresMedicalAttn);

    ui->bite->setValue(animal->attr("bite_tendency"));
    ui->scratch->setValue(animal->attr("scratch_tendency"));
    ui->assertDominance->setValue(animal->attr("assert_dominance_tendency"));
    ui->adultFriendliness->setValue(animal->attr("friendliness_adults"));
    ui->childFriendliness->setValue(animal->attr("friendliness_children"));
    ui->animalFriendliness->setValue(animal->attr("friendliness_animals"));
    ui->noise->setValue(animal->attr("noisiness"));
    ui->independence->setValue(animal->attr("independence"));
    ui->affection->setValue(animal->attr("affection"));
    ui->energy->setValue(animal->attr("energy"));
    ui->anxiety->setValue(animal->attr("anxiety"));
    ui->curiosity->setValue(animal->attr("curiosity"));
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

    ui->saveButton->setEnabled(enabled);
}

void AnimalDetailsModal::handleSave() {
    QMessageBox messageBox;
    messageBox.setWindowTitle("cuACS");

    if (animal == nullptr) {
        animal = new Animal();
    }

    animal->name = ui->nameEdit->text();
    animal->species = ui->animalType->currentText();
    animal->gender =ui->gender->currentText();
    animal->breed = ui->breedEdit->text();
    animal->age = ui->ageEdit->text().toInt();
    animal->neuteredOrSpayed = ui->neuteredCheckBox->isChecked();
    animal->requiresMedicalAttn =  ui->medicalCheckbox->isChecked();
    animal->color = ui->colorEdit->text();

    bool animalSaved = animal->save();

    if (!animalSaved) {
        messageBox.setText("Failed to save animal.");
        messageBox.exec();
        return;
    }

    animal
            ->setAttr("bite_tendency", ui->bite->value())
            ->setAttr("scratch_tendency", ui->scratch->value())
            ->setAttr("assert_dominance_tendency", ui->assertDominance->value())
            ->setAttr("friendliness_adults", ui->adultFriendliness->value())
            ->setAttr("friendliness_children", ui->childFriendliness->value())
            ->setAttr("friendliness_animals", ui->animalFriendliness->value())
            ->setAttr("noisiness", ui->noise->value())
            ->setAttr("independence", ui->independence->value())
            ->setAttr("affection", ui->affection->value())
            ->setAttr("energy", ui->energy->value())
            ->setAttr("anxiety", ui->anxiety->value())
            ->setAttr("curiosity", ui->curiosity->value());

    messageBox.setText("Animal profile saved.");
    messageBox.exec();
}

void AnimalDetailsModal::handleCancel() {
    this->close();
}
