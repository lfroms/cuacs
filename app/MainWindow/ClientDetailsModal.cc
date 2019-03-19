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

    ui->clientNameEdit->setText(clientName);
    ui->clientAgeEdit->setText(QString::number(client->getAge()));
    ui->clientPhoneNumberEdit->setText(client->getPhoneNumber());
    ui->clientEmailEdit->setText(client->getEmail());
}

void ClientDetailsModal::setFieldsEnabled() {
    bool enabled = !readOnly;
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
