#include "BudgetManager.h"


Operation BudgetManager::addOperationDetails(const Type &type)
{
    Operation operation;
    string inputDate, operationAmount;
    char choice;

    if (type == INCOME)
    {
        operation.id = incomeFile.getLastId() + 1;
    }
    else if (type == EXPENSE)
    {
        operation.id = expenseFile.getLastId() + 1;
    }

    operation.userId = LOGGED_USER_ID;

    cout << "Please choose operation date:" << endl;
    cout << "1. Todays date" << endl;
    cout << "2. Specific date" << endl;

    choice = Utilities::getCharacter();

    switch (choice)
    {
    case '1':
        operation.date = DateMethods::getCurrentDate();
        break;
    case '2':
        do
        {
            cout << "Please enter the date in YYYY-MM-DD format: ";
            inputDate = Utilities::readLine();
        }
        while(!DateMethods::validateDate(inputDate));
        operation.date = DateMethods::convertStringDateToInt(inputDate);
        break;
    default:
        cout << endl << "There is no such option in the menu." << endl << endl;
        system("pause");
        break;
    }

    if(type == INCOME)
    {
        cout << "Please choose income category:" << endl;
        cout << "1. Salary" << endl;
        cout << "2. Internet Sales" << endl;
        cout << "3. Return on investment" << endl;
        cout << "4. Other" << endl;

    }
    else if(type == EXPENSE)
    {
        cout << "Please choose expense category:" << endl;
        cout << "1. Bills" << endl;
        cout << "2. Food" << endl;
        cout << "3. Investments" << endl;
        cout << "4. Other" << endl;

    }

    choice = Utilities::getCharacter();
    switch (choice) {
    case '1':
        operation.item = (type == INCOME) ? "Salary" : "Bills";
        break;
    case '2':
        operation.item = (type == INCOME) ? "Internet Sales" : "Food";
        break;
    case '3':
        operation.item = (type == INCOME) ? "Return on investment" : "Investments";
        break;
    case '4':
        operation.item = "Other";
        break;
    default:
        cout << "There is no such option in the menu.";
        system("pause");
    }

    do
    {
        cout << "Please enter operation amount: ";
        operationAmount = Utilities::readLine();
    }
    while (!CashMethods::validateAmount(operationAmount));

    operation.amount = stod(operationAmount);

    return operation;
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
    Operation expense = addOperationDetails(EXPENSE);
    expenses.push_back(expense);
    expenseFile.addOperationToFile(expense);
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
