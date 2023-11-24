#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginpage.h"
#include "homepage.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Instance login page
    p_LoginPage = new LoginPage();
    ui->LoginPage->layout()->addWidget(p_LoginPage);
    p_LoginPage->show();

    // Instance home page
    p_HomePage = new HomePage();
    ui->HomePage->layout()->addWidget(p_HomePage);
    p_HomePage->show();

    // Connect Buttons
    connect(p_LoginPage->GetLoginButton(), &QPushButton::clicked, this, &MainWindow::LoginButtonClicked);
    connect(p_HomePage->GetLogoutButton(), &QPushButton::clicked, this, &MainWindow::LogoutButtonClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoginButtonClicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::LogoutButtonClicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

