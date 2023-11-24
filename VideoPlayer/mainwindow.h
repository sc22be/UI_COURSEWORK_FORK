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

    // Indicies of pages in stackedWidget
    enum PageIndex
    {
        HOME_PAGE = 0,
        LOGIN_PAGE = 1,
        PROFILE_PAGE = 2
    };

    /**
     * Changes the currently displayed page
     * @param page : PageIndex of what page to change to
    */
    void ChangePage(PageIndex page);

private:
    Ui::MainWindow *ui;

    // Pointers to tacked widget children
    LoginPage* p_LoginPage;
    HomePage* p_HomePage;
    ProfilePage* p_ProfilePage;

};
#endif // MAINWINDOW_H
