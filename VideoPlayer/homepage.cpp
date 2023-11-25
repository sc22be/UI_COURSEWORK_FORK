#include "homepage.h"
#include "ui_homepage.h"

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

HomePage::HomePage(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::HomePage())
{
    ui->setupUi(this);
}

HomePage::~HomePage()
{
    delete ui;
}

const QPushButton *HomePage::GetLogoutButton() const
{
    return ui->button_Logout;
}

const QPushButton *HomePage::GetProfileButton() const
{
    return ui->button_Profile;
}
