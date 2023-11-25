#include "profilepage.h"
#include "ui_profile.h"

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

ProfilePage::ProfilePage(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::ProfilePage())
{
    ui->setupUi(this);
}

ProfilePage::~ProfilePage()
{
    delete ui;
}

const QPushButton *ProfilePage::GetHomeButton() const
{
    return ui->button_HomePage;
}
