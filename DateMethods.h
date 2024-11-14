#pragma once
#include <string>
#include <map>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

class DateMethods {
    static void calculateCurrentDate(map<string, int> &currentDate);
    static bool isYearLeap(int year);

public:
    static bool validateDate(string &date);
    static int convertStringDateToInt(const string &dateAsString);
    static string convertIntDateToStringWithDashes(int dateAsInt);
    static int getCurrentDate();
    static int getCurrentMonthFirstDayDate();
    static int getPreviousMonthLastDayDate();
    static int getPreviousMonthFirstDayDate();
};
