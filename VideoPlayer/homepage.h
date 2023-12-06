#ifndef HOMEPAGE_H
#define HOMEPAGE_H

//#include "qlayout.h"
// Muhammad: ^^ i dont know what is up with this include here
#include <QWidget>
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>
#include <QDateTime>


//#include "core/user.h"

using namespace std;

class QPushButton;
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE

class HomePage : public QWidget
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    ~HomePage();

public slots:
    void ProfileButtonClicked();
    void SetupPostsOnSuccessfulLogin();


private:
    class PostWidget: public QWidget
    {
    public:
        PostWidget(std::string name, std::string timePosted, std::string videoUrl);

    private:
        // @MUSTAFA, THIS IS A SIMPLE IMPLEMENTATION OF A VIDEO CLASS. IF YOU WANT TO PULL THIS TO USE INSIDE THE VIDEO_DB, YOU MIGHT BE ABLE TO USE IT
        // i dont know what you have planned for that class, nor i know how to actually implement it the way you are thinking
        // THE ENTIRE CLASS HAS BEEN INLINED TO THE POST_WIDGET CLASS. THERE IS NO .CPP CLASS FILE FOR THIS

        class Video
        {
        public:
            // Constructor
            Video(QUrl *Url, QDateTime DateTime) { m_VideoUrl = Url; m_CreationDateTime = DateTime;}

            // Getter methods
            QUrl *GetVideoUrl() { return m_VideoUrl; }
            QTime GetCreationTime() { return m_CreationDateTime.time(); }
            QDate GetCreationDate() { return m_CreationDateTime.date(); }

            // Setter methods
            void SetVideoUrl(QUrl *Url) { m_VideoUrl = Url; }
            void SetVideoDateTime(QDateTime DateTime) { m_CreationDateTime = DateTime; }

        private:
            // data values to store in class
            QUrl *m_VideoUrl;
            QDateTime m_CreationDateTime;
        };

        QLabel m_NameLabel;
        Video m_Video;
        QPushButton m_LikeButton;
        QPushButton m_CommentsButton;
    };

    MainWindow* p_MainWindow;
    Ui::HomePage* ui;
    vector<PostWidget> VideosInDirectory;

    // Functions used by the SetupPostsOnSuccessfulLogin() function call
    vector<PostWidget> RetrieveVideosFromDirectory();



};

#endif // HOMEPAGE_H
