#ifndef ANIMALDETAILSMODAL_H
#define ANIMALDETAILSMODAL_H

#include <QDialog>
#include <Models/Animal.h>

namespace Ui {
class AnimalDetailsModal;
}

class AnimalDetailsModal : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalDetailsModal(Animal* a, QWidget *parent = nullptr);
    ~AnimalDetailsModal();

private:
    Ui::AnimalDetailsModal *ui;
    Animal* animal;

    void setupViews();
};

#endif // ANIMALDETAILSMODAL_H
