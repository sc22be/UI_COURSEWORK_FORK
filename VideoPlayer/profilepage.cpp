#include "profilepage.h"
#include "ui_profilepage.h"
#include "mainwindow.h"
#include "core/user.h"

/**
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
*/

ProfilePage::ProfilePage(QWidget *parent, MainWindow* main_window, User *user)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::ProfilePage())
{
    ui->setupUi(this);

    connect(ui->backButton, &QPushButton::clicked, this, &ProfilePage::HomeButtonClicked);
}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::HomeButtonClicked()
{
    p_MainWindow->ChangePage(MainWindow::PageIndex::HOME_PAGE);
}
