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
#include <QResizeEvent>
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

    // Connect to profile page
    connect(ui->button_Profile, &QPushButton::clicked, this, &HomePage::ProfileButtonClicked);

    // Connect upload video button
    connect(ui->button_UploadVideo, &QPushButton::clicked, this, &HomePage::UploadButtonClicked);

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

void HomePage::UploadButtonClicked()
{
    // for now, just display videos straight away

    QMessageBox::information(nullptr, "Upload video", "This would open a page where you record a video. Pretend that you uploaded a video");

    ui->sw_Posts->setCurrentIndex(1);
    SetupPostsOnSuccessfulLogin();
}

void HomePage::SetupPostsOnSuccessfulLogin()
{
    std::cout << "Creating video players" << std::endl;

    Core* core = Application::instance()->GetCore();

    // Retrieve videos
    std::vector<Video> videos = core->GetVideoDB()->GetVideos();

    // Get friends list
    auto frens = core->GetUser()->GetFriends();
    int size = frens.size();

    // Add all the videos to the scroll view
    int i = 0;
    for (auto& video : videos)
    {
        Post* post = new Post(nullptr, frens[i % size], &video);
        ui->w_PostsWidget->layout()->addWidget(post);
        post->show();

        i++;
    }

    // Make the posts correct size
    ResizePosts();
}

void HomePage::ResizePosts()
{
    int total_height = 0;
    QLayout* layout = ui->w_PostsWidget->layout();
    for (int i = 0; i < layout->count(); i++)
    {
        // Set post max size
        QWidget* post = layout->itemAt(i)->widget();

        post->setMaximumWidth(ui->scrollArea->width() - 50);
        post->setMaximumHeight(ui->scrollArea->height());

        total_height += post->height();
    }

    // Resize posts' parent widget to get scroll working
    ui->w_PostsWidget->resize(ui->w_Videos->width(), total_height);
}

void HomePage::resizeEvent(QResizeEvent *e)
{
    ResizePosts();
}

void HomePage::OnPageEnter()
{
    std::cout << "Homepage enter" << std::endl;

    // Display correct username
    ui->label_Username->setText(Application::instance()->GetCore()->GetUser()->GetUsername().c_str());

    ui->label_Timer->show();
    QMessageBox::information(this, "StaySimple", "Time to record! Post a video to share with your friends!");
    timer.StartCountdown(180); // In seconds
}
