#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "core/user.h"
#include "page.h"
#include "core/countdown.h"

class MainWindow;

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

private:
    MainWindow* p_MainWindow;
    Ui::HomePage* ui;
    countdown timer;

    // Resize posts when screen is resized
    void ResizePosts();
public:

    void resizeEvent(QResizeEvent* e) override;
    virtual void OnPageEnter() override;
};

#endif // HOMEPAGE_H
