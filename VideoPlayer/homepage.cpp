#include <iostream>
#include <QDir>
#include <QDirIterator>
#include <QUrl>
#include <QVideoWidget>

#include "homepage.h"
#include "ui_homepage.h"
#include "core/application.h"
#include "mainwindow.h"

// This is a variable used to indicate how many videos and users there are meant to be
// THIS IS NOT TO INDICATE THE FINAL DESIGN. DEMONSTRATION PURPOSES ONLY
#define SET_POSTS 1

using namespace std;



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
    // Retrieve user class
    User *p_User = Application::instance()->GetCore()->GetUser();

    // Retrieve videos
    VideosFromDirectory = RetrieveVideosFromDirectory();

    // Set up layout to store videos to

    // Set up a label to indicate no videos to show
    QLabel *NoVideosToDisplayLabel;

    // TODO: loop through each video and set up each videos layout. store it to a list of layouts

    // Check statements if:
    // The user has no friends
    if (VideosFromDirectory.empty() && p_User->GetFriends().empty())
    {
        NoVideosToDisplayLabel = new QLabel("<h3>You have not added any friends yet. Add some friends <h3>");
    }
    // The users friends has no videos to display
    else if (VideosFromDirectory.empty())
    {
        NoVideosToDisplayLabel = new QLabel("<h3>Your friends have not uploaded their StaySimple videos. Check back Later</h3>");
    }
    // There are videos and friends to display
    else
    {
        // cout << "here" << endl;
        PostWidgets = SetupPostWidgetsAndLayout(VideosFromDirectory);
        ui->scrollAreaForPosts->setWidget(PostWidgets[0]);
//        ui->scrollAreaForPosts->show();

    }

//    update();


        // need post metadata

    // TODO: setup the layouts in date order
}

vector<HomePage::Video*> HomePage::RetrieveVideosFromDirectory()
{
    // TODO (maybe): implement the situation where the path was entered by the user
    // this may need to be taken care of in the login page

    // find path to videos
    QString AppDirPath = Application::instance()->applicationDirPath();
    // Apparently calling this function leads to ".../build-VideoPlayer-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug"
    // So we will navigate out from this directory until an assets folder can be found. (this was pre-defined by the group)

    //  TEST LINE
    // cout << AppDirPath.toStdString() << endl;

    // Call QDir to navigate directories
    QDir AppDir(AppDirPath);
    // Name of folder we want to navigate to#
    QString AssetsSubDirName = "assets";

    // Repeatidly cd out of the current directory until the assets folder is found
    while (!AppDir.cd(AssetsSubDirName))
    {
        AppDir.cdUp();
    }

    // Enter the videos folder inside the assets folder
    AppDir.cd("videos");

    // TEST LINE
    // cout << AppDir.absolutePath().toStdString() << endl;

    // Find all videos in the videos directory and store it to a vector to return
    // MAY NEED TO MAKE A SUBCLASS FOR STORING VIDEO
    vector<HomePage::Video*> DataForVideos;

    // We are going to look through the directory for any videos
    // This has been adapted from "the.pro" and its code
    // We only want the videos (FOR NOW)
    QDirIterator it(AppDir);

    while (it.hasNext())
    { // for all files

        QString f = it.next();

        if (f.contains("."))

#if defined(_WIN32)
        if (f.contains(".wmv"))
        { // windows
#else
        if (f.contains(".mp4") || f.contains("MOV"))
        { // mac/linux
#endif
            QUrl* Url = new QUrl(QUrl::fromLocalFile(f)); // convert the file location to a generic url
            // Obtain file path to get DateTime metadata
            QString FilePath = Url->toLocalFile();
            QFileInfo FileInfo(FilePath);
            QDateTime CreationDateTime = FileInfo.birthTime();

            // Save video URL and DateTime to list of Videos
            DataForVideos.push_back(new HomePage::Video(Url, CreationDateTime));
            // cout << DataForVideos[0]->GetCreationTimeToString().toStdString() << endl;
        }
    }

    return DataForVideos;
}

vector<PostWidget*> HomePage::SetupPostWidgetsAndLayout(vector<HomePage::Video*> DataForVideos)
{
    // Set Posts list
    vector<PostWidget*> Posts;
    PostWidget *Post;

    // Get user information and friends
    User *p_User = Application::instance()->GetCore()->GetUser();
    vector<string> UserFriends = p_User->GetFriends();

    // Make 1 Post from the user and videos information
    for (int NumPosts = 0; NumPosts < SET_POSTS; NumPosts++)
    {
        Posts.push_back(new PostWidget(UserFriends[NumPosts], DataForVideos[NumPosts]));
    }

    return Posts;
}


//SOME FUNCTION HERE??????
//order by time function, asc order


// Constructor for the PostWidget class
PostWidget::PostWidget(string name, HomePage::Video *videoData)
{
    // Create widgets
    CreateWidgets(name, videoData);

    // Arrange widgets
    ArrangeWidgets();

    // Make connections
    MakeConnections();
}

void PostWidget::CreateWidgets(string name, HomePage::Video *videoData)
{
    // Set up labels
    m_NameLabel = new QLabel(QString::fromStdString(name));
    m_TimeLabel = new QLabel(videoData->GetCreationTimeToString());

    // Set up media player and video
//    QPushButton *m_ClickablePlayerForPlayPause = new QPushButton();           // EXPERIMENTAL, CONSIDERING HAVING TO CLICK ON THE VIDEO TO PAUSE/PLAY IT, SIMILAR TO YOUTUBE SHORTS KINDA
    m_MediaPlayer = new QMediaPlayer;
    m_Video = new QVideoWidget(this);
    m_MediaPlayer->setMedia(*videoData->GetVideoUrl());
    m_MediaPlayer->setVideoOutput(m_Video);
//    m_Video->setAspectRatioMode(Qt::IgnoreAspectRatio);

    qint64 duration = m_MediaPlayer->duration();
    m_MediaPlayer->play();

    // Set up scroll bar for the video player
    m_SliderForVideoSeeking = new QSlider(Qt::Horizontal, this);
    m_SliderForVideoSeeking->setRange(0, duration);

    // Set up like and comments button
    m_LikeButton = new QPushButton();
    m_LikeButton->setIcon(QIcon(":/assets/button_images/likeButtonOff.jpg"));
    m_LikeButton->setCheckable(false);
    m_CommentsButton = new QPushButton();
    m_CommentsButton->setIcon(QIcon(":/assets/button_images/commentsButton.jpg"));
}

void PostWidget::ArrangeWidgets()
{
    // Arrange friend information and time taken to the top of the post
    m_UserInformationLayout = new QHBoxLayout();
    m_UserInformationLayout->addWidget(m_NameLabel);
    m_UserInformationLayout->addStretch(1);
    m_UserInformationLayout->addWidget(m_TimeLabel);

    // Arrange video player and slider to the middle of the post
    m_VideoPlayerLayout = new QVBoxLayout();
    m_VideoPlayerLayout->addWidget(m_Video);
    m_VideoPlayerLayout->addWidget(m_SliderForVideoSeeking);

    // Arrange like and comment buttons to the bottom of the post
    m_LikeAndCommentLayout = new QHBoxLayout();
    m_LikeAndCommentLayout->addWidget(m_LikeButton);
    m_LikeAndCommentLayout->addWidget(m_CommentsButton);

    m_MainLayout = new QVBoxLayout();
    m_MainLayout->addLayout(m_UserInformationLayout);
    m_MainLayout->addLayout(m_VideoPlayerLayout);
    m_MainLayout->addLayout(m_LikeAndCommentLayout);

    setLayout(m_MainLayout);
}

void PostWidget::MakeConnections()
{
    // Connect slider to media player and vice versa
    connect(m_SliderForVideoSeeking, SIGNAL(valueChanged(int)), this, SLOT(SetPosition(int)));
    connect(m_MediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(UpdateDuration(qint64)));
    connect(m_MediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(UpdatePosition(qint64)));

    // Connect like button
    connect(m_LikeButton, SIGNAL(clicked()), this, SLOT(ChangeLikeButtonStatus()));
}

void PostWidget::SetPosition(int position)
{
    m_MediaPlayer->setPosition(static_cast<qint64> (position));
    m_MediaPlayer->play();
}

void PostWidget::UpdateDuration(qint64 duration)
{
    m_SliderForVideoSeeking->setMaximum(static_cast<int>(duration));
}

void PostWidget::UpdatePosition(qint64 position)
{
    m_SliderForVideoSeeking->setValue(static_cast<int>(position));
}

void PostWidget::ChangeLikeButtonStatus()
{
    if (!m_LikeButton->isChecked())
    {
        m_LikeButton->setIcon(QIcon(":/assets/button_images/likeButtonOn.jpg"));
        m_LikeButton->setCheckable(true);
//        update();
    }
    else
    {
        // cout << "herrr2" << endl;
        m_LikeButton->setIcon(QIcon(":/assets/button_images/likeButtonOff.jpg"));
        m_LikeButton->setCheckable(false);
        update();
    }
}


//void HomePage::PostWidget::

//// read in videos and thumbnails to this directory
//std::vector<TheButtonInfo> getInfoIn (std::string loc) {

//    std::vector<TheButtonInfo> out =  std::vector<TheButtonInfo>();
//    QDir dir(QString::fromStdString(loc) );
//    QDirIterator it(dir);

//    while (it.hasNext()) { // for all files

//        QString f = it.next();

//        if (f.contains("."))

//#if defined(_WIN32)
//        if (f.contains(".wmv"))  { // windows
//#else
//        if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
//#endif

//            QString thumb = f.left( f .length() - 4) +".png";
//            if (QFile(thumb).exists()) { // if a png thumbnail exists
//                QImageReader *imageReader = new QImageReader(thumb);
//                QImage sprite = imageReader->read(); // read the thumbnail
//                if (!sprite.isNull()) {
//                    QIcon* ico = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
//
//                    out . push_back(TheButtonInfo( url , ico  ) ); // add to the output list
//                }
//                else
//                    qDebug() << "warning: skipping video because I couldn't process thumbnail " << thumb << endl;
//            }
//            else
//                qDebug() << "warning: skipping video because I couldn't find thumbnail " << thumb << endl;
//        }
//    }

//    return out;
//}
