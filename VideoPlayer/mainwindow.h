#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Forward declare pages
class LoginPage;
class HomePage;
class ProfilePage;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // Pointers to tacked widget children
    LoginPage* p_LoginPage;
    HomePage* p_HomePage;
    ProfilePage* p_ProfilePage;

public slots:

    // Handle navigation
    void LoginButtonClicked();
    void LogoutButtonClicked();
    void ProfileHomeButtonClicked();
    void ProfileButtonClicked();

};
#endif // MAINWINDOW_H
