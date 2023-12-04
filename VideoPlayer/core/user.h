#ifndef USER_H
#define USER_H

/*
 * @author Muhammad Kashif-Khan
 * @author Mustafa Yozgyur
*/

#include <string>
#include <vector>


class User
{
public:
    User();

    // getter methods
    const std::string GetUsername()          { return m_Username; }
    const std::string GetPassword()          { return m_Password; }
    const std::string GetEmail()             { return m_Email; }
    const std::vector<User*> GetFriends()    { return m_FriendsList; } // could not relate more to this...     (dw im joking)
    std::vector<User*> RetrieveFriendsList() { return m_FriendsList; }



    // setter methods
    void SetUsername(std::string user)  { m_Username = user; }
    void SetPassword(std::string pass)  { m_Password = pass; }
    void SetEmail(std::string email)    { m_Email = email; }

    // friend related methods
    void AddFriend(User* usernameOfFriend);
    // void RemoveFriend(User* usernameOfFriend); // Removed: as wont be used in the prototype

private:
    // values to store
    std::string m_Username = "test";
    std::string m_Password = "password";
    std::string m_Email = "test@test.com";
    std::vector<User*> m_FriendsList;
};

#endif // USER_H
