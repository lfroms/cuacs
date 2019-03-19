#include "ClientDetailsModal.h"
#include "ui_ClientDetailsModal.h"

ClientDetailsModal::ClientDetailsModal(Client* c, bool readOnly, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetailsModal) {

    ui->setupUi(this);

    client = c;
    this->readOnly = readOnly;

    if (c != nullptr) {
        loadProfileData();
    }

    configureWindow();
    setFieldsEnabled();
}

ClientDetailsModal::~ClientDetailsModal() {
    delete ui;
}

void ClientDetailsModal::configureWindow() {
    QString windowTitle;

    if (client != nullptr) {
        windowTitle = QString("%1's Details").arg(client->getName());
    } else {
        windowTitle = QString("New Client");
    }

    this->setWindowTitle(windowTitle);
}

void ClientDetailsModal::loadProfileData() {
    QString clientName = client->getName();
    this->setWindowTitle(clientName + QString("'s")+ QString(" Details"));

    ui->name->setText(clientName);
    ui->age->setValue(client->getAge());
    ui->phoneNumber->setText(client->getPhoneNumber());
    ui->email->setText(client->getEmail());
}

void ClientDetailsModal::setFieldsEnabled() {
    bool enabled = !readOnly;

    ui->name->setEnabled(enabled);
    ui->age->setEnabled(enabled);
    ui->phoneNumber->setEnabled(enabled);
    ui->email->setEnabled(enabled);

    ui->assertiveness->setEnabled(enabled);
    ui->socialness->setEnabled(enabled);
    ui->noisiness->setEnabled(enabled);
    ui->independence->setEnabled(enabled);
    ui->affection->setEnabled(enabled);
    ui->fitness->setEnabled(enabled);
    ui->anxiety->setEnabled(enabled);
    ui->curiosity->setEnabled(enabled);

    ui->sqFoot->setEnabled(enabled);
    ui->salary->setEnabled(enabled);
    ui->hrDedication->setEnabled(enabled);
    ui->ownedAnimal->setEnabled(enabled);
    ui->ownsAnimal->setEnabled(enabled);
    ui->hasChildren->setEnabled(enabled);
}

void ClientDetailsModal::handleSave() {
    QMessageBox messageBox;
    messageBox.setWindowTitle("cuACS");

    if (client == nullptr) {
        client = new Client();
    }

    // TODO: Set members of client (i.e. client->name = ui->...)

    bool clientSaved = client->save();

    if (!clientSaved) {
        messageBox.setText("Failed to save client.");
        messageBox.exec();
        return;
    }

    // TODO: Set attributes of client

    messageBox.setText("Client profile saved.");
    messageBox.exec();
}

void ClientDetailsModal::handleCancel() {
    this->close();
}
