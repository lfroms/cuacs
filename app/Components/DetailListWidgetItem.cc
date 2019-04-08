#include "DetailListWidgetItem.h"
#include "ui_DetailListWidgetItem.h"
#include <QFile>
#include <QTextStream>

DetailListWidgetItem::DetailListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailListWidgetItem) {

    ui->setupUi(this);

    QFile file;
    file.setFileName("../app/Resources/styles.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //return;
    }
    QTextStream in(&file);
    QString stylesheet = in.readAll();
    stylesheet = stylesheet.trimmed();
    this->setStyleSheet(stylesheet);
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
