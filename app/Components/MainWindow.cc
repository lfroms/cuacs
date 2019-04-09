#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setStyleSheet("QTabBar::tab::disabled {width: 0; height: 0; margin: 0; padding: 0; border: none;}");

    connect(ui->animalsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onAnimalClicked(QListWidgetItem*)));
    connect(ui->clientsListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(onClientClicked(QListWidgetItem*)));
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
    QHashIterator<Animal*, QVector<Match*>> hashIterator(hash);

    while (hashIterator.hasNext()) {
        hashIterator.next();
        QVector<Match*> matches = hashIterator.value();

        QVectorIterator<Match*> matchIterator(matches);

        while (matchIterator.hasNext()) {
            Match* match = matchIterator.next();

            QListWidgetItem* listWidgetItem = new QListWidgetItem(ui->acmResultsListWidget);

            ACMResultListWidgetItem* matchWidget = new ACMResultListWidgetItem;

            Client* client = match->getClient();
            User* userAssociatedWithClient = User::findBy(client->userId);
            matchWidget->setClientName(userAssociatedWithClient->getName());
            matchWidget->setClientDetail(client->email);

            Animal* animal = match->getAnimal();
            matchWidget->setAnimalName(animal->name);
            matchWidget->setAnimalDetail(animal->species);

            QVariant var = QVariant::fromValue(match);
            listWidgetItem->setData(Qt::UserRole, var);

            ui->acmResultsListWidget->setItemWidget(listWidgetItem, matchWidget);

            qDebug() << match->getAnimal()->name << match->getClient()->email << match->getScore() << match->getRules();
        }
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
