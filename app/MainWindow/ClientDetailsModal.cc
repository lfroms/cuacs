#include "ClientDetailsModal.h"
#include "ui_ClientDetailsModal.h"

ClientDetailsModal::ClientDetailsModal(Client * c, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetailsModal)
{
    ui->setupUi(this);
    client = c;
    setupViews();
}

ClientDetailsModal::~ClientDetailsModal() {
    delete ui;
}

void ClientDetailsModal::setupViews() {
    int age;
    QString name, phoneNumber, email;

    client->getName(name);
    client->getAge(age);
    client->getPhoneNumber(phoneNumber);
    client->getEmail(email);

    this->setWindowTitle(name + QString("'s")+ QString(" Details"));

    ui->clientNameEdit->setText(name);
    ui->clientAgeEdit->setText(QString(age));
    ui->clientPhoneNumberEdit->setText(phoneNumber);
    ui->clientEmailEdit->setText(email);
}
