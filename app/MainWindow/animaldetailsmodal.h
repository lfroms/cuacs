#ifndef ANIMALDETAILSMODAL_H
#define ANIMALDETAILSMODAL_H

#include <QDialog>
#include <Models/animal.h>

namespace Ui {
class AnimalDetailsModal;
}

class AnimalDetailsModal : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalDetailsModal(QWidget *parent = 0);
    ~AnimalDetailsModal();
    void setAnimal(Animal* a);
    void setupViews();

private:
    Ui::AnimalDetailsModal *ui;
    Animal* animal;
};

#endif // ANIMALDETAILSMODAL_H
