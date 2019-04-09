#include "MatchDetailsModal.h"
#include "ui_MatchDetailsModal.h"

MatchDetailsModal::MatchDetailsModal(Match * match, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatchDetailsModal)
{
    this->match = match;
    configureWindow();
    ui->setupUi(this);
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

    QHash<Animal*, QVector<Match*>> scores = CompatibilityScorer().calculate_scores();
    QVector<Match*> matchesForAnimal = scores[match->getAnimal()];
    QVector<Match*> sortedMatches = MatchCreator().sortAndThresholdMatches(matchesForAnimal);

    int ranking = sortedMatches.indexOf(match);

    QString rationale = QString("This matching was the best match possible without creating another match whose animal"
                        "or client would be better suited with this match's animal or client. "
                        "In absolute terms, this was the %1 best match for the animal in our entire database.").arg(ranking);

    ui->rationaleLabel->setText(rationale);
}

