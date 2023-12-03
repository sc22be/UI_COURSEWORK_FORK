#include "core.h"

#include <QString>

Core::Core(const CoreArgs& args)
{
    // Initialise user
    m_User.SetUsername("Test");
    m_User.SetEmail("test@test.com");
    m_User.SetPassword("password");
}

// Account Authication
bool Core::SubmitLogin(std::string email, std::string password)
{

    // Checks if strings are the same (returns 0) and sends to login screen
    if(email.compare(m_User.GetEmail()) == 0 && password.compare(m_User.GetPassword()) == 0)
    {
        return true;
    }
    else
    {
        // For dev only, REMOVE BEFORE PRODUCTION
        if(email.empty() && password.empty())
        {
            return true;
        }
        // For dev only, REMOVE BEFORE PRODUCTION

        return false;
    }
}
