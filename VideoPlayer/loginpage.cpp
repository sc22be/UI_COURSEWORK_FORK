#include "loginpage.h"
#include "ui_loginpage.h"
#include "mainwindow.h"

#include <QPushButton>

#include <iostream>

LoginPage::LoginPage(QWidget *parent, MainWindow* main_window)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::LoginPage())
{
    ui->setupUi(this);

    // Connect button
    connect(ui->button_Login, &QPushButton::clicked, this, &LoginPage::LoginButtonClicked);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::LoginButtonClicked()
{
    // TODO: call Login in Core but we havent done that yet lol

    // If login successful
    p_MainWindow->ChangePage(MainWindow::PageIndex::HOME_PAGE);
}
