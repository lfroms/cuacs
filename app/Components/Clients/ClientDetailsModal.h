#ifndef CLIENTDETAILSMODAL_H
#define CLIENTDETAILSMODAL_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <Components/Animals/AnimalDetailsModal.h>
#include <Repository/Client/Client.h>
#include <Repository/User/User.h>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <Components/StyleUtil.h>

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
    bool performClientValidation();

    QString EMAIL_REGEX = QString("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    QString PHONE_REGEX = QString("^[+]*[(]{0,1}[0-9]{1,4}[)]{0,1}[-\s\./0-9]*$");
};

#endif // CLIENTDETAILSMODAL_H
