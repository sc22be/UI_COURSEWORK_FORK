#include "registerpage.h"
#include "ui_registerpage.h"
#include "mainwindow.h"
#include "core/application.h"

#include <QPushButton>
#include <QMessageBox>
#include <iostream>
#include <QDebug>

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

    // Set default date
    QDate today = QDate::currentDate();
    QDate modTodaysDate = today.addYears(-13);
    ui->date_Birthday->setDate(modTodaysDate);
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::RegisterButtonClicked()
{
    // Get core
    Core* core = Application::instance()->GetCore();

    // Get input
    std::string Username = ui->text_Username->text().toStdString();
    std::string Email = ui->text_Email->text().toStdString();
    std::string Password = ui->text_Password->text().toStdString();
    QDateTime Birthday = ui->date_Birthday->dateTime();

    // Test if register was successful
    int result = core->RegisterAccount(Username, Password, Email, Birthday);
    switch (result)
    {
        case 0:
            // If login successful
            p_MainWindow->ChangePage(MainWindow::PageIndex::LOGIN_PAGE);
            break;
        case -1:
            // Fields left blank
            QMessageBox::critical(this, "Register Account Failed", "Please fill in the missing information.");
            break;
        case 1:
            // Pop up to say too young
            QMessageBox::critical(this, "Register Account Failed", "You must be atleast 13 years old to create an account!");
            break;
        case 2:
            // Pop up to say pass word needs to be atleast 8 characters
            QMessageBox::critical(this, "Register Account Failed", "Password must be atleast 8 characters long!");
            break;
        case 3:
            // Pop up to say password needs uppercase
            QMessageBox::critical(this, "Register Account Failed", "Password must contain atleast one uppercase character!");
            break;
        case 4:
            // Pop up to say password needs lowercase
            QMessageBox::critical(this, "Register Account Failed", "Password must contain atleast one lowercase character!");
            break;
        case 5:
            // Pop up to say password needs a number
            QMessageBox::critical(this, "Register Account Failed", "Password must contain atleast one number!");
            break;
        /* TBD
        case 6:
            // Pop up to say password needs lowercase
            QMessageBox::critical(this, "Register Account Failed", "Password must contain atleast one symbol!");
            break;
        */
    }

}

