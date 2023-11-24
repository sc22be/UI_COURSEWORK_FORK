#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::LoginPage())
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

const QPushButton* LoginPage::GetLoginButton() const
{
    return ui->pushButton;
}
