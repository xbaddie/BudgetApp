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

    MenuManager::addOperationDateMenu(operation);
    MenuManager::addOperationCategoryMenu(operation, type);
    MenuManager::addOperationAmountMenu(operation);

    return operation;
}

void BudgetManager::showBalance(int startDate, int endDate)
{
    cout << "Balance From " << DateMethods::convertIntDateToStringWithDashes(startDate) << " TO " << DateMethods::convertIntDateToStringWithDashes(endDate) << endl;

    cout << "Incomes:" << endl;
    double incomesSum = calculateBalance(startDate, endDate, INCOME);
    cout << "Expenses:" << endl;
    double expensesSum = calculateBalance(startDate, endDate, EXPENSE);

    cout << "Total Incomes:" << incomesSum << endl;
    cout << "Total Expenses:" << expensesSum << endl << endl;
    cout << "Balance:" << incomesSum - expensesSum << endl;

    system("pause");
}

double BudgetManager::calculateBalance(int startDate, int endDate, const Type &type)
{
    double balance = 0;
    vector<Operation> operations = (type == INCOME) ? incomes : expenses;

    sort(operations.begin(), operations.end(), [](const Operation &a, const Operation &b)
    {
        return a.date < b.date;
    });

    for (const Operation &operation : operations)
    {
        if (operation.date >= startDate && operation.date <= endDate)
        {
            cout << "ID: " << operation.id << " Transaction date: " << operation.date << " Operation: " << operation.item << " Amount: " << operation.amount << endl;
            balance += operation.amount;
        }
    }
    return balance;
}

void BudgetManager::addIncome()
{
    Operation income = addOperationDetails(INCOME);
    incomes.push_back(income);
    if(incomeFile.addOperationToFile(income))
    {
        cout << "Operation added successfully." << endl;
        system("pause");
    }
}

void BudgetManager::addExpense()
{
    Operation expense = addOperationDetails(EXPENSE);
    expenses.push_back(expense);
    if(expenseFile.addOperationToFile(expense))
    {
        cout << "Operation added successfully" << endl;
        system("pause");
    }
}

void BudgetManager::showCurrentMonthBalance()
{
    int startDate = DateMethods::getCurrentMonthFirstDayDate();
    int endDate = DateMethods::getCurrentDate();

    showBalance(startDate, endDate);
}

void BudgetManager::showPreviousMonthBalance()
{
    int startDate = DateMethods::getPreviousMonthFirstDayDate();
    int endDate = DateMethods::getPreviousMonthLastDayDate();

    showBalance(startDate, endDate);
}

void BudgetManager::showCustomPeriodBalance()
{
    string firstDate, secondDate;

    cout << "Enter the start date of the period (YYYY-MM-DD): ";
    firstDate = Utilities::readLine();
    while (!DateMethods::validateDate(firstDate))
    {
        cout << "Enter the start date of the period (YYYY-MM-DD): ";
        firstDate = Utilities::readLine();
    }

    cout << "Enter the end date of the period (YYYY-MM-DD): ";
    secondDate = Utilities::readLine();
    while (!DateMethods::validateDate(secondDate))
    {
        cout << "Enter the end date of the period (YYYY-MM-DD): ";
        secondDate = Utilities::readLine();
    }

    int startDate = DateMethods::convertStringDateToInt(firstDate);
    int endDate = DateMethods::convertStringDateToInt(secondDate);

    if (startDate <= endDate)
    {
        showBalance(startDate, endDate);
    }
    else
    {
        cout << "The start date must be earlier than the end date." << endl;
        system("pause");
    }
}
