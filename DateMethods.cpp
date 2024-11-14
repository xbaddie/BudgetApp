#include "DateMethods.h"


void DateMethods::calculateCurrentDate(map<string, int> &currentDate)
{
    time_t t = time(nullptr);
    tm *now = localtime(&t);
    currentDate["year"] = now->tm_year + 1900;
    currentDate["month"] = now->tm_mon + 1;
    currentDate["day"] = now->tm_mday;
}

bool DateMethods::isYearLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

bool DateMethods::validateDate(string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        cout << "Improper date format, please try again." << endl;
        system("pause");
        return false;
    }

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    if (month < 1 || month > 12)
    {
        cout << "Improper month, please try again." << endl;
        system("pause");
        return false;
    }
    else if(year < 2000)
    {
        cout << "The entered date cannot be earlier than the year 2000." << endl;
        system("pause");
        return false;
    }

    int daysInMonth[] = {31, isYearLeap(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day >= 1 && day <= daysInMonth[month - 1])
    {
        return true;
    }
    else
    {
        cout << "Improper number of days in month, please try again." << endl;
        system("pause");
        return false;
    }

}

int DateMethods::convertStringDateToInt(const string &dateAsString)
{
    int dateConvertedToInt;
    string dateWithoutDashes;

    dateWithoutDashes = dateAsString.substr(0, 4) + dateAsString.substr(5, 2) + dateAsString.substr(8, 2);
    dateConvertedToInt = stoi(dateWithoutDashes);

    return dateConvertedToInt;
}

string DateMethods::convertIntDateToStringWithDashes(int dateAsInt)
{
    stringstream ss;
    ss << setw(4) << setfill('0') << dateAsInt / 10000 << "-"
       << setw(2) << setfill('0') << (dateAsInt / 100) % 100 << "-"
       << setw(2) << setfill('0') << dateAsInt % 100;
    return ss.str();
}

int DateMethods::getCurrentDate()
{
    map<string, int> currentDate;
    calculateCurrentDate(currentDate);

    stringstream ss;
    ss << setw(4) << setfill('0') << currentDate["year"]
       << setw(2) << setfill('0') << currentDate["month"]
       << setw(2) << setfill('0') << currentDate["day"];

    return stoi(ss.str());
}

int DateMethods::getCurrentMonthFirstDayDate()
{

}

int DateMethods::getPreviousMonthLastDayDate()
{

}

int DateMethods::getPreviousMonthFirstDayDate()
{

}
