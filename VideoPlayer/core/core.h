#ifndef CORE_H
#define CORE_H

#include "core/settings.h"
#include "core/user.h"
#include "core/videodb.h"

#include <array>
#include <string>

/**
 * @author Mustafa Yozgyur
*/

// Arguments to construct core
struct CoreArgs
{
    std::string m_VideosPath;
};

// Singleton class
// Implements backend apis and stuff
class Core
{
public:
    Core(const CoreArgs& args);
    bool SubmitLogin(std::string email, std::string password);

    // Getters
    inline Settings* GetSettings() { return &m_Settings; }
    inline User* GetUser() { return &m_User; }
    inline VideoDB* GetVideoDB() { return &m_VideoDB; }

private:

    // Core related classes
    Settings m_Settings;
    User m_User;
    VideoDB m_VideoDB;
};

#endif // CORE_H
