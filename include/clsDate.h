#ifndef PROJECT1L4BANKEXTENSION2_CLSDATE_H
#define PROJECT1L4BANKEXTENSION2_CLSDATE_H

#pragma once
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class clsDate {
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

    // Helper for string splitting (Teacher uses a separate clsString, we keep it internal or use this)
    static vector<string> _Split(string Str, string Delim) {
        short Pos = 0;
        string word = "";
        vector<string> VWords;
        while ((Pos = Str.find(Delim)) != std::string::npos) {
            word = Str.substr(0, Pos);
            if (word != "") VWords.push_back(word);
            Str.erase(0, Pos + Delim.length());
        }
        if (Str != "") VWords.push_back(Str);
        return VWords;
    }

public:
    enum enDateCompare { Before = -1, Equal = 0, After = 1 };

    // --- Constructors ---
    clsDate() {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    clsDate(string sDate) {
        vector<string> vDate = _Split(sDate, "/");
        if (vDate.size() >= 3) {
            _Day = (short)stoi(vDate[0]);
            _Month = (short)stoi(vDate[1]);
            _Year = (short)stoi(vDate[2]);
        }
    }

    clsDate(short Day, short Month, short Year) {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(short DateOrderInYear, short Year) {
        clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = Date1.GetDay();
        _Month = Date1.GetMonth();
        _Year = Date1.GetYear();
    }


    // --- Month Increase ---
    static clsDate AddOneMonth(clsDate Date) {
        if (Date.GetMonth() == 12) {
            Date.SetMonth(1);
            Date.SetYear(Date.GetYear() + 1);
        } else {
            Date.SetMonth(Date.GetMonth() + 1);
        }
        // Clamp the day if the new month has fewer days (e.g. Jan 31 -> Feb 28)
        short maxDay = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() > maxDay)
            Date.SetDay(maxDay);
        return Date;
    }

    void IncreaseDateByOneMonth() { *this = AddOneMonth(*this); }

    // --- Age Calculator ---
    static int CalculateMyAgeInDays(clsDate BirthDate) {
        clsDate Today;
        return GetDifferenceInDays(BirthDate, Today, true);
    }


    static void SwapDates(clsDate& Date1, clsDate& Date2) {
        clsDate Temp = Date1;
        Date1 = Date2;
        Date2 = Temp;
    }


    // --- Accessors (Standard C++ compatible) ---
    void SetDay(short Day) { _Day = Day; }
    short GetDay() const { return _Day; }

    void SetMonth(short Month) { _Month = Month; }
    short GetMonth() const { return _Month; }

    void SetYear(short Year) { _Year = Year; }
    short GetYear() const { return _Year; }

    // --- Static Utility Methods (Leap Year & Month Days) ---
    static bool isLeapYear(short Year) {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear() const { return isLeapYear(_Year); }

    static short NumberOfDaysInAMonth(short Month, short Year) {
        if (Month < 1 || Month > 12) return 0;
        int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : (short)days[Month - 1];
    }

    short NumberOfDaysInAMonth() const { return NumberOfDaysInAMonth(_Month, _Year); }

    // --- Calendar & Names ---
    static short DayOfWeekOrder(short Day, short Month, short Year) {
        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    short DayOfWeekOrder() const { return DayOfWeekOrder(_Day, _Month, _Year); }

    static string MonthShortName(short MonthNumber) {
        string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return Months[MonthNumber - 1];
    }

    string MonthShortName() const { return MonthShortName(_Month); }

    static string DayShortName(short DayOrder) {
        string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        return arrDayNames[DayOrder];
    }

    string DayShortName() const { return DayShortName(DayOfWeekOrder()); }

    // --- Calculations ---
    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
        short TotalDays = 0;
        for (int i = 1; i <= Month - 1; i++) TotalDays += NumberOfDaysInAMonth(i, Year);
        TotalDays += Day;
        return TotalDays;
    }

    short DaysFromTheBeginingOfTheYear() const { return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year); }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
        clsDate Date(1, 1, Year);
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;
        while (true) {
            MonthDays = NumberOfDaysInAMonth(Date.GetMonth(), Year);
            if (RemainingDays > MonthDays) {
                RemainingDays -= MonthDays;
                Date.SetMonth(Date.GetMonth() + 1);
            } else {
                Date.SetDay(RemainingDays);
                break;
            }
        }
        return Date;
    }

    // --- Comparisons ---
    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {
        return (Date1.GetYear() < Date2.GetYear()) ? true :
               ((Date1.GetYear() == Date2.GetYear()) ?
                (Date1.GetMonth() < Date2.GetMonth() ? true :
                 (Date1.GetMonth() == Date2.GetMonth() ? Date1.GetDay() < Date2.GetDay() : false)) : false);
    }

    bool IsBefore(clsDate Date2) const { return IsDate1BeforeDate2(*this, Date2); }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
        return (Date1.GetYear() == Date2.GetYear() && Date1.GetMonth() == Date2.GetMonth() && Date1.GetDay() == Date2.GetDay());
    }

    bool IsEqual(clsDate Date2) const { return IsDate1EqualDate2(*this, Date2); }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }

    bool IsAfter(clsDate Date2) const { return IsDate1AfterDate2(*this, Date2); }

    // --- Increase / Decrease Logic ---
    static clsDate AddOneDay(clsDate Date) {
        if (Date.GetDay() == NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear())) {
            if (Date.GetMonth() == 12) {
                Date.SetMonth(1); Date.SetDay(1); Date.SetYear(Date.GetYear() + 1);
            } else {
                Date.SetDay(1); Date.SetMonth(Date.GetMonth() + 1);
            }
        } else {
            Date.SetDay(Date.GetDay() + 1);
        }
        return Date;
    }

    void IncreaseDateByOneDay() { *this = AddOneDay(*this); }

    static clsDate DecreaseDateByOneDay(clsDate Date) {
        if (Date.GetDay() == 1) {
            if (Date.GetMonth() == 1) {
                Date.SetMonth(12); Date.SetDay(31); Date.SetYear(Date.GetYear() - 1);
            } else {
                Date.SetMonth(Date.GetMonth() - 1);
                Date.SetDay(NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear()));
            }
        } else {
            Date.SetDay(Date.GetDay() - 1);
        }
        return Date;
    }

    void DecreaseDateByOneDay() { *this = DecreaseDateByOneDay(*this); }

    // Example of Bulk Increase
    void IncreaseDateByXDays(short Days) {
        for (short i = 1; i <= Days; i++) IncreaseDateByOneDay();
    }

    // --- Difference ---
    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
        int Days = 0;
        short SwapFlagValue = 1;
        if (!IsDate1BeforeDate2(Date1, Date2)) {
            clsDate Temp = Date1; Date1 = Date2; Date2 = Temp; // Simple swap
            SwapFlagValue = -1;
        }
        while (IsDate1BeforeDate2(Date1, Date2)) {
            Days++;
            Date1 = AddOneDay(Date1);
        }
        return IncludeEndDay ? (++Days * SwapFlagValue) : (Days * SwapFlagValue);
    }

    // --- Weekend Logic ---
    static bool IsWeekEnd(clsDate Date) {
        short DayIndex = DayOfWeekOrder(Date.GetDay(), Date.GetMonth(), Date.GetYear());
        return (DayIndex == 5 || DayIndex == 6); // Fri and Sat
    }

    bool IsWeekEnd() const { return IsWeekEnd(*this); }

    static bool IsBusinessDay(clsDate Date) {
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay() const { return IsBusinessDay(*this); }

    // --- Validation ---
    static bool IsValidDate(clsDate Date) {
        if (Date.GetMonth() < 1 || Date.GetMonth() > 12) return false;
        short DaysInMonth = NumberOfDaysInAMonth(Date.GetMonth(), Date.GetYear());
        if (Date.GetDay() < 1 || Date.GetDay() > DaysInMonth) return false;
        return true;
    }

    bool IsValid() const { return IsValidDate(*this); }

    // --- Print ---
    static string DateToString(clsDate Date) {
        return to_string(Date.GetDay()) + "/" + to_string(Date.GetMonth()) + "/" + to_string(Date.GetYear());
    }

    string DateToString() const { return DateToString(*this); }

    string ToString() const { return DateToString(*this); }

    void Print() const { cout << ToString() << endl; }

    static void PrintMonthCalendar(short Month, short Year) {
        int current = DayOfWeekOrder(1, Month, Year);
        int numberOfDays = NumberOfDaysInAMonth(Month, Year);
        printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        int i;
        for (i = 0; i < current; i++) printf("     ");
        for (int j = 1; j <= numberOfDays; j++) {
            printf("%5d", j);
            if (++i == 7) { i = 0; printf("\n"); }
        }
        printf("\n  _________________________________\n");
    }

    void PrintMonthCalendar() const { PrintMonthCalendar(_Month, _Year); }

    void PrintYearCalendar() const {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", _Year);
        printf("  _________________________________\n");
        for (int i = 1; i <= 12; i++) PrintMonthCalendar(i, _Year);
    }
};
#endif //PROJECT1L4BANKEXTENSION2_CLSDATE_H