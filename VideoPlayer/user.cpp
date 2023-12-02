#include <QString>


#include "user.h"

// constructor sets up the default user for the explicit purpose of the showcase
User::User(QString appPath)
{
    pathToUserDirectory = appPath;
}

// adds friends to the friends list, 1 by 1
void User::addFriend(QString usernameOfFriend)
{
    friendsList.push_back(usernameOfFriend);
}

// removes friends from the friends list, 1 by 1
void User::removeFriend(QString usernameOfFriend)
{
    auto it = remove(friendsList.begin(), friendsList.end(), usernameOfFriend);
    friendsList.erase(it, friendsList.end());
}







//User::User(string user, string pass)
//{

//}
