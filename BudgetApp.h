#pragma once
#include <string>

using namespace std;

#include "UserManager.h"
#include "BudgetManager.h"
#include "Utilities.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

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

    char chooseOptionFromMainMenu();
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
