#ifndef STYLEUTIL_H
#define STYLEUTIL_H
#include <QFile>
#include <QWidget>
#include <QString>
#include <QTextStream>

class StyleUtil {
public:
    StyleUtil();
    void updateStyle(QWidget*);
};

#endif // STYLEUTIL_H
