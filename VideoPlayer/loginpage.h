#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

class QPushButton;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginPage; }
QT_END_NAMESPACE

class LoginPage : public QWidget
{
    Q_OBJECT
public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

    // Login button getter
    const QPushButton* GetLoginButton() const;

private:
    Ui::LoginPage* ui;
};

#endif // LOGINPAGE_H
