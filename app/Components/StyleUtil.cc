#include "StyleUtil.h"

StyleUtil::StyleUtil() {}

void StyleUtil::updateStyle(QWidget *widget) {
    QFile file;
    file.setFileName("styles.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    QString stylesheet = in.readAll();
    stylesheet = stylesheet.trimmed();
    widget->setStyleSheet(stylesheet);
}
