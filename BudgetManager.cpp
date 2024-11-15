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

    cout << (type == INCOME ? "Please choose income category:" : "Please choose expense category:") << endl;
    cout << (type == INCOME ? "1. Salary" : "1. Bills") << endl;
    cout << (type == INCOME ? "2. Internet Sales" : "2. Food") << endl;
    cout << (type == INCOME ? "3. Return on investment"  : "3. Investments") << endl;
    cout << "4. Other" << endl;

    choice = Utilities::getCharacter();
    switch (choice)
    {
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
    double sum = 0;
    vector<Operation> operations = (type == INCOME) ? incomes : expenses;

    sort(operations.begin(), operations.end(), [](const Operation &a, const Operation &b) {
        return a.date < b.date;
    });

    for (const Operation &operation : operations) {
        if (operation.date >= startDate && operation.date <= endDate) {
            cout << "ID: " << operation.id << " Transaction date: " << operation.date << " Operation: " << operation.item << " Amount: " << operation.amount << endl;
            sum += operation.amount;
        }
    }
    return sum;
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
