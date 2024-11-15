#include "BudgetApp.h"

bool BudgetApp::isUserLoggedIn()
{
   return userManager.isUserLoggedIn();
}
void BudgetApp::registerUser()
{
    userManager.registerUser();
}

void BudgetApp::loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedUserId());
    }
}

void BudgetApp::changeUserPassword()
{
    userManager.changeUserPassword();
}

void BudgetApp::logoutUser()
{
    userManager.logoutUser();
}

void BudgetApp::addIncome()
{
    budgetManager->addIncome();
}

void BudgetApp::addExpense()
{
    budgetManager->addExpense();
}

void BudgetApp::showCurrentMonthBalance()
{
    budgetManager->showCurrentMonthBalance();
}

void BudgetApp::showPreviousMonthBalance()
{
    budgetManager->showPreviousMonthBalance();
}

void BudgetApp::showCustomPeriodBalance()
{
    budgetManager->showCustomPeriodBalance();
}

char BudgetApp::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register user" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------" << endl;
    cout << "Choosment: ";
    choice = Utilities::getCharacter();

    return choice;
}

char BudgetApp::chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << "    >>> User Menu <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Previous month balance" << endl;
    cout << "5. Custom period balance" << endl;
    cout << "6. ChangePassword" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------" << endl;
    cout << "Choosment: ";
    choice = Utilities::getCharacter();

    return choice;
}

