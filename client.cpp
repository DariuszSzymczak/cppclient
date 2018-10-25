#include "client.h"
#include "ui_client.h"
static inline qint32 ArrayToInt(QByteArray source);

client::client(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readFortune()));
    ui->logIn->setDisabled(1);
    ui->Register->setDisabled(1);
}

bool client::connectToServer()
{
    socket->connectToHost(ui->serverName->text(), ui->server_port->text().toInt(), QIODevice::ReadWrite);
    if (socket->state() == QAbstractSocket::ConnectedState) {
        QMessageBox::information(this, tr("Komunikat aplikacji klienckiej"),
            tr("Połączono "));
        ui->Register->setEnabled(1);
        ui->logIn->setEnabled(1);
    }
    return socket->waitForConnected();
}
QByteArray IntToArray(qint32 source) //Use qint32 to ensure that the number have 4 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

void client::readFortune()
{


 QByteArray line = socket->readLine();
 qDebug() << line;

}
bool client::writeData(QByteArray data)
{

    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(IntToArray(data.size())); //write size of data
        socket->write(data); //write the data itself
        return socket->waitForBytesWritten();
    }
    else
        return false;
}

//-----------------------------------------------------
client::~client()
{
    delete ui;
}

void client::on_Register_clicked()
{
    QString a = "log|anal|iza|to powinno byc cale";
    QByteArray data;
    data.append(a);
    writeData(data);
}

void client::on_connectToServer_clicked()
{
       connectToServer();
}
