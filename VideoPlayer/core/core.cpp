#include "core.h"

Core::Core(const CoreArgs& args)
{
    // Initialise user
    m_User.SetUsername("Test");
    m_User.SetEmail("test@test.com");
    m_User.SetPassword("password");
}
