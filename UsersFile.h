#pragma once
#include <string>

using namespace std;

class UserFile : public File
{
public:
    UserFile(string userFileName) : FILE_NAME(userFileName) {
    };
  vector <User> loadUsersFromFile();
  bool addUserToFile(const User &user);
  bool changePasswordInFile(int id, const string &password)
}
