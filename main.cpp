#include <iostream>

#include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("users.xml","incomes.xml", "expenses.xml");

        while (true)
    {
        if (!budgetApp.isUserLoggedIn())
        {
            char choice = budgetApp.chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                budgetApp.registerUser();
                break;
            case '2':
                budgetApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
           char choice = budgetApp.chooseOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                budgetApp.addIncome();
                break;
            case '2':
               // ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
              //  ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
               // ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
              //  ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                budgetApp.changeUserPassword();
                break;
            case '8':
                budgetApp.logoutUser();
                break;
            }
        }
    }
    return 0;
}
