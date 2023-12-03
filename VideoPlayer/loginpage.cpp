#include "loginpage.h"
#include "ui_loginpage.h"
#include "mainwindow.h"

#include <QPushButton>
#include <iostream>

/**
 * @author Mustafa Yozgyur
 * @author Brent Edington
 * @author Muhammad Kashif-Khan
*/

LoginPage::LoginPage(QWidget *parent, MainWindow* main_window)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::LoginPage())
{
    ui->setupUi(this);

    // Connect button
    connect(ui->button_Login, &QPushButton::clicked, this, &LoginPage::LoginButtonClicked);
    connect(ui->button_Register, &QPushButton::clicked, this, &LoginPage::RegisterButtonClicked);
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

void LoginPage::RegisterButtonClicked()
{
    // Go to register page
    p_MainWindow->ChangePage(MainWindow::PageIndex::REGISTER_PAGE);
}
