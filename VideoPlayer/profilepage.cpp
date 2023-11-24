#include "profilepage.h"
#include "ui_profile.h"
#include "mainwindow.h"

ProfilePage::ProfilePage(QWidget *parent, MainWindow* main_window)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::ProfilePage())
{
    ui->setupUi(this);

    connect(ui->button_HomePage, &QPushButton::clicked, this, &ProfilePage::HomeButtonClicked);
}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::HomeButtonClicked()
{
    p_MainWindow->ChangePage(MainWindow::PageIndex::HOME_PAGE);
}
