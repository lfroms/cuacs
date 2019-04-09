#include "MatchDetailsModal.h"
#include "ui_MatchDetailsModal.h"

MatchDetailsModal::MatchDetailsModal(Match * match, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatchDetailsModal)
{
    ui->setupUi(this);
    this->match = match;
    configureWindow();
}

MatchDetailsModal::~MatchDetailsModal()
{
    delete ui;
}

void MatchDetailsModal::configureWindow() {
    ui->animalName->setText(match->getAnimal()->name);

    QString clientName = User::findBy(match->getClient()->userId)->getName();
    ui->clientName->setText(clientName);

    QVectorIterator<QString> rulesIter(match->getRules());

    while (rulesIter.hasNext()) {
        QString rule = rulesIter.next();
        ui->rulesList->addItem(rule);
    }

    QString rationale = QString("This matching was the best match possible without creating another match whose animal "
                        "or client would be better suited with this match's animal or client. "
                                "The ideal animal is given");

    ui->rationaleLabel->setText(rationale);
}

