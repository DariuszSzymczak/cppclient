#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtNetwork>

namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();
    void connectSrv();
    void displayError(QLocalSocket::LocalSocketError socketError);
    void getData();

private:
    Ui::client *ui;
    QLocalSocket *socket;
    QDataStream in;
    quint32 blockSize;

    QString currentData;
};

#endif // CLIENT_H
