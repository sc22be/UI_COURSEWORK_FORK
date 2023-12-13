#ifndef POST_H
#define POST_H

#include <QWidget>
#include <QMediaPlayer>

/**
 * @brief This is the video player
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
 */

// Some forward declarations
class User;
class Video;

namespace Ui {
class Post;
}

class Post : public QWidget
{
    Q_OBJECT

public:
    explicit Post(QWidget *parent = nullptr, User* user = nullptr, Video* video = nullptr);
    ~Post();

public slots:
    // Post slots
    void UpdateDuration(qint64 duration);
    void UpdatePosition(qint64 position);
    #if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    void MediaStateChanged(QMediaPlayer::MediaStatus status);
    #else
    void MediaStateChanged(QMediaPlayer::State state);
    #endif
    void MediaPlayerError(QMediaPlayer::Error e);
    void SetPosition(int position);
    void ChangeLikeButtonStatus();

    void PlayPauseClicked();

private:
    Ui::Post *ui;

    // Media player
    QMediaPlayer m_MediaPlayer;
};

#endif // POST_H
