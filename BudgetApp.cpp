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
    MenuManager::chooseOptionFromMainMenu();
}

char BudgetApp::chooseOptionFromUserMenu()
{
    MenuManager::chooseOptionFromUserMenu();
}

