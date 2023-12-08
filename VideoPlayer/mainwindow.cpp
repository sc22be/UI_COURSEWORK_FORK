#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginpage.h"
#include "homepage.h"
#include "profilepage.h"
#include "registerpage.h"

#include <QPushButton>

/**
 * @author Mustafa Yozgyur
 * @author Brent Edington
 * @author ...
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Instance home page
    p_HomePage = new HomePage(nullptr, this);
    ui->HomePage->layout()->addWidget(p_HomePage);
    p_HomePage->show();

    // Instance login page
    p_LoginPage = new LoginPage(nullptr, this);
    ui->LoginPage->layout()->addWidget(p_LoginPage);
    p_LoginPage->show();

    // Instance profile page
    p_ProfilePage = new ProfilePage(nullptr, this);
    ui->ProfilePage->layout()->addWidget(p_ProfilePage);
    p_ProfilePage->show();

    // Instance register page
    p_RegisterPage = new RegisterPage(nullptr, this);
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
