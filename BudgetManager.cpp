#include "BudgetManager.h"


Operation BudgetManager::addOperationDetails(const Type &type)
{
    Operation operation;

    if (type == INCOME)
    {
        operation.id = incomeFile.getLastId() + 1;
    }
    else if (type == EXPENSE)
    {
        operation.id = expenseFile.getLastId() + 1;
    }

    operation.userId = LOGGED_USER_ID;

    cout << "Please choose income date:" << endl;
    cout << "1. Todays date" << endl;
    cout << "2. Specific date" << endl;

    char choice = Utilities::getCharacter();

    switch (choice)
    {
    case '1':
        operation.date = int getCurrentDate();
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



        cout << "Enter Password: ";
    user.password = Utilities::readLine();

    cout << "Enter First Name: ";
    user.firstName = Utilities::readLine();


    cout << "Enter Last Name: ";
    user.lastName = Utilities::readLine();

    return user;
}

void BudgetManager::showBalance(int startDate, int endDAte)
{

}

double BudgetManager::calculateBalance(int startDate, int endDate, const Type &type)
{

}

void BudgetManager::addIncome()
{
    Operation income = addOperationDetails(INCOME);
    incomes.push_back(income);
    incomeFile.addOperationToFile(income);
}

void BudgetManager::addExpense()
{

}

void BudgetManager::showCurrentMonthBalance()
{

}

void BudgetManager::showPreviousMonthBalance()
{

}

void BudgetManager::showCustomPeriodBalance()
{

}
