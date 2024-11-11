#include "UsersFile.h"

vector <User> UserFile::loadUsersFromFile()
{
    User user;
    vector <User> users;

    try {
        if (!xmlFile.Load(getFileName())) {
            cerr << "Error: Could not load XML file." << endl;
            return users; // Return an empty vector on error
        }

        xmlFile.FindElem("Users");
        xmlFile.IntoElem();

        while (xmlFile.FindElem("User")) {
            xmlFile.IntoElem();

            xmlFile.FindElem("ID");
            user.id = stoi(xmlFile.GetData());

            xmlFile.FindElem("FirstName");
            user.firstName = xmlFile.GetData();

            xmlFile.FindElem("LastName");
            user.lastName = xmlFile.GetData();

            xmlFile.FindElem("Login");
            user.login = xmlFile.GetData();

            xmlFile.FindElem("Password");
            user.password = xmlFile.GetData();

            users.push_back(user);
            xmlFile.OutOfElem();
        }
    } catch (const exception &caughtException) {
        cerr << "Error loading users: " << caughtException.what() << endl;
    }

    return users;
}

bool UserFile::addUserToFile(const User &user)
{
    try {
        ifstream infile(getFileName());
        bool fileExists = infile.good();
        infile.close();

        if (fileExists) {
            xmlFile.Load(getFileName());
        } else {
            xmlFile.AddElem("Users");
        }

        xmlFile.FindElem("Users");
        xmlFile.IntoElem();

        xmlFile.AddElem("User");
        xmlFile.IntoElem();
        xmlFile.AddElem("ID", user.id);

        xmlFile.AddElem("FirstName", user.firstName);
        xmlFile.AddElem("LastName", user.lastName);
        xmlFile.AddElem("Login", user.login);
        xmlFile.AddElem("Password", user.password);
        xmlFile.OutOfElem();

        if (!xmlFile.Save(getFileName())) {
            cout << "Failed to save the user to the file." << endl;
            return false;
        }
    } catch (const exception &caughtException) {
        cerr << "Error: " << caughtException.what() << endl;
        return false;
    }

    return true;
}
