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
//        User(string user, string pass);          // this constructor will be used to take care of any new user joining the platform. this constructor may be redundant

        // getter methods
        const string getUsername()   { return username; }
//        const string getPassword()  { return password; }          // temporary comment out until i figure out what is going on
        const QString getPathToUserDirectory()  { return pathToUserDirectory; }
        const vector<string> getFriends()   { return friends; }               // could not relate more to this...     (dw im joking)

        // setter methods
        void setUsername(string user);
//        void setPassword(string pass);          // temporary comment out until i figure out what is going on
//        void setFriends(vector<string> friendList)  { friends = friendList; }   // involve this to be in the private sector
        void addFriend(string userFriend);
        void removeFriend(string userFriend);


//        // take notice of the different name here. setting the path to the app directory can allow us to use the update function to find the path to the user informatio
        // THIS IS MOST LIKELY REDUNDANT

//        void setPathToAppDirectory(QString path);




    private:
        // values to store
        string username;
        QString pathToUserDirectory;
        string password;                // @BRENT do you need this?
        vector<string> friends;

        // if the username has been added/modified/updated, these functions will redirect the path to the correct directory
        void updatePathToUserDirectory();
        //  and retrieve the new friends list
        void retrieveFriendsList();





};

#endif // USER_H
