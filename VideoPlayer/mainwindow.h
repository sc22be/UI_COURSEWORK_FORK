#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

#include <QMainWindow>

// Forward declare pages
class LoginPage;
class HomePage;
class ProfilePage;
class WelcomePage;
class RegisterPage;
class SettingsPage;
class Page;

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

    // Indicies of pages in stackedWidget
    enum PageIndex
    {
        HOME_PAGE = 0,
        LOGIN_PAGE = 1,
        PROFILE_PAGE = 2,
        REGISTER_PAGE = 3,
        SETTINGS_PAGE = 4,
        NUM_PAGES
    };

    /**
     * Changes the currently displayed page
     * @param page : PageIndex of what page to change to
    */
    void ChangePage(PageIndex page);

signals:
    void pageChange(const int pageIndex);

private:
    Ui::MainWindow *ui;
    LoginPage* p_LoginPage;
    HomePage* p_HomePage;
    ProfilePage* p_ProfilePage;
    RegisterPage* p_RegisterPage;
    SettingsPage* p_SettingsPage;

};
#endif // MAINWINDOW_H
