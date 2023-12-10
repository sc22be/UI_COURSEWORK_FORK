#ifndef POST_H
#define POST_H

#include <QWidget>

namespace Ui {
class Post;
}

class Post : public QWidget
{
    Q_OBJECT

public:
    explicit Post(QWidget *parent = nullptr);
    ~Post();

private:
    Ui::Post *ui;
};

/*
class PostWidget: public QWidget
{
    Q_OBJECT
public:
    // Constructor for PostWidget
    PostWidget(std::string name, Video *videoData);

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
*/

#endif // POST_H
