#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


short ReadDay() {
    short Day;
    cout << "\nPlease enter a day: ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << "\nPlease enter a month: ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "\nPlease enter a year: ";
    cin >> Year;
    return Year;
}

short ReadDaysToAdd() {
    short Days;
    cout << "\nPlease enter number of days to add: ";
    cin >> Days;
    return Days;
}

struct sDate {
    short Day;
    short Month;
    short Year;
};

sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Checks if the year is a leap year
bool isLeapYear(short Year) {
    // A year is a leap year if divisible by 4 AND not 100, OR if divisible by 400
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}


// Returns the total number of days in a specific month
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;

    short days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year) {
    short totalDays = 0;
    for (short m = 1; m < Month; ++m) {
        totalDays += NumberOfDaysInAMonth(m, Year);
    }
    totalDays += Day;
    return totalDays;
}

sDate DateAddDays(short Days,sDate Date) 
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;
    while (true) 
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays) 
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12) 
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else 
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

int main() {
    sDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();
    Date = DateAddDays(Days, Date);

    cout << "\nDate after adding " << Days << " days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    system("pause>0");
    return 0;
}