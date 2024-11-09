#pragma once
#include <string>

using namespace std;

class DateMethods {
    const string FILE_NAME;
    void calculateCurrentDate(map<string, int> &currentDate);
    int sYearLeap(int year);

public:
    bool validateDate(string &date);
    int convertStringDateToInt(const string &dateAsString);
    string convertIntDateToStringWithDashes(int dateAsInt);
    int getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getPreviousMonthLastDayDate();
    int getPreviousMonthFirstDayDate();
};
