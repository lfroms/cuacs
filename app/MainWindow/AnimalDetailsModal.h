#ifndef ANIMALDETAILSMODAL_H
#define ANIMALDETAILSMODAL_H

#include <QDialog>
#include <QMessageBox>
#include <Models/Animal/Animal.h>
#include <Models/CurrentUser/Session.h>

namespace Ui {
class AnimalDetailsModal;
}

class AnimalDetailsModal : public QDialog {
    Q_OBJECT

public:
    explicit AnimalDetailsModal(
            Animal* a,
            bool readOnly,
            bool idealAnimalMode = false,
            QWidget *parent = nullptr
            );
    ~AnimalDetailsModal();

private slots:
    void handleCancel();
    void handleSave();

private:
    Ui::AnimalDetailsModal *ui;
    Animal* animal;
    bool readOnly;
    bool idealAnimalMode;

    void loadProfileData();
    void setFieldsEnabled();
    void configureWindow();
};

#endif // ANIMALDETAILSMODAL_H
