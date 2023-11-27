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
    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterPage::registerButtonClicked);
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::registerButtonClicked()
{
    // TODO: call Login in Core but we havent done that yet lol

    // If login successful
    p_MainWindow->ChangePage(MainWindow::PageIndex::HOME_PAGE);
}

