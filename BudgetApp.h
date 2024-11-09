#pragma once
#include <string>

using namespace std;

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;
    void wczytajAdresatowZalogowanegoUzytkownikaZpliku();

public:
    BudgetApp(string userFileName, string incomeFileName, string expenseFileName)
    : userManager(userFileName), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName)
    {
        budgetManager = NULL;
    };
    ~BudgetApp()
    {
        delete budgetManager;
        budgetManager = NULL;
    }

    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();

};
