#include "UsersFile.h"

vector <User> UserFile::loadUsersFromFile()
{
    User user;
    vector <User> users;
//    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
//
//    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
//
//    if (plikTekstowy.good() == true)
//    {
//        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
//        {
//            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
//            uzytkownicy.push_back(uzytkownik);
//        }
//        plikTekstowy.close();
//    }

    return users;
}

bool UserFile::addUserToFile(const User &user)
{

}
