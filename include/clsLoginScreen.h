//
// Created by imad on 21/06/2026.
//

#ifndef PROJECT1L4BANKEXTENSION2_CLSLOGINSCREEN_H
#define PROJECT1L4BANKEXTENSION2_CLSLOGINSCREEN_H

#pragma once

#include <iostream>
#include "clsScreen.h"
#include "Manage_Users_Screen/clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{
private :
  static  void _Login()
{
    bool LoginFaild = false;

    string Username, Password;
    do
    {
        if (LoginFaild)
        {
            cout << "\nInvlaid Username/Password!\n\n";
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

        CurrentUser = clsUser::Find(Username, Password);

        LoginFaild = CurrentUser.IsEmpty();

    } while (LoginFaild);

    clsMainScreen::ShowMainMenue();
}

public:
    static void ShowLoginScreen()
    {
        _ClearScreen();
        _DrawScreenHeader("\t  Login Screen");
        _Login();
    }
};
#endif //PROJECT1L4BANKEXTENSION2_CLSLOGINSCREEN_H