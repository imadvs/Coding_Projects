#include <iostream>

using namespace std;


short ReadDay() {
    short Day;
    cout << "\n\nPlease enter a day: ";
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

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}


short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;

    short days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}


bool IsItLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}


bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDayByOneDay(sDate Date)
{
    if (IsItLastDayInMonth(Date))
    {
        Date.Day = 1;
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
    Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
    Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool
IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDayByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

sDate GetsystemDate()
{
    sDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Day = now->tm_mday;
    Date.Month = now->tm_mon + 1;
    Date.Year = now->tm_year + 1900;

    return Date;
}

int main() {
    sDate Date1 = ReadFullDate();
    sDate Date2 = GetsystemDate();

    cout << "\n\nDifference in days is: " << GetDifferenceInDays(Date1, Date2, true);

    system("pause>0");
    return 0;
}