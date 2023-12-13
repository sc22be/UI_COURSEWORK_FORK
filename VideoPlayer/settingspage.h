#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>

/**
 * @author Brent Edington
 * @@author Mustafa Yozgyur
*/

#include "page.h"

class MainWindow;

namespace Ui {
class SettingsPage;
}

class SettingsPage : public QWidget, public Page
{
    Q_OBJECT

public:
    explicit SettingsPage(QWidget *parent = nullptr, MainWindow* window = nullptr);
    ~SettingsPage();

    virtual void OnPageEnter() override;

private slots:
    // Dropdowns
    void OnNotifyChange(int index);
    void OnLangChange(int index);
    // Buttons
    void ProfileButtonClicked();
    void LogoutButtonClicked();
    void HowtoClicked();

private:
    Ui::SettingsPage *ui;

    MainWindow* p_MainWindow;
    void ChangeLang();
};

#endif // SETTINGSPAGE_H
