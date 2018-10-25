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
    bool connectToServer();
    void displayError(QLocalSocket::LocalSocketError);
    bool writeData(QByteArray);

private slots:
    void on_downloadData_clicked();

        void readFortune();
        void on_Register_clicked();

private:
    Ui::client *ui;
    QTcpSocket  *socket;
    QDataStream in;
    quint32 blockSize;
    QString currentFortune;
    QHash<QTcpSocket*, QByteArray*> buffers; //bufor do przetrzymywania danych az dojda cale
    QHash<QTcpSocket*, qint32*> sizes;
      QNetworkSession *networkSession = nullptr;
};

#endif // CLIENT_H
