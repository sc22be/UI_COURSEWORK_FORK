#ifndef CORE_H
#define CORE_H

#include <string>


class Core
{
public:
    Core();
    // Account
    bool SubmitLogin(std::string email, std::string password);
    inline std::string GetUsername() const {return "HelloWorld";};
    // Get Profile Picture

    // Video Player
    // Get Video

    // Events (Notifications)


};

#endif // CORE_H
