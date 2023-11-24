#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Forward declare pages
class LoginPage;
class HomePage;

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

public slots:

    void LoginButtonClicked();
    void LogoutButtonClicked();

};
#endif // MAINWINDOW_H
