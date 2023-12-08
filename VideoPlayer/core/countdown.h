#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QTimer>

/**
 * @author Brent Edington
 * @author ...
*/

class countdown : public QObject
{
    Q_OBJECT

public:
    explicit countdown(QObject *parent = nullptr);
    void StopTimer();
    void StartCountdown(int duration);

    // Timer variables
    bool isCountdown = true;
    std::string timerText;

signals:
    void timerChanged(const QString& text);
    void timerColorChange(const QString& style);

private slots:
    void OnSecond();
    QString GetTextColor();

private:
    QTimer *timer;
    int secondsRem = 10;
};

#endif // COUNTDOWN_H
