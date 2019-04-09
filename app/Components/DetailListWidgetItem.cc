#include "DetailListWidgetItem.h"
#include "ui_DetailListWidgetItem.h"

DetailListWidgetItem::DetailListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailListWidgetItem) {

    ui->setupUi(this);

    StyleUtil().updateStyle(this);
}

DetailListWidgetItem::~DetailListWidgetItem() {
    delete ui;
}

void DetailListWidgetItem::setTitle(QString title) {
    ui->titleLabel->setText(title);
}

void DetailListWidgetItem::setSubtitle(QString subtitle) {
    ui->subtitleLabel->setText(subtitle);
}
