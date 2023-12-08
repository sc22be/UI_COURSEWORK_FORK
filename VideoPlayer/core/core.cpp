#include "core.h"

#include <QString>
#include <iostream>
#include <QDateTime>
#include <regex>

Core::Core(const CoreArgs& args)
{
    std::cout << "Path to assets: " << args.m_AssetsFolderPath << std::endl;
    // Set assets folder path
    m_AssetsPath = args.m_AssetsFolderPath;

    // Initialise user
    m_User.SetUsername("Test");
    m_User.SetEmail("test@test.com");
    m_User.SetPassword("password");

    // Add friends to user
    m_User.AddFriend("@DynoAbd786");
    m_User.AddFriend("@Brek");
    m_User.AddFriend("@Gamer");
    m_User.AddFriend("@xSarahVictoria");
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

//Account Modification
int Core::RegisterAccount(std::string username, std::string password, std::string email, QDateTime birthday)
{
    // Check if all fields were given
    if (username.empty() || password.empty() || email.empty() || birthday.isNull())
    {
        return Register::EMPTY;
    }

    // Check if age is 13 or above
    QDateTime today = QDateTime::currentDateTime();
    int yearsDiff = birthday.daysTo(today) / 365;
    if (yearsDiff < 13)
    {
        return Register::TOOYOUNG;
    }

    // Check if email is valid
    // Create email formatting (requreing and @ and .)
    QRegExp mailFormat("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailFormat.setCaseSensitivity(Qt::CaseInsensitive);
    mailFormat.setPatternSyntax(QRegExp::RegExp);

    // If not an email
    bool isEmail = mailFormat.exactMatch(QString::fromStdString(email));
    if (!isEmail)
    {
        return Register::NOTEMAIL;
    }

    // Create all the regex for passwords (to give personalised errors)
    std::regex contUppercase("[A-Z]");
    std::regex contLowercase("[a-z]");
    std::regex containsNum("[0-9]");
    //std::regex containsSymbol("[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>\\/?]"); TBD

    // Check password strength
    if (password.length() < 8)
    {
        // If password length is less then 8
        return Register::SHORTPASS;
    }
    else if (!std::regex_search(password, contUppercase))
    {
        // If password does not contain uppercase
        return Register::NOUPPER;
    }
    else if (!std::regex_search(password, contLowercase))
    {
        // If password does not contain lowercase
        return Register::NOLOWER;
    }
    else if (!std::regex_search(password, containsNum))
    {
        // If password does not contain a number
        return Register::NONUM;
    }
    /* TBD
    else if (!std::regex_search(password, containsSymbol))
    {
        // If password does not contain a symbol
        return Register::NOSYMBOL;
    }
    */

    // After all checks, change user information and return 0 to change page
    m_User.SetUsername(username);
    m_User.SetEmail(email);
    m_User.SetPassword(password);
    return Register::SUCCESS;
}
