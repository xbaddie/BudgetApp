#include "UsersFile.h"

vector <User> UserFile::loadUsersFromFile()
{
    User user;
    vector <User> users;

    if (!xmlFile.Load(getFileName()))
    {
        return users;
    }

    xmlFile.FindElem("Users");
    xmlFile.IntoElem();

    while (xmlFile.FindElem("User"))
    {
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

    return users;
}

bool UserFile::addUserToFile(const User &user)
{

    ifstream infile(getFileName());
    bool fileExists = infile.good();
    infile.close();

    if (fileExists)
    {
        xmlFile.Load(getFileName());
    }
    else
    {
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

    if (!xmlFile.Save(getFileName()))
    {
        return false;
    }


    return true;
}

bool UserFile::changePasswordInFile(int id, const string &password)
{
    int tempId;

    xmlFile.Load(getFileName());
    xmlFile.FindElem("Users");
    xmlFile.IntoElem();
    while (xmlFile.FindElem("User"))
    {
        xmlFile.IntoElem();
        if (xmlFile.FindElem("ID"))
        {
            tempId = stoi(xmlFile.GetData());
            if(id == tempId)
            {
                xmlFile.FindElem("Password");
                xmlFile.SetData(password);
                xmlFile.Save(getFileName());
                return true;
            }
            xmlFile.OutOfElem();
        }
    }
    return false;
}

int UserFile::getLastId()
{
    int lastId = 0;

    try {
        if (!xmlFile.Load(getFileName())) {
            return lastId;
        }

        xmlFile.FindElem("Users");
        xmlFile.IntoElem();

        while (xmlFile.FindElem("User")) {
            xmlFile.IntoElem();
            xmlFile.FindElem("ID");
            lastId = stoi(xmlFile.GetData());
            xmlFile.OutOfElem();
        }

    } catch (const exception &caughtException) {
        cerr << "Error getting last user ID: " << caughtException.what() << endl;
    }

    return lastId;
}

