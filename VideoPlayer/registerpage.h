#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

/**
 * @author Brent Edington
 * @author ...
*/

#include <QWidget>

class QPushButton;
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui {class RegisterPage;}
QT_END_NAMESPACE

class RegisterPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    ~RegisterPage();

private slots:
    void registerButtonClicked();

private:
    MainWindow* p_MainWindow;
    Ui::RegisterPage* ui;
};

#endif // REGISTERPAGE_H
