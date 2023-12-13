#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>


class Settings
{
public:
    Settings();
    bool shouldNotify = true;
    int lang = 0;
};

#endif // SETTINGS_H
