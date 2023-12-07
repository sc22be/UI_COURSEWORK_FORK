#ifndef HOMEPAGE_H
#define HOMEPAGE_H

//#include "qlayout.h"
// Muhammad: ^^ i dont know what is up with this include here
#include <QWidget>
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>
#include <QDateTime>
#include <QVBoxLayout>
#include <QSlider>


//#include "core/user.h"

using namespace std;

class QPushButton;
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE


class PostWidget;
class HomePage : public QWidget
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    ~HomePage();


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
        QString GetCreationTimeToString() { return m_CreationDateTime.time().toString(); }
        QString GetCreationDateToString() { return m_CreationDateTime.date().toString(); }

        // Setter methods
        // THESE MIGHT BE REDUNDANT
        void SetVideoUrl(QUrl *Url) { m_VideoUrl = Url; }
        void SetVideoDateTime(QDateTime DateTime) { m_CreationDateTime = DateTime; }

    private:
        // data values to store in class
        QUrl *m_VideoUrl;
        QDateTime m_CreationDateTime;
    };

    // Post creation functions
    vector<PostWidget*> SetupPostWidgetsAndLayout(vector<HomePage::Video*> DataForVideos);

public slots:
    void ProfileButtonClicked();
    void SetupPostsOnSuccessfulLogin();



protected:
    vector<Video*> RetrieveVideosFromDirectory();





private:
    MainWindow* p_MainWindow;
    Ui::HomePage* ui;
    vector<Video*> VideosFromDirectory;
    vector<PostWidget*> PostWidgets;
    QVBoxLayout LayoutForAllPosts;

    // Functions used by the SetupPostsOnSuccessfulLogin() function call
//    vector<PostWidget> SetupPostWidgetsAndLayout(vector<Video> DataOfVideos);



};


class PostWidget: public QWidget
{
    Q_OBJECT
public:
    // Constructor for PostWidget
    PostWidget(std::string name, HomePage::Video *videoData);

public slots:
    // Post slots
    void UpdateDuration(qint64 duration);
    void UpdatePosition(qint64 position);
    void SetPosition(int position);
    void ChangeLikeButtonStatus();

private:
    // Functions to set up post class
    void CreateWidgets(string name, HomePage::Video *videoData);
    void ArrangeWidgets();
    void MakeConnections();



    // Widgets
    QLabel *m_NameLabel;
    QLabel *m_TimeLabel;
    QPushButton *m_LikeButton;
    QPushButton *m_CommentsButton;
    QSlider *m_SliderForVideoSeeking;
    QVideoWidget *m_Video;
    // And the respective video player
    QMediaPlayer *m_MediaPlayer;

    // Layouts to store the widgets and layouts to
    QHBoxLayout *m_UserInformationLayout;
    QVBoxLayout *m_VideoPlayerLayout;
    QHBoxLayout *m_LikeAndCommentLayout;

    QVBoxLayout *m_MainLayout;

};

#endif // HOMEPAGE_H
