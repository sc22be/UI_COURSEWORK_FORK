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
        case Register::SUCCESS:
            // If login successful
            p_MainWindow->ChangePage(MainWindow::PageIndex::LOGIN_PAGE);
            break;
        case Register::EMPTY:
            // Fields left blank
            QMessageBox::critical(this, "Register Account Failed", "Please fill in the missing information.");
            break;
        case Register::TOOYOUNG:
            // Pop up to say too young
            QMessageBox::critical(this, "Register Account Failed", "You must be atleast 13 years old to create an account!");
            break;
        case Register::NOTEMAIL:
            QMessageBox::critical(this, "Register Account Failed", "Please enter a valid Email!");
            break;
        case Register::SHORTPASS:
            // Pop up to say pass word needs to be atleast 8 characters
            QMessageBox::critical(this, "Register Account Failed", "Password must be atleast 8 characters long!");
            break;
        case Register::NOUPPER:
            // Pop up to say password needs uppercase
            QMessageBox::critical(this, "Register Account Failed", "Password must contain atleast one uppercase character!");
            break;
        case Register::NOLOWER:
            // Pop up to say password needs lowercase
            QMessageBox::critical(this, "Register Account Failed", "Password must contain atleast one lowercase character!");
            break;
        case Register::NONUM:
            // Pop up to say password needs a number
            QMessageBox::critical(this, "Register Account Failed", "Password must contain atleast one number!");
            break;
        /* TBD
        case Register::NOSYMBOL:
            // Pop up to say password needs lowercase
            QMessageBox::critical(this, "Register Account Failed", "Password must contain atleast one symbol!");
            break;
        */
    }

}

