#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "core/user.h"
#include "page.h"
#include "core/countdown.h"
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE

class HomePage : public QWidget, public Page
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    ~HomePage();

public slots:
    void ProfileButtonClicked();
    void UploadButtonClicked();
    void SetupPostsOnSuccessfulLogin();
    void PageChanged(MainWindow::PageIndex from, MainWindow::PageIndex to);

private:
    MainWindow* p_MainWindow;
    Ui::HomePage* ui;
    countdown timer;

    // Has the user uploaded their video?
    bool b_UploadedVideo = false;

    void ChangeLang();

    // Resize posts when screen is resized
    void ResizePosts();
public:

    void resizeEvent(QResizeEvent* e) override;
    virtual void OnPageEnter() override;
};

#endif // HOMEPAGE_H
