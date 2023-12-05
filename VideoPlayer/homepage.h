#ifndef HOMEPAGE_H
#define HOMEPAGE_H

//#include "qlayout.h"
// Muhammad: ^^ i dont know what is up with this include here
#include <QWidget>
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>

//#include "core/user.h"

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

    class PostWidget: public QWidget
    {
    public:
        PostWidget(std::string name, std::string timePosted, std::string videoUrl);
        QLabel m_NameLabel;
        QLabel m_TimePostedLabel;
        QMediaPlayer m_Video;
        QPushButton m_LikeButton;

    };


public slots:
    void ProfileButtonClicked();

private:
    MainWindow* p_MainWindow;
    Ui::HomePage* ui;
    void SetupPosts();
};

#endif // HOMEPAGE_H
