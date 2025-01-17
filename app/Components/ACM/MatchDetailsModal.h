#ifndef MATCHDETAILSMODAL_H
#define MATCHDETAILSMODAL_H

#include <QDialog>
#include <QString>
#include <QVectorIterator>
#include <Components/ACM/Match.h>
#include <Repository/User/User.h>

namespace Ui {
class MatchDetailsModal;
}

class MatchDetailsModal : public QDialog {
    Q_OBJECT

public:
    explicit MatchDetailsModal(Match* match, QWidget *parent = nullptr);
    ~MatchDetailsModal();

private:
    Ui::MatchDetailsModal *ui;
    Match* match;
    void configureWindow();
};

#endif // MATCHDETAILSMODAL_H
