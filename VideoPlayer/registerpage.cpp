#include "registerpage.h"
#include "ui_registerpage.h"
#include "mainwindow.h"

#include <QPushButton>
#include <iostream>
/**
 * @author Brent Edington
 * @author ...
*/

RegisterPage::RegisterPage(QWidget *parent, MainWindow* main_window)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::RegisterPage())
{
    ui->setupUi(this);

    // Connect button
    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterPage::RegisterButtonClicked);
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::RegisterButtonClicked()
{
    // TODO: call Login in Core but we havent done that yet

    // If login successful
    p_MainWindow->ChangePage(MainWindow::PageIndex::LOGIN_PAGE);
}

