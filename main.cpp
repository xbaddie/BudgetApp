#include <iostream>

#include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp("users.xml", "incomes.xml", "expenses.xml");

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
                budgetApp.addExpense();
                break;
            case '3':
                budgetApp.showCurrentMonthBalance();
                break;
            case '4':
                budgetApp.showPreviousMonthBalance();
                break;
            case '5':
                budgetApp.showCustomPeriodBalance();
                break;
            case '6':
                budgetApp.changeUserPassword();
                break;
            case '9':
                budgetApp.logoutUser();
                break;
            }
        }
    }
    return 0;
}
