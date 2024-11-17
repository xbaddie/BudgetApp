#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "UsersFile.h"
#include "User.h"
#include "Utilities.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    bool checkIfLoginExist(const string &login);
    User enterUserData();
    void findUserByLogin(const string &login, vector <User>::iterator &itr);
    void findUserById(vector <User>::iterator &itr);

public:
    UserManager(string userFileName) : userFile(userFileName)
    {
        loggedUserId = 0;
        users = userFile.loadUsersFromFile();
    };
    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();


    bool isUserLoggedIn();
    int getLoggedUserId();
};
