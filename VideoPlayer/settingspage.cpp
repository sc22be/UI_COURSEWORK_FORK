#include "settingspage.h"
#include "ui_settingspage.h"

SettingsPage::SettingsPage(QWidget *parent, MainWindow* window) :
    QWidget(parent),
    ui(new Ui::SettingsPage),
    p_MainWindow(window)
{
    ui->setupUi(this);
}

SettingsPage::~SettingsPage()
{
    delete ui;
}

void SettingsPage::OnPageEnter()
{

}
