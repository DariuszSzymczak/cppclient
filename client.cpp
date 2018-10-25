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
}

bool client::connectToServer()
{
    blockSize = 0;

    socket->connectToHost(ui->serverName->text(), 1024, QIODevice::ReadWrite);
    if (socket->state() == QAbstractSocket::ConnectedState) {
        QMessageBox::information(this, tr("Komunikat aplikacji klienckiej"),
            tr("Połączono "));
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
qint32 ArrayToInt(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}
void client::readFortune()
{


 QByteArray line = socket->readLine();
 qDebug() << "moze"+line;
//    QByteArray* buffering = new QByteArray();
//    qint32* a = new qint32(0);
//    buffers.insert(socket, buffering);
//    sizes.insert(socket, a);
//    QByteArray* buffer = buffers.value(socket);
//    buffer->append(socket->readAll());
//    qint32* s = sizes.value(socket);
//    qint32 size = *s;
//    qDebug()<< buffer;
//    while (socket->bytesAvailable() > 0) {

//        while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) //While can process data, process it
//        {
//            qDebug()<< "1while";
//            if (size == 0 && buffer->size() >= 4) //jesli rozmiar dotarl zapisz
//            {
//                size = ArrayToInt(buffer->mid(0, 4));
//                *s = size;
//                buffer->remove(0, 4);
//                qDebug()<< "1if";
//            }
//            if (size > 0 && buffer->size() >= size) // jezeli doszly cale wyemiutuj
//            {
//                QByteArray data = buffer->mid(0, size);
//                buffer->remove(0, size);
//                size = 0;
//                *s = size;

//                qDebug() << data;

//            }
//        }}
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

void client::on_downloadData_clicked()
{
    connectToServer();
}

void client::on_Register_clicked()
{
    QString a = "log|anal|iza|to powinno byc cale";
    QByteArray data;
    data.append(a);
    writeData(data);
}
