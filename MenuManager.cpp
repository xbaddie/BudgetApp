#include "MenuManager.h"

char MenuManager::chooseOptionFromMainMenu()
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

char MenuManager::chooseOptionFromUserMenu()
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
    cout << "6. Change Password" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------" << endl;
    cout << "Choosment: ";
    choice = Utilities::getCharacter();

    return choice;
}

void MenuManager::addOperationDateMenu(Operation &operation)
{
    char choice;
    string inputDate;

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
}

void MenuManager::addOperationCategoryMenu(Operation &operation, const Type &type)
{
    char choice;

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
}

void MenuManager::addOperationAmountMenu(Operation &operation)
{
    string operationAmount;

    do
    {
        cout << "Please enter operation amount: ";
        operationAmount = Utilities::readLine();
    }
    while (!CashMethods::validateAmount(operationAmount));

    operation.amount = stod(operationAmount);
}


