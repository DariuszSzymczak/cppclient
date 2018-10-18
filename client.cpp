#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client),
    socket(new QLocalSocket(this))
{
    ui->setupUi(this);
    in.setDevice(socket);
    in.setVersion(QDataStream::Qt_5_10);

    //przechwytywanie błędów
    connect(socket, QOverload<QLocalSocket::LocalSocketError>::of(&QLocalSocket::error),
                this, &client::displayError); // Nie ruszać

    connect(ui->downloadData, &QPushButton::clicked,this, &client::connectSrv); //Pobiera dane
    connect(socket, &QLocalSocket::readyRead, this, &client::getData); //Przetwarza jeśli są gotowe
}


void client::connectSrv()
{
    blockSize = 0;
    socket->abort();
    socket->connectToServer(ui->serverName->text());
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        QMessageBox::information(this, tr("Komunikat aplikacji klienckiej"),
                                 tr("Połączono "));
    }

}
//  Przetwarzanie danych otrzymanych od serwera
void client::getData()
{
    if(blockSize == 0)
    {
        if(socket->bytesAvailable() < (int)sizeof (quint32))
        {
            return;
        }

        in >> blockSize;

        if(socket->bytesAvailable() < blockSize || in.atEnd())
            return;

        QString newDane;
        in >> newDane;

        currentData = newDane;
        ui->label1->setText(currentData);
    }
}

//------------------------------------------------------
//Przechwytywanie wszystkich możliwych rodzajów błędów.
//Podpiętę pod funkcję connect w client::client.
//Nie kasować

void client::displayError(QLocalSocket::LocalSocketError socketError)
{
    switch (socketError) {
        case QLocalSocket::ServerNotFoundError:
            QMessageBox::information(this, tr("Komunikat aplikacji klienckiej"),
                                     tr("Nie znaleziono serwera. Upewnij się, czy serwer działa "
                                        "oraz czy jego nazwa została podana poprawnie. "));
            break;
        case QLocalSocket::ConnectionRefusedError:
            QMessageBox::information(this, tr("Komunikat aplikacji klienckiej"),
                                     tr("Połączenie zostało odrzucone. "
                                        "Upewnij się, czy serwer działa "
                                        "oraz czy jego nazwa została podana poprawnie."));
            break;
        case QLocalSocket::PeerClosedError:
            break;
        default:
            QMessageBox::information(this, tr("Komunikat aplikacji klienckiej"),
                                     tr("Wystąpił błąd: %1.")
                                     .arg(socket->errorString()));
        }
}
//-----------------------------------------------------
client::~client()
{
    delete ui;
}
