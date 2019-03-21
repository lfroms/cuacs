#ifndef CLIENTDETAILSMODAL_H
#define CLIENTDETAILSMODAL_H

#include <QDialog>
#include <QMessageBox>
#include "AnimalDetailsModal.h"
#include <Models/Client/Client.h>
#include <Models/User/User.h>

namespace Ui {
class ClientDetailsModal;
}

class ClientDetailsModal : public QDialog {
    Q_OBJECT

public:
    explicit ClientDetailsModal(Client* c, bool readOnly, QWidget *parent = nullptr);
    ~ClientDetailsModal();

private slots:
    void handleCancel();
    void handleSave();
    void handleEditIdealAnimal();

private:
    Ui::ClientDetailsModal *ui;
    Client* client;
    bool readOnly;

    void loadProfileData();
    void setFieldsEnabled();
    void configureWindow();
};

#endif // CLIENTDETAILSMODAL_H
