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
    QList<QByteArray> dane = line.split('|');
    QString check = dane.takeAt(0);

    if (check == "log")
    {
        QByteArray login = dane.takeAt(0);
        QByteArray password = dane.takeAt(0); //poprzednie wywolanie wyciaga QByteArray i ten staje sie 1
            if (login != "" && password != "")
            {

            }
    }
    else if(check == "reg")
    {
                QString login = dane.takeAt(0);
                if(login != "")
                {
                    QString password = dane.takeAt(0);
                QMessageBox::information(this, tr("Komunikat aplikacji klienckiej"),
                    tr("Użytkownik %1 zarejestrowany pomyślnie!\nHasło: %2")
                                         .arg(login).arg(password));
                }

     }
    else if(check== "send")
    {

    }
    else if(check=="get")
    {

    }

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
void client::showMainWindow()
{
    ui->centralWidget->show();
}
void client::on_Register_clicked()
{
    registerForm = new userRegister(this);

    connect(registerForm, SIGNAL(registerUser(QString)), this, SLOT(getRegisterData(QString)));
    registerForm->show();
}

void client::getRegisterData(QString registerString)
{
    qDebug()<<registerString;
    QByteArray regArray;
    regArray.append(registerString);
    writeData(regArray);
}

void client::on_connectTo_clicked()
{
    connectToServer();
}
