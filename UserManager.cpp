#include "UserManager.h"

bool UserManager::checkIfLoginExist(const string &login)
{
    for (size_t i = 0; i < users.size(); i++)
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

    user.id = userFile.getLastId() + 1;


    do
    {
        cout << "Enter login: ";
        user.login = Utilities::readLine();
    }
    while (checkIfLoginExist(user.login) == true);


    cout << "Enter Password: ";
    user.password = Utilities::readLine();

    cout << "Enter First Name: ";
    user.firstName = Utilities::readLine();


    cout << "Enter Last Name: ";
    user.lastName = Utilities::readLine();

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
    if (userFile.addUserToFile(user))
    {
        cout << endl << "Your account has been created." << endl << endl;
        system("pause");
    }

}

void UserManager::loginUser()
{
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = Utilities::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr ->login == login)
        {
            for (int entryAttempts = 3; entryAttempts > 0; entryAttempts--)
            {
                cout << "Enter password. Attempts remaining: " << entryAttempts << ": ";
                password = Utilities::readLine();

                if (itr -> password == password)
                {
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    loggedUserId = itr ->id;
                    return;
                }
            }
            cout << "You have entered the wrong password 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "User with provided login do not exist" << endl << endl;
    system("pause");
    return;
}

void UserManager::changeUserPassword()
{
    string newUserPassword;
    bool passwordChanged = false;

    for (int i = 0; i <users.size(); i++)
    {
        if (users[i].id == loggedUserId)
        {
            do
            {
                cout << "Type in new password: ";
                newUserPassword = Utilities::readLine();
                cout << "Confirm password: ";
                if (newUserPassword == Utilities::readLine())
                {
                    users[i].password = newUserPassword;
                    passwordChanged = true;
                }
                else
                {
                    cout << "Passwords do not match. Try again." << endl;
                    system("pause");
                }
            }
            while (!passwordChanged);
            if (!userFile.changePasswordInFile(loggedUserId, newUserPassword))
            {
                cout << "Failed to change user password";
            }
        }
    }
}

void UserManager::logoutUser()
{
    loggedUserId = 0;
}

bool UserManager::isUserLoggedIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}
