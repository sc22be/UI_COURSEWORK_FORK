#include "homepage.h"
#include "ui_homepage.h"

#include "mainwindow.h"
#include "core/application.h"
#include "core/videodb.h"
#include "core/video/video.h"
#include "core/video/post.h"

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

    // get the user by calling:
//    User *user = Application::instance()->GetCore()->GetUser();

    // Begin to set up posts
//    SetupPostsOnSuccessfulLogin();

    // u can use ui->scrollArea to get the ScrollArea btw.
//     ui->scrollAreaForPosts.


//    if (scrollAreaForPosts)
//    {
//        setupPosts(scrollAreaForPosts, user)
//    }


    // End of addition

    connect(ui->button_Profile, &QPushButton::clicked, this, &HomePage::ProfileButtonClicked);

    // Display posts
    SetupPostsOnSuccessfulLogin();
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

void HomePage::SetupPostsOnSuccessfulLogin()
{
    // Retrieve videos
    std::vector<Video> videos = Application::instance()->GetCore()->GetVideoDB()->GetVideos();

    // Add all the videos to the scroll view
    for (auto video : videos)
    {
        Post* post = new Post();
        ui->sa_Posts->layout()->addWidget(post);
    }
}
