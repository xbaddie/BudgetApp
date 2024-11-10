#include "UserManager.h"

bool UserManager::checkIfLoginExist(const string &login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].login == login)
        {
            cout << endl << "User with entered login already exists." << endl;
            return true;
        }
    }
    return false;
}

User UserManager::enterUserData()
{
    User user;

    if (users.empty()) {
        user.id = 1;
    } else {
        user.id = users.back().id + 1;
    }

    string login;

    do
    {
        cout << "Enter login: ";
        cin >> login;
        user.login = login;
    }
    while (checkIfLoginExist(user.login) == true);

    string password;
    cout << "Enter Password: ";
    cin >> password;
    user.password = password;

    return user;
}

void UserManager::findUserByLogin(const string &login, vector <User>::iterator &itr)
{

}

void UserManager::findUserById(vector <User>::iterator &itr)
{

}

void UserManager::registerUser()
{
    User user = enterUserData();

    users.push_back(user);
    userFile.addUserToFile(user);
    cout << endl << "Your account has been created." << endl << endl;
    system("pause");
}

void UserManager::loginUser()
{

}

void UserManager::changeUserPassword()
{

}

void UserManager::logoutUser()
{

}

bool UserManager::isUserLoggedIn()
{

}

int UserManager::getLoggedUserId()
{

}
