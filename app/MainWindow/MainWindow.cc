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

    if (result == 0 || CurrentUser::user == nullptr) {
        QTimer::singleShot(0, this, SLOT(close()));
        return;
    }

    setGlobalElementsEnabled();
    renderListItems();
}

void MainWindow::setGlobalElementsEnabled() {
    bool isAdmin = CurrentUser::user->getIsAdmin();

    ui->actionAdd_Animal->setEnabled(isAdmin);
    ui->actionAdd_Client->setEnabled(isAdmin);
}

void MainWindow::onAnimalClicked(QListWidgetItem* animalWidgetItem) {
    QVariant var = animalWidgetItem->data(Qt::UserRole);
    Animal* animal = var.value<Animal*>();

    bool canEdit = CurrentUser::user->getIsAdmin();

    AnimalDetailsModal modal(animal, !canEdit);
    modal.setModal(true);
    modal.exec();
    renderAnimalList();
}

void MainWindow::onClientClicked(QListWidgetItem* clientWidgetItem) {
    QVariant var = clientWidgetItem->data(Qt::UserRole);
    Client* client = var.value<Client*>();

    bool canEdit = CurrentUser::user->getIsAdmin();

    if (client->getId() == CurrentUser::user->getId()) {
        canEdit = true;
    }

    ClientDetailsModal modal(client, !canEdit);
    modal.setModal(true);
    modal.exec();
    renderClientList();
}

void MainWindow::renderAnimalList() {
    ui->animalsListWidget->clear();

    QVector<Animal*>* animalVector = Animal::all();
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

        bool hasReadWritePermission = CurrentUser::user->getIsAdmin();

        if (currentClient->getId() == CurrentUser::user->getId()) {
            hasReadWritePermission = true;
        }

        if (!hasReadWritePermission) {
            continue;
        }

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
