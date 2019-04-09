#ifndef ACMRESULTLISTWIDGETITEM_H
#define ACMRESULTLISTWIDGETITEM_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class ACMResultListWidgetItem;
}

class ACMResultListWidgetItem : public QWidget {
    Q_OBJECT

public:
    explicit ACMResultListWidgetItem(QWidget *parent = nullptr);
    ~ACMResultListWidgetItem();

    void setClientName(QString clientName);
    void setClientDetail(QString clientDetail);

    void setAnimalName(QString animalName);
    void setAnimalDetail(QString animalDetail);

private:
    Ui::ACMResultListWidgetItem *ui;
};

#endif // ACMRESULTLISTWIDGETITEM_H
