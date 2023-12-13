#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

/**
 * @author Brent Edington
 * @author ...
*/

#include <QWidget>
#include "page.h"

class QPushButton;
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui {class RegisterPage;}
QT_END_NAMESPACE

class RegisterPage : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    ~RegisterPage();

private slots:
    void RegisterButtonClicked();

private:
    MainWindow* p_MainWindow;
    Ui::RegisterPage* ui;
    void ChangeLang();

public:
    virtual void OnPageEnter() override;
};

#endif // REGISTERPAGE_H
