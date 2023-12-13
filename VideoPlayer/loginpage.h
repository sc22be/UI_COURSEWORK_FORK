#ifndef LOGINPAGE_H
#define LOGINPAGE_H

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
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QWidget, public Page
{
    Q_OBJECT
public:
    explicit LoginPage(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    ~LoginPage();

private slots:
    void LoginButtonClicked();
    void RegisterButtonClicked();
    void OnLangChange(int index);

private:
    MainWindow* p_MainWindow;
    Ui::LoginPage* ui;
    void ChangeLang();

public:
    virtual void OnPageEnter() override {};
};

#endif // LOGINPAGE_H
