#include "post.h"
#include "ui_post.h"

#include "core/user.h"
#include "core/video/video.h"

#include <iostream>

Post::Post(QWidget *parent, User* user, Video* video)
    : QWidget(parent)
    , ui(new Ui::Post)
{
    ui->setupUi(this);

    std::cout << "Creating video player for: " << video->GetPath() << std::endl;

    // Connect ui signals
    connect(ui->slider_Slider, SIGNAL(valueChanged(int)), this, SLOT(SetPosition(int)));
    connect(&m_MediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(UpdateDuration(qint64)));
    connect(&m_MediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(UpdatePosition(qint64)));

    // Connect like button
    connect(ui->button_Like, SIGNAL(clicked()), this, SLOT(ChangeLikeButtonStatus()));

    // Setup media player
    m_MediaPlayer.setMedia(video->GetURL());
    m_MediaPlayer.setVideoOutput(ui->vp_MediaPlayer);
    m_MediaPlayer.play();

    // Set text of lables
    ui->label_Username->setText(std::string("@").append(user->GetUsername()).c_str());
    ui->label_Date->setText(video->GetDate().toString());
}

Post::~Post()
{
    delete ui;
}

void Post::UpdateDuration(qint64 duration)
{
    ui->slider_Slider->setMaximum(static_cast<int>(duration));
}

void Post::UpdatePosition(qint64 position)
{
    ui->slider_Slider->setValue(static_cast<int>(position));
}

void Post::SetPosition(int position)
{
    m_MediaPlayer.setPosition(static_cast<qint64>(position));
    m_MediaPlayer.play();
}

void Post::ChangeLikeButtonStatus()
{
    if (!ui->button_Like->isChecked())
    {
        ui->button_Like->setIcon(QIcon(":/assets/button_images/likeButtonOn.jpg"));
        ui->button_Like->setCheckable(true);
    }
    else
    {
        ui->button_Like->setIcon(QIcon(":/assets/button_images/likeButtonOff.jpg"));
        ui->button_Like->setCheckable(false);
    }
}
