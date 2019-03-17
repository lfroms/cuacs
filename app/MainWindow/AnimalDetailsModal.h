#ifndef ANIMALDETAILSMODAL_H
#define ANIMALDETAILSMODAL_H

#include <QDialog>
#include <QMessageBox>
#include <Models/Animal/Animal.h>

namespace Ui {
class AnimalDetailsModal;
}

class AnimalDetailsModal : public QDialog {
    Q_OBJECT

public:
    explicit AnimalDetailsModal(Animal* a, bool readOnly, QWidget *parent = nullptr);
    ~AnimalDetailsModal();

private slots:
    void handleCancel();
    void handleSave();

private:
    Ui::AnimalDetailsModal *ui;
    Animal* animal;
    bool readOnly;

    void loadProfileData();
    void setFieldsEnabled();
    void configureWindow();
};

#endif // ANIMALDETAILSMODAL_H
