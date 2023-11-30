#ifndef USER_H
#define USER_H

/*
 * @author Muhammad Kashif-Khan
 *
 *
*/


#include <string>
#include <vector>
using namespace std;


class User
{
    public:
        User();         // this constructor will be used to create the default user. there will be only 1 default user for the showcase purpose
        User(string user, string pass)          // this constructor will be used to take care of any new user joining the platform



    private:
        string username;
        string pathToUserDirectory;
        string password;
        vector<string> friends;

        // getter methods
        getUsername();
        getPassword();
        getPathToUserDirectory();
        getFriends();               // could not relate more to this...     (dw im joking)

        // setter methods
        setUsername();


};

#endif // USER_H
