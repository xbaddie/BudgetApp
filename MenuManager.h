#pragma once

#include <string>
#include <iostream>

#include "Utilities.h"
#include "Operation.h"
#include "DateMethods.h"
#include "Type.h"
#include "CashMethods.h"


using namespace std;

class MenuManager
{

public:
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromUserMenu();
    static void addOperationDateMenu(Operation &operation);
    static void addOperationCategoryMenu(Operation &operation, const Type &type);
    static void addOperationAmountMenu(Operation &operation);
};
