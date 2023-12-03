#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginpage.h"
#include "homepage.h"
#include "profilepage.h"
#include "registerpage.h"
#include "core/user.h"

#include <QPushButton>

/**
 * @author Mustafa Yozgyur
 * @author Brent Edington
 * @author ...
*/

MainWindow::MainWindow(QWidget *parent, QString appPath)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set up user to store the user details
    // dynamically declared for global use across the program
    User *user = new User(appPath);

    // Instance login page
    p_LoginPage = new LoginPage(nullptr, this, user);
    ui->LoginPage->layout()->addWidget(p_LoginPage);
    p_LoginPage->show();

    // Instance home page
    p_HomePage = new HomePage(nullptr, this, user);
    ui->HomePage->layout()->addWidget(p_HomePage);
    p_HomePage->show();

    // Instance profile page
    p_ProfilePage = new ProfilePage(nullptr, this, user);
    ui->ProfilePage->layout()->addWidget(p_ProfilePage);
    p_ProfilePage->show();

    // Instance register page
    p_RegisterPage = new RegisterPage(nullptr, this, user);
    ui->RegisterPage->layout()->addWidget(p_RegisterPage);
    p_RegisterPage->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangePage(PageIndex page)
{
    ui->stackedWidget->setCurrentIndex(page);
}
