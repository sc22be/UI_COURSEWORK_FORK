#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>

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

private:
    Ui::SettingsPage *ui;

    MainWindow* p_MainWindow;
};

#endif // SETTINGSPAGE_H
