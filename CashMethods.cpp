#include "CashMethods.h"

bool CashMethods::validateAmount(string &amount)
{
    bool hasDot = false;
    int decimalCount = 0;

    replaceComaWithPeriod(amount);

    for (char ch : amount)
    {
        if (hasDot) decimalCount++;
        if (decimalCount > 2)
        {
            cout << "Only 2 decimal places." << endl;
            return false;
        }
        if (!isdigit(ch))
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

void CashMethods::replaceComaWithPeriod(string &amount)
{
    for (char &ch : amount)
    {
        if (ch == ',')
        {
            ch = '.';
        }
    }
}

