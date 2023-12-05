#include "homepage.h"
#include "ui_homepage.h"
#include "core/application.h"
#include "mainwindow.h"

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
    Application::instance()->GetCore()->GetUser();

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

//void HomePage::SetupPosts()
//{
//    // TODO: retrieve posts by video
//    vector<QLayout>

//    // TODO: loop through each video and set up each videos layout. store it to a list of layouts
//        // need post metadata

//    // TODO: setup the layouts in date order
//}

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
//                    QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
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
