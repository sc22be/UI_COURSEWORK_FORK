#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

#include <QMainWindow>
#include <QTranslator>

// Forward declare pages
class LoginPage;
class HomePage;
class ProfilePage;
class WelcomePage;
class RegisterPage;
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
        NUM_PAGES
    };

    /**
     * Changes the currently displayed page
     * @param page : PageIndex of what page to change to
    */
    void ChangePage(PageIndex page);
    void ChangeLang(QString lang);

signals:
    void pageChange(const int pageIndex);
    void langChange();

private:
    Ui::MainWindow *ui;
    LoginPage* p_LoginPage;
    HomePage* p_HomePage;
    ProfilePage* p_ProfilePage;
    RegisterPage* p_RegisterPage;

    QTranslator translator;
};
#endif // MAINWINDOW_H
