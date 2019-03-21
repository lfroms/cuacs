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
        User* user = User::findBy(client->userId);

        windowTitle = QString("%1's Details").arg(user->getName());
    } else {
        windowTitle = QString("New Client");
    }

    this->setWindowTitle(windowTitle);
}

void ClientDetailsModal::loadProfileData() {
    User* user = User::findBy(client->userId);
    QString clientName = user->getName();
    this->setWindowTitle(clientName + QString("'s")+ QString(" Details"));

    ui->name->setText(clientName);
    ui->age->setValue(client->age);
    ui->phoneNumber->setText(client->phoneNumber);
    ui->email->setText(client->email);

    ui->assertiveness->setValue(client->attr("assertiveness"));
    ui->socialness->setValue(client->attr("socialness"));
    ui->noisiness->setValue(client->attr("noisiness"));
    ui->independence->setValue(client->attr("independence"));
    ui->affection->setValue(client->attr("affection"));
    ui->fitness->setValue(client->attr("energy"));
    ui->anxiety->setValue(client->attr("anxiety"));
    ui->curiosity->setValue(client->attr("curiosity"));

    ui->sqFoot->setValue(client->homeSqFoot);
    ui->salary->setValue(client->salary);
    ui->hrDedication->setValue(client->hrsDedication);
    ui->ownedAnimal->setChecked(client->ownedAnimal);
    ui->ownsAnimal->setChecked(client->ownsAnimal);
    ui->hasChildren->setChecked(client->hasChildren);
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

    ui->saveButton->setEnabled(enabled);

    // Edit Ideal Animal Button
    bool shouldEnableButton = client->idealAnimalId != -1 || !readOnly;
    ui->editIdealAnimal->setEnabled(shouldEnableButton);
}

void ClientDetailsModal::handleSave() {
    QMessageBox messageBox;
    messageBox.setWindowTitle("cuACS");

    User* user = nullptr;

    if (client == nullptr) {
        client = new Client();
        user = new User(ui->name->text(), "", Client::className());
    } else {
        user = User::findBy(client->userId);
        user->setName(ui->name->text());
    }

    bool userSaved = user->save();

    if (!userSaved) {
        messageBox.setText("Failed to save user.");
        messageBox.exec();
        return;
    }

    client->userId = user->getId();
    client->age = ui->age->value();
    client->phoneNumber = ui->phoneNumber->text();
    client->email = ui->email->text();

    client->homeSqFoot = ui->sqFoot->value();
    client->salary = ui->salary->value();
    client->hrsDedication = ui->hrDedication->value();
    client->ownedAnimal = ui->ownedAnimal->isChecked();
    client->ownsAnimal = ui->ownsAnimal->isChecked();
    client->hasChildren = ui->hasChildren->isChecked();

    bool clientSaved = client->save();

    if (!clientSaved) {
        messageBox.setText("Failed to save client.");
        messageBox.exec();
        return;
    }

    client
            ->setAttr("assertiveness", ui->assertiveness->value())
            ->setAttr("socialness", ui->socialness->value())
            ->setAttr("noisiness", ui->noisiness->value())
            ->setAttr("independence", ui->independence->value())
            ->setAttr("affection", ui->affection->value())
            ->setAttr("energy", ui->fitness->value())
            ->setAttr("anxiety", ui->anxiety->value())
            ->setAttr("curiosity", ui->curiosity->value());

    messageBox.setText("Client profile saved.");
    messageBox.exec();
}

void ClientDetailsModal::handleEditIdealAnimal() {
    Animal* a = Animal::findBy(client->idealAnimalId);

    int beforeCount = Animal::count();

    AnimalDetailsModal modal(a, false, true);
    modal.exec();

    int afterCount = Animal::count();

    if (beforeCount == afterCount && a == nullptr) {
        return;
    }

    if (beforeCount != afterCount && a == nullptr) {
        a = Animal::last();
    }

    client->idealAnimalId = a->getId();
    client->save();
}

void ClientDetailsModal::handleCancel() {
    this->close();
}
