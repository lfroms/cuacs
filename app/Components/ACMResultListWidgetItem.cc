#include "ACMResultListWidgetItem.h"
#include "ui_ACMResultListWidgetItem.h"

ACMResultListWidgetItem::ACMResultListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ACMResultListWidgetItem) {

    ui->setupUi(this);
}

ACMResultListWidgetItem::~ACMResultListWidgetItem() {
    delete ui;
}

void ACMResultListWidgetItem::setClientName(QString clientName) {
    ui->clientName->setText(clientName);
}

void ACMResultListWidgetItem::setClientDetail(QString clientDetail) {
    ui->clientDetail->setText(clientDetail);
}

void ACMResultListWidgetItem::setAnimalName(QString animalName) {
    ui->animalName->setText(animalName);
}

void ACMResultListWidgetItem::setAnimalDetail(QString animalDetail) {
    ui->animalDetail->setText(animalDetail);
}
