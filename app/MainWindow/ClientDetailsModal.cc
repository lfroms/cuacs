#include "ClientDetailsModal.h"
#include "ui_ClientDetailsModal.h"

ClientDetailsModal::ClientDetailsModal(Client * c, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetailsModal)
{
    ui->setupUi(this);
    client = c;
    setupViews();
}

ClientDetailsModal::~ClientDetailsModal() {
    delete ui;
}

void ClientDetailsModal::setupViews() {

}
