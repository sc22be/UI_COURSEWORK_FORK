#include <iostream>
#include <QDir>
#include <QDirIterator>
#include <QUrl>

#include "homepage.h"
#include "ui_homepage.h"
#include "core/application.h"
#include "mainwindow.h"


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

    // begin to set up posts
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
    VideosFromDirectory = RetrieveVideosFromDirectory();

    // TODO: retrieve videos
//    vector<string> VideosLocation = RetrieveVideosFromDirectory();

    // TODO: loop through each video and set up each videos layout. store it to a list of layouts
        // need post metadata

    // TODO: setup the layouts in date order
}

vector<HomePage::Video> HomePage::RetrieveVideosFromDirectory()
{
    // TODO (maybe): implement the situation where the path was entered by the user

    // find path to videos
    QString AppDirPath = Application::instance()->applicationDirPath();
    // Apparently calling this function leads to ".../build-VideoPlayer-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug"
    // So we will navigate out from this directory until an assets folder can be found. (this was pre-defined by the group)

    //  TEST LINE
    cout << AppDirPath.toStdString() << endl;

    // Call QDir to navigate directories
    QDir AppDir(AppDirPath);
    // Name of folder we want to navigate to#
    QString AssetsSubDirName = "assets";

    // Repeatidly cd out of the current directory until the assets folder is found
    while (!AppDir.cd(AssetsSubDirName))
    {
        AppDir.cdUp();
    }

    AppDir.cd("videos");
    cout << AppDir.absolutePath().toStdString() << endl;

    // Find all videos in the videos directory and store it to a vector to return
    // MAY NEED TO MAKE A SUBCLASS FOR STORING VIDEO
    vector<HomePage::Video> DataForVideos;

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
            DataForVideos.push_back(HomePage::Video(Url, CreationDateTime));
        }
    }

    return DataForVideos;
}

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
