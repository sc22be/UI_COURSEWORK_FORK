#ifndef LOGINPAGE_H
#define LOGINPAGE_H

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

#include <QWidget>
#include <user.h>

class QPushButton;
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QWidget
{
    Q_OBJECT
public:
    explicit LoginPage(QWidget *parent = nullptr, MainWindow* main_window = nullptr, User *user = nullptr);
    ~LoginPage();

private slots:
    void LoginButtonClicked();
    void RegisterButtonClicked();

private:
    MainWindow* p_MainWindow;
    Ui::LoginPage* ui;
};

#endif // LOGINPAGE_H
