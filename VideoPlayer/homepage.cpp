#include "homepage.h"
#include "ui_homepage.h"

#include "mainwindow.h"

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

HomePage::HomePage(QWidget *parent, MainWindow* main_window)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::HomePage())
{
    ui->setupUi(this);

    connect(ui->button_Logout, &QPushButton::clicked, this, &HomePage::LogoutButtonClicked);
    connect(ui->button_Profile, &QPushButton::clicked, this, &HomePage::ProfileButtonClicked);
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::LogoutButtonClicked()
{
    // Clear session token and auth token etc...

    // Switch pages
    p_MainWindow->ChangePage(MainWindow::PageIndex::LOGIN_PAGE);
}

void HomePage::ProfileButtonClicked()
{
    // Switch pages
    p_MainWindow->ChangePage(MainWindow::PageIndex::PROFILE_PAGE);
}
