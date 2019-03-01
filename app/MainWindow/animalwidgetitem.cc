#include "animalwidgetitem.h"
#include "ui_animalwidgetitem.h"

AnimalWidgetItem::AnimalWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimalWidgetItem)
{
    ui->setupUi(this);
}

AnimalWidgetItem::~AnimalWidgetItem()
{
    delete ui;
}

void AnimalWidgetItem::setName(QString name) {
    ui->nameLabel->setText(name);
}

void AnimalWidgetItem::setBreed(QString breed) {
    ui->breedLabel->setText(breed);
}
