#ifndef USER_H
#define USER_H

/*
 * @author Muhammad Kashif-Khan
 * @author ...
*/

#include <string>
#include <vector>
#include <QString>
using namespace std;


class User
{
    public:
        User(QString appPath);         // this constructor will be used to create the default user using the initial path to the app. there will be only 1 default user for the log in showcase purpose

        //        User(string user, string pass);          // this constructor will be used to take care of any new user joining the platform. this constructor may be redundant (havent veriefied with the group)

        // getter methods
        const QString getUsername()   { return username; }
        const QString getPassword()  { return password; }
        const QString getEmail()    { return email; }
        const QString getPathToUserDirectory()  { return pathToUserDirectory; }
        const vector<QString> getFriends()   { return friendsList; }               // could not relate more to this...     (dw im joking)



        // setter methods
        void setUsername(QString user);
        void setPassword(QString pass)  { password = pass; }
        void setEmail(QString e)    { email = e; }

        // friend related methods
        void addFriend(QString usernameOfFriend);
        void removeFriend(QString usernameOfFriend);

    private:
        // values to store
        QString username;
        QString pathToUserDirectory;
        QString password;
        QString email;
        vector<QString> friendsList;            // the type of the friends list may be changed to conform with requirements. im thinking it may need to be another class called Friend. Need to Discuss

        // if the username has been added/modified/updated, these functions will redirect the path to the correct directory
        void updatePathToUserDirectory();
        //  and retrieve the new friends list
        void retrieveFriendsList();
};

#endif // USER_H
