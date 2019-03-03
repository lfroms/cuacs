#ifndef ANIMALWIDGETITEM_H
#define ANIMALWIDGETITEM_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class AnimalWidgetItem;
}

class AnimalWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit AnimalWidgetItem(QWidget *parent = 0);
    ~AnimalWidgetItem();
    void setName(QString name);
    void setBreed(QString breed);
private:
    Ui::AnimalWidgetItem *ui;
};

#endif // ANIMALWIDGETITEM_H
