#include "homepage.h"
#include "ui_homepage.h"

#include "mainwindow.h"

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

HomePage::HomePage(QWidget *parent, MainWindow* main_window)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::HomePage())
{
    ui->setupUi(this);

    connect(ui->button_Profile, &QPushButton::clicked, this, &HomePage::ProfileButtonClicked);
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::ProfileButtonClicked()
{
    // Switch pages
    p_MainWindow->ChangePage(MainWindow::PageIndex::PROFILE_PAGE);
}
