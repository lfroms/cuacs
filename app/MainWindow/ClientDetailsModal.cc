#include "ClientDetailsModal.h"
#include "ui_ClientDetailsModal.h"

ClientDetailsModal::ClientDetailsModal(Client * c, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetailsModal) {
    ui->setupUi(this);
    client = c;
    setupViews();
}

ClientDetailsModal::~ClientDetailsModal() {
    delete ui;
}

void ClientDetailsModal::setupViews() {
    QString clientName = client->getName();
    this->setWindowTitle(clientName + QString("'s")+ QString(" Details"));

    ui->clientNameEdit->setText(clientName);
    ui->clientAgeEdit->setText(QString::number(client->getAge()));
    ui->clientPhoneNumberEdit->setText(client->getPhoneNumber());
    ui->clientEmailEdit->setText(client->getEmail());
}
