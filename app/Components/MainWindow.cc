﻿#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    StyleUtil().updateStyle(this);

    connect(ui->animalsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onAnimalClicked(QListWidgetItem*)));
    connect(ui->clientsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onClientClicked(QListWidgetItem*)));
    connect(ui->acmResultsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onMatchClicked(QListWidgetItem*)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showEvent(QShowEvent *event) {
    (void)event;

    LoginWindow l;
    int result = l.exec();

    if (result == 0 || Session::currentUser == nullptr) {
        QTimer::singleShot(0, this, SLOT(close()));
        return;
    }

    setGlobalElementsEnabled();
    renderListItems();
}

void MainWindow::setGlobalElementsEnabled() {
    bool isAdmin = Session::currentUser->getIsAdmin();

    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(1, isAdmin);
    ui->tabWidget->setTabEnabled(2, isAdmin);
    ui->menuTools->setEnabled(isAdmin);
    ui->actionEdit_My_Profile->setEnabled(!isAdmin);
}

void MainWindow::handleEditMyProfile() {
    QVector<Client*>* clients = Client::where("user_id", Session::currentUser->getId());

    if (clients->isEmpty()) {
        return;
    }

    Client* c = clients->first();

    ClientDetailsModal modal(c, false);
    modal.setModal(true);
    modal.exec();
}

void MainWindow::handleLogOut() {
    Session::currentUser = nullptr;

    hide();
    show();
}

void MainWindow::onAnimalClicked(QListWidgetItem* animalWidgetItem) {
    QVariant var = animalWidgetItem->data(Qt::UserRole);
    Animal* animal = var.value<Animal*>();

    bool canEdit = Session::currentUser->getIsAdmin();

    AnimalDetailsModal modal(animal, !canEdit);
    modal.setModal(true);
    modal.exec();
    renderAnimalList();
}

void MainWindow::onClientClicked(QListWidgetItem* clientWidgetItem) {
    QVariant var = clientWidgetItem->data(Qt::UserRole);
    Client* client = var.value<Client*>();

    ClientDetailsModal modal(client, true);
    modal.setModal(true);
    modal.exec();
    renderClientList();
}

void MainWindow::onMatchClicked(QListWidgetItem* matchWidgetItem) {
    QVariant var = matchWidgetItem->data(Qt::UserRole);
    Match* match = var.value<Match*>();

    MatchDetailsModal modal(match);
    modal.setModal(true);
    modal.exec();
}

void MainWindow::renderAnimalList() {
    ui->animalsListWidget->clear();

    QVector<Animal*>* animalVector = Animal::where("hypothetical", false);
    QVectorIterator<Animal*> i(*animalVector);

    while (i.hasNext()) {
        Animal* currentAnimal = i.next();
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->animalsListWidget);

        DetailListWidgetItem *animalWidget = new DetailListWidgetItem;
        animalWidget->setTitle(currentAnimal->name);
        animalWidget->setSubtitle(currentAnimal->breed);

        listWidgetItem->setSizeHint(animalWidget->sizeHint());

        QVariant var = QVariant::fromValue(currentAnimal);
        listWidgetItem->setData(Qt::UserRole, var);

        ui->animalsListWidget->setItemWidget(listWidgetItem, animalWidget);
    }
}

void MainWindow::renderClientList() {
    ui->clientsListWidget->clear();

    QVector<Client*>* clientVector = Client::all();
    QVectorIterator<Client*> i(*clientVector);

    while (i.hasNext()) {
        Client* currentClient = i.next();
        User* currentUser = User::findBy(currentClient->userId);

        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->clientsListWidget);

        DetailListWidgetItem *clientWidget = new DetailListWidgetItem;
        clientWidget->setTitle(currentUser->getName());
        clientWidget->setSubtitle(currentClient->email);

        listWidgetItem->setSizeHint(clientWidget->sizeHint());

        QVariant var = QVariant::fromValue(currentClient);
        listWidgetItem->setData(Qt::UserRole, var);

        ui->clientsListWidget->setItemWidget(listWidgetItem, clientWidget);
    }
}

void MainWindow::handleLaunchACM() {
    ui->acmResultsListWidget->clear();

    QHash<Animal*, QVector<Match*>> hash = CompatibilityScorer::calculate_scores();
    QVector<Match*> matches = MatchCreator::computeOptimalMatches(hash);

    QVectorIterator<Match*> i(matches);

    while (i.hasNext()) {
        Match* match = i.next();

        QListWidgetItem* listWidgetItem = new QListWidgetItem(ui->acmResultsListWidget);

        ACMResultListWidgetItem* matchWidget = new ACMResultListWidgetItem;

        Client* client = match->getClient();
        User* userAssociatedWithClient = User::findBy(client->userId);
        matchWidget->setClientName(userAssociatedWithClient->getName());
        matchWidget->setClientDetail(client->email);

        Animal* animal = match->getAnimal();
        matchWidget->setAnimalName(animal->name);

        const QString animalDetail =
                QString("A %1 %2 (%3)")
                .arg(animal->color.toLower())
                .arg(animal->species.toLower())
                .arg(animal->breed);

        matchWidget->setAnimalDetail(animalDetail);

        float rounded = roundf(match->getScore() * 10) / 10;
        matchWidget->setScore(rounded);

        listWidgetItem->setSizeHint(matchWidget->sizeHint());

        QVariant var = QVariant::fromValue(match);
        listWidgetItem->setData(Qt::UserRole, var);

        ui->acmResultsListWidget->setItemWidget(listWidgetItem, matchWidget);
    }
}

void MainWindow::renderListItems() {
    renderAnimalList();
    renderClientList();
}

void MainWindow::handleAddAnimalAction() {
    AnimalDetailsModal modal(nullptr, false);
    modal.exec();
    renderAnimalList();
}


void MainWindow::handleAddClientAction() {
    ClientDetailsModal modal(nullptr, false);
    modal.exec();
    renderClientList();
}
