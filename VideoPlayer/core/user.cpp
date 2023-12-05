#include <QString>
#include <QDir>


#include "user.h"

// constructor sets up the default user for the explicit purpose of the showcase
User::User()
{

}

// adds friends to the friends list, 1 by 1
void User::AddFriend(std::string usernameOfFriend)
{
    m_FriendsList.push_back(usernameOfFriend);
}

// removes friends from the friends list, 1 by 1
// void User::RemoveFriend(User* usernameOfFriend)
// {
//     auto it = remove(friendsList.begin(), friendsList.end(), usernameOfFriend);
//     friendsList.erase(it, friendsList.end());
// }

// retrieves friends of user from the users friends list
