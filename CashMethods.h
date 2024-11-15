#pragma once
#include <string>
#include <iostream>

using namespace std;

class CashMethods {

    static void replaceComaWithPeriod(string &amount);

public:
    static bool validateAmount(string &amount);
};
