#include "loginpage.h"
#include "ui_loginpage.h"
#include "mainwindow.h"
#include "core/application.h"
#include "homepage.h"

#include <QPushButton>
#include <iostream>
#include <string>
#include <QMessageBox>

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

    // Connect signal of successful login to setup posts in the HomePage
    connect(this, SIGNAL(SuccessfulLogin()), p_MainWindow->GetPointerToHomePage(), SLOT(SetupPostsOnSuccessfulLogin()));
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::LoginButtonClicked()
{
    // Get core
    Core* core = Application::instance()->GetCore();

    // Get strings
    std::string Email = ui->text_Email->text().toStdString();
    std::string Password = ui->text_Password->text().toStdString();

    // Test if login successful
    bool result = core->SubmitLogin(Email, Password);
    cout << result << endl;
    if (result)
    {
        // If login successful
        emit SuccessfulLogin();
        p_MainWindow->ChangePage(MainWindow::PageIndex::HOME_PAGE);
    }
    else
    {
        // Pop up to say password incorrect
        QMessageBox::critical(this, "Login Failed", "Incorrect email or password.");
    }
}

void LoginPage::RegisterButtonClicked()
{
    // Go to register page
    p_MainWindow->ChangePage(MainWindow::PageIndex::REGISTER_PAGE);

    // Setting up posts for respective user
}
