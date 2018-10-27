#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::setResponse(QString cos){
    ui->succesLabel->setText(cos);
}

QString LoginForm::getLogin(){
    return ui->loginInput->text();
}

QString LoginForm::getPassword(){
    return ui->passwordInput->text();
}

void LoginForm::on_closeButton_clicked()
{
   emit closeWindow();
}

void LoginForm::on_loginButton_clicked()
{
    QString registerString = "log|"+this->getLogin()+"|"+this->getPassword()+"|";
    emit loginUser(registerString);
}
