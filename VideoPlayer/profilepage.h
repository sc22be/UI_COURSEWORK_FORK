#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

#include <QWidget>
#include "core/user.h"

class QPushButton;
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class ProfilePage; }
QT_END_NAMESPACE

class ProfilePage : public QWidget
{
    Q_OBJECT
public:
    explicit ProfilePage(QWidget *parent = nullptr, MainWindow* main_window = nullptr, User *user = nullptr);
    ~ProfilePage();

public slots:

    void HomeButtonClicked();

private:
    MainWindow* p_MainWindow;
    Ui::ProfilePage* ui;

};

#endif // PROFILEPAGE_H
