#include "CashMethods.h"

bool CashMethods::validateAmount(string &amount)
{
    string modifiedAmount = amount;
    for (char &ch : modifiedAmount)
    {
        if (ch == ',')
        {
            ch = '.';
        }
    }

    bool hasDot = false;
    int decimalCount = 0;
    for (char ch : modifiedAmount)
    {
        if (hasDot) decimalCount++;
        if (decimalCount > 2)
        {
            cout << "Only 2 decimal places." << endl;
            return false;
        }
        if (isdigit(ch) == 0)
        {
            if (ch == '.' && !hasDot)
            {
                hasDot = true;
            }
            else
            {
                cout << "Invalid amount, please try again." << endl;
                return false;
            }
        }
    }

    return true;
}

