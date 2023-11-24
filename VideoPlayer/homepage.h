#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

class QPushButton;

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE

class HomePage : public QWidget
{
    Q_OBJECT
public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

    // Navigation button getters
    const QPushButton* GetLogoutButton() const;
    const QPushButton* GetProfileButton() const;

private:
    Ui::HomePage* ui;
};

#endif // HOMEPAGE_H