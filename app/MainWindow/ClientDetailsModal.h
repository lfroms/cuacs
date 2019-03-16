#ifndef CLIENTDETAILSMODAL_H
#define CLIENTDETAILSMODAL_H

#include <QDialog>
#include <Models/Client/Client.h>

namespace Ui {
class ClientDetailsModal;
}

class ClientDetailsModal : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDetailsModal(Client * c, QWidget *parent = nullptr);
    ~ClientDetailsModal();

private:
    Ui::ClientDetailsModal *ui;
    Client* client;

    void setupViews();
};

#endif // CLIENTDETAILSMODAL_H
