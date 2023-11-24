#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QWidget>

class QPushButton;

QT_BEGIN_NAMESPACE
namespace Ui { class ProfilePage; }
QT_END_NAMESPACE

class ProfilePage : public QWidget
{
    Q_OBJECT
public:
    explicit ProfilePage(QWidget *parent = nullptr);
    ~ProfilePage();

    // Button getters for connecting buttons
    const QPushButton* GetHomeButton() const;

private:

    Ui::ProfilePage* ui;

};

#endif // PROFILEPAGE_H
