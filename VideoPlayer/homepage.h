#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "core/user.h"
#include "core/countdown.h"

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

private:
    MainWindow* p_MainWindow;
    Ui::HomePage* ui;
    countdown timer;
};

#endif // HOMEPAGE_H
