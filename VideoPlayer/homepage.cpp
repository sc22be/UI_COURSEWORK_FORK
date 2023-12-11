#include "homepage.h"
#include "ui_homepage.h"

#include "mainwindow.h"
#include <iostream>

/**
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
*/

HomePage::HomePage(QWidget *parent, MainWindow* main_window)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::HomePage())
{
    ui->setupUi(this);

    // Muhammad has added the following
    // I WILL TAKE CARE OF THIS LATER
    // User user = new User();
    // tip: get the user by calling:
    // Application::instance()->GetUser();
    // will need to #include "core/application.h"

    // QScrollArea *scrollAreaForPosts = findChild<QScrollArea*>("scrollAreaForPosts");
    // u can use ui->scrollArea to get the ScrollArea btw.

//    if (scrollAreaForPosts)
//    {
//        setupPosts(scrollAreaForPosts, user)
//    }


    // End of addition

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

void HomePage::OnPageEnter()
{
    std::cout << "Homepage enter" << std::endl;
}

//void HomePage::setupPosts()
//{
//    // TODO: retrieve posts by video

//    // TODO: loop through each video and set up each videos layout. store it to a list of layouts
//        // need post metadata

//    // TODO: setup the layouts in date order
//}
