#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

QString LoginForm::getLogin(){
    return ui->loginInput->text();
}

QString LoginForm::getPassword(){
    return ui->passwordInput->text();
}

void LoginForm::on_closeButton_clicked()
{

   this->close();
}

void LoginForm::on_loginButton_clicked()
{
    QString registerString = "log|"+this->getLogin()+"|"+this->getPassword()+"|";
    emit loginUser(registerString);
}
