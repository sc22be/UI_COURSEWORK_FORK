#include "Countdown.h"


#include <QTimer>
#include <QDebug>
#include <QString>

/**
 * @author Brent Edington
 * @author ...
*/

countdown::countdown(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);

    // Setup signal and function per second
    connect(timer, SIGNAL(timeout()), this, SLOT(OnSecond()));
}

void countdown::StartCountdown(int duration)
{
    // Always stop timer just in case it is going
    StopTimer();
    // Set countdown to true
    isCountdown = true;
    // Set timer duration
    secondsRem = duration;
    // For protype, have timer run when home page is
    // opened so only once during the app's existence
    isFirst = false;
    // Timer is in ms, want to trigger every 1s (1000ms)
    timer->start(1000);
}

void countdown::StopTimer()
{
    timer->stop();
}

// Every second
void countdown::OnSecond()
{
    // Get minutes and preformatted seconds
    int minutes = secondsRem / 60;
    int rawSeconds = secondsRem % 60;

    // Add a placeholder if needed
    QString seconds = QString::number(rawSeconds);
    if (rawSeconds < 10)
    {
        seconds = "0" + QString::number(rawSeconds);
    }

    // Change text and emit signal saying timer text updated
    timerText = std::to_string(minutes) + ":" + seconds.toStdString();
    emit timerChanged(QString::fromStdString(timerText));

    // Test if time has expired
    if (secondsRem == 0)
    {
        isCountdown = false;
    }

    // Test if color needs to change
    QString style = GetTextColor();
    if (style != "")
    {
        emit timerColorChange(style);
    }

    // Change timer
    if (isCountdown)
    {
        secondsRem--;
    }
    else
    {
        secondsRem++;
    }
}

QString countdown::GetTextColor()
{
    int rgbColors[] = {255, 255, 255};
    if (secondsRem <= 60 && secondsRem >= 30)
    {
        float scalar = 102/30; // Difference/Seconds Rem

        // Calculate new rgb values
        for (int i = 1; i < 3; i++)
        {
            // This takes the scalar and multiplies it by how many seconds are left until we
            // reach the desired rgb value
            rgbColors[i] = rgbColors[i] - (scalar*(30-(secondsRem-30)));
        }

        QString textColor = QString("color: rgb(%1, %2, %3);").arg(rgbColors[0]).arg(rgbColors[1]).arg(rgbColors[2]);
        return textColor;
    }

    // If not
    return "";
}
