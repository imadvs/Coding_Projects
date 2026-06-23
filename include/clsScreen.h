#pragma once
#include <cstdlib>
#include <iostream>
#include <limits>
#include "Manage_Users_Screen/clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected :
    static void _ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

    static void _PauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

    static void _DrawScreenHeader(string Title, string SubTitle = "")
{
    cout << "\t\t\t\t\t______________________________________";
    cout << "\n\n\t\t\t\t\t  " << Title;
    if (SubTitle != "")
    {
        cout << "\n\t\t\t\t\t  " << SubTitle;
    }
    cout << "\n\t\t\t\t\t______________________________________\n";
    cout << "\n\t\t\t\t\tUser: " << CurrentUser.GetUserName() << "\n";
    cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())
        << "\n\n";
}

    static bool CheckAccessRights(clsUser::enPermissions Permission)
{
    if (!CurrentUser.CheckAccessPermission(Permission))
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        return false;
    }
    else
    {
        return true;
    }
}
};

