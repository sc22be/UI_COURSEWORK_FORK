#include "homepage.h"
#include "ui_homepage.h"

#include "mainwindow.h"
#include "core/user.h"

/**
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
*/

HomePage::HomePage(QWidget *parent, MainWindow* main_window, User *user)
    : QWidget{parent}
    , p_MainWindow(main_window)
    , ui(new Ui::HomePage())
{
    ui->setupUi(this);

    // Muhammad has added the following
    //  I WILL TAKE CARE OF THIS LATER
//    User user = new User();

//    QScrollArea *scrollAreaForPosts = findChild<QScrollArea*>("scrollAreaForPosts");

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

//void HomePage::setupPosts()
//{
//    // TODO: retrieve posts by video

//    // TODO: loop through each video and set up each videos layout. store it to a list of layouts
//        // need post metadata

//    // TODO: setup the layouts in date order
//}
