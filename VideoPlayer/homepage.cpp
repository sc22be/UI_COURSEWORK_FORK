#include "homepage.h"
#include "ui_homepage.h"

#include "mainwindow.h"
#include "core/application.h"
#include "core/videodb.h"
#include "core/video/video.h"
#include "core/video/post.h"
#include "core/settings.h"
#include "core/countdown.h"
#include <iostream>
#include <QDebug>
#include <QMessageBox>
#include <QResizeEvent>

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

    // Delete the posts when we change page
    connect(p_MainWindow, SIGNAL(PageChange(MainWindow::PageIndex,MainWindow::PageIndex)), this, SLOT(PageChanged(MainWindow::PageIndex,MainWindow::PageIndex)));

    // Translate
    connect(p_MainWindow, &MainWindow::langChange, this, &HomePage::ChangeLang);
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
    QMessageBox::information(nullptr, tr("Upload video"), tr("This would open a page where you record a video. Pretend that you uploaded a video"));
    ui->sw_Posts->setCurrentIndex(1);
    SetupPostsOnSuccessfulLogin();
    b_UploadedVideo = true;
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

void HomePage::PageChanged(MainWindow::PageIndex from, MainWindow::PageIndex to)
{
    // Make sure we are exiting the page
    if (from != MainWindow::PageIndex::HOME_PAGE)
    {
        return;
    }

    QLayout* layout = ui->w_PostsWidget->layout();

    int count = layout->count();

    // Delete posts
    for (int i = 0; i < count; i++)
    {
        // Set post max size
        QWidget* post = layout->itemAt(0)->widget();

        layout->removeWidget(post);
        delete post;
    }
}

void HomePage::ResizePosts()
{
    int total_height = 0;
    QLayout* layout = ui->w_PostsWidget->layout();
    for (int i = 0; i < layout->count(); i++)
    {
        // Set post max size
        QWidget* post = layout->itemAt(i)->widget();

        post->setMinimumWidth(ui->scrollArea->width() - 50);
        post->setMinimumHeight(ui->scrollArea->height());

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
    // Get core
    Core* core = Application::instance()->GetCore();

    // Display correct username
    ui->label_Username->setText(Application::instance()->GetCore()->GetUser()->GetUsername().c_str());

    ui->label_Timer->show();

    static bool first_time = true;
    if (first_time && core->GetSettings()->shouldNotify)
    {
        QMessageBox::information(this, tr("StaySimple"), tr("Time to record! Post a video to share with your friends!"));
        first_time = false;
    }

    timer.StartCountdown(180); // In seconds

    // Display posts if user uploaded
    if (b_UploadedVideo)
    {
        SetupPostsOnSuccessfulLogin();
    } else
    {
        // Show upload video button
        ui->sw_Posts->setCurrentIndex(0);

    }
}

void HomePage::ChangeLang()
{
    ui->retranslateUi(this);
}
