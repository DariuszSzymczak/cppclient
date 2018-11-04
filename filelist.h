#ifndef FILELIST_H
#define FILELIST_H

#include <QWidget>


namespace Ui {
class FileList;
}

class FileList : public QWidget
{
    Q_OBJECT

public:
    explicit FileList(QWidget *parent = nullptr);
    ~FileList();
    void setLogin(QString logData);
    void updateAll(QList<QByteArray>);
    void showError();
    void showSuccess();
    void showDeleted();
private slots:
    void on_logoutButton_clicked();
    void on_addFileButton_clicked();

    void on_downloadButton_clicked();

    void on_delButton_clicked();

signals:
    void getFile(QByteArray);
    void sendFile(QByteArray);
    void delFile(QByteArray);
private:
    QString login;
    Ui::FileList *ui;
};

#endif // FILELIST_H
