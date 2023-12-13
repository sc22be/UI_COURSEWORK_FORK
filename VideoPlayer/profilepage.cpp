#include "profilepage.h"
#include "ui_profilepage.h"
#include "mainwindow.h"

/**
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
*/

#include "core/application.h"

ProfilePage::ProfilePage(QWidget *parent, MainWindow* main_window)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::ProfilePage())
{
    ui->setupUi(this);

    // Connect buttons
    connect(ui->button_Back, &QPushButton::clicked, this, &ProfilePage::HomeButtonClicked);
    connect(ui->button_Settings, &QPushButton::clicked, this, &ProfilePage::SettingsButtonClicked);
}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::HomeButtonClicked()
{
    p_MainWindow->ChangePage(MainWindow::PageIndex::HOME_PAGE);
}

void ProfilePage::SettingsButtonClicked()
{
    p_MainWindow->ChangePage(MainWindow::PageIndex::SETTINGS_PAGE);
}

void ProfilePage::OnPageEnter()
{
    Core* core = Application::instance()->GetCore();
    ui->label_Username->setText(core->GetUser()->GetUsername().c_str());
    ui->label_Email->setText(core->GetUser()->GetEmail().c_str());
}
