#include "userregister.h"
#include "ui_userregister.h"

userRegister::userRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userRegister)
{
    ui->setupUi(this);

}

userRegister::~userRegister()
{
    delete ui;
}

void userRegister::on_pushButton_2_clicked()
{
    this->close();
}

void userRegister::on_pushButton_clicked()
{
    QString registerString = "reg|"+ui->userLogin->text()+"|"+ui->userPassword->text()+"|";
    emit registerUser(registerString);
    this->close();
}
