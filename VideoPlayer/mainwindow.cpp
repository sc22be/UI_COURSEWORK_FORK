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

    // Instance login page
    p_LoginPage = new LoginPage(nullptr, this);
    ui->LoginPage->layout()->addWidget(p_LoginPage);
    p_LoginPage->show();

    // Instance home page
    p_HomePage = new HomePage(nullptr, this);
    ui->HomePage->layout()->addWidget(p_HomePage);
    p_HomePage->show();

    // Instance profile page
    p_ProfilePage = new ProfilePage(nullptr, this);
    ui->ProfilePage->layout()->addWidget(p_ProfilePage);
    p_ProfilePage->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangePage(PageIndex page)
{
    ui->stackedWidget->setCurrentIndex(page);
}
