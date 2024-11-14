#pragma once
#include <string>

#include "OperationFile.h"
#include "Operation.h"
#include "Type.h"
#include "Utilities.h"
#include "DateMethods.h"
#include "CashMethods.h"

using namespace std;

class BudgetManager
{
    const int LOGGED_USER_ID;
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation addOperationDetails(const Type &type);
    void showBalance(int startDate, int endDAte);
    double calculateBalance(int startDate, int endDate, const Type &type);



public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId)
        : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId)
    {
        incomes = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();

};
