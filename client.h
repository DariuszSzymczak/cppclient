#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtNetwork>
#include "userregister.h"
namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
    bool connectToServer();
    void displayError(QLocalSocket::LocalSocketError);
    bool writeData(QByteArray);
    void showMainWindow();
private slots:
        void readFortune();
        void on_Register_clicked();
        void getRegisterData(QString);
        void on_connectTo_clicked();

private:
    Ui::client *ui;
    userRegister *registerForm;
    QTcpSocket  *socket;
};

#endif // CLIENT_H
