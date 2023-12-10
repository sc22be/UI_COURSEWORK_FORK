#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE


class PostWidget;
class HomePage : public QWidget
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    ~HomePage();

public slots:
    void ProfileButtonClicked();
    void SetupPostsOnSuccessfulLogin();

private:
    MainWindow* p_MainWindow;
    Ui::HomePage* ui;
};

#endif // HOMEPAGE_H
