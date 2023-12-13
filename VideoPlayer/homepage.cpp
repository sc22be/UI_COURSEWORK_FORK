#include "homepage.h"
#include "ui_homepage.h"

#include "mainwindow.h"
#include "core/application.h"
#include "core/videodb.h"
#include "core/video/video.h"
#include "core/video/post.h"
#include <iostream>
#include "core/countdown.h"
#include <QDebug>
#include <QMessageBox>
#include "core/application.h"

/**
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
 * @author Brent Edington
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
    // Connect to profile page
    connect(ui->button_Profile, &QPushButton::clicked, this, &HomePage::ProfileButtonClicked);

    // Display posts
    SetupPostsOnSuccessfulLogin();
    // Label for timer
    QLabel* timerLabel = ui->label_Timer;
    ui->label_Timer->hide();
    // Change text when signal given
    QObject::connect(&timer, &countdown::timerChanged, [timerLabel](const QString& text)
    {
        timerLabel->setText(text);
    });
    // Change style when signal given
    QObject::connect(&timer, &countdown::timerColorChange, [timerLabel](const QString& style)
    {
        timerLabel->setStyleSheet(style);
    });
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
    ui->label_Username->setText(Application::instance()->GetCore()->GetUser()->GetUsername().c_str());

    Core* core = Application::instance()->GetCore();

//void HomePage::setupPosts()
//{
//    // TODO: retrieve posts by video

    // Retrieve videos
    std::vector<Video> videos = core->GetVideoDB()->GetVideos();

    // Add all the videos to the scroll view
    // for (auto& video : videos)
    // {
    //     Post* post = new Post(nullptr, core->GetUser(), &video);
    //     ui->w_PostsWidget->layout()->addWidget(post);
    // }

    // FOR TESTING, DISPLAYING 1 VIDEO ONLY
    Post* post = new Post(nullptr, core->GetUser(), &videos[3]);
    ui->w_PostsWidget->layout()->addWidget(post);
}

void HomePage::OnPageEnter()
{
    std::cout << "Homepage enter" << std::endl;

    ui->label_Timer->show();
    QMessageBox::information(this, "StaySimple", "Time to record! Post a video to share with your friends!");
    timer.StartCountdown(180); // In seconds
}
