#include <QString>
#include <QDir>


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

void User::setUsername(QString user)
{
    username = user.toLower();

    updatePathToUserDirectory();
    retrieveFriendsList();
}

// sets the path of the user directory by navigating from the apps directory
void User::updatePathToUserDirectory()
{
    QDir userFolder(pathToUserDirectory);
    userFolder.cd("users");
    userFolder.cd(username);

    pathToUserDirectory = userFolder.absolutePath();
}

// retrieves friends of user from the users friends list
// NULL FUNCTION. DOES NOT DO ANYTHING AT THE MOMENT
void User::retrieveFriendsList()
{

}




//User::User(string user, string pass)
//{

//}
