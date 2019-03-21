#ifndef DETAILLISTWIDGETITEM_H
#define DETAILLISTWIDGETITEM_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class DetailListWidgetItem;
}

class DetailListWidgetItem : public QWidget {
    Q_OBJECT

public:
    explicit DetailListWidgetItem(QWidget *parent = nullptr);
    ~DetailListWidgetItem();

    void setTitle(QString title);
    void setSubtitle(QString subtitle);

private:
    Ui::DetailListWidgetItem *ui;
};

#endif // DETAILLISTWIDGETITEM_H
