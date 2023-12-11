#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

#include <QWidget>
#include "core/user.h"
#include "page.h"

class QPushButton;
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class ProfilePage; }
QT_END_NAMESPACE

class ProfilePage : public QWidget, public Page
{
    Q_OBJECT
public:
    explicit ProfilePage(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    ~ProfilePage();

public slots:

    void HomeButtonClicked();

private:
    MainWindow* p_MainWindow;
    Ui::ProfilePage* ui;
public:
    virtual void OnPageEnter() override {}
};

#endif // PROFILEPAGE_H
