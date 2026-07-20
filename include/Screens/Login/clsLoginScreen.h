//
// Created by imad on 21/06/2026.
//

#ifndef PROJECT1L4BANKEXTENSION2_CLSLOGINSCREEN_H
#define PROJECT1L4BANKEXTENSION2_CLSLOGINSCREEN_H

#pragma once

#include <iostream>
#include "../Core/clsScreen.h"
#include "../Users/clsUser.h"
#include <iomanip>
#include "../clsMainScreen.h"
#include "../Core/Global.h"

class clsLoginScreen :protected clsScreen
{
private :
  static  bool _Login()
{
    bool LoginFaild = false;
    short FaildLoginCount = 0;

    string Username, Password;
    do
    {
        if (LoginFaild)
        {
            FaildLoginCount++;

            cout << "\nInvlaid Username/Password!\n\n";
            cout << "\nYou have " << (3-FaildLoginCount)
            << " Trial(s) to login.\n\n";
        }

        if (FaildLoginCount == 3)
        {
            cout << "\nYour are Locked after 3 faild trails \n\n";
            return false;
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

        CurrentUser = clsUser::Find(Username, Password);

        LoginFaild = CurrentUser.IsEmpty();

    } while (LoginFaild);

    CurrentUser.RegisterLogIn();
    clsMainScreen::ShowMainMenue();
    return true;
}

public:
    static bool ShowLoginScreen()
    {
        _ClearScreen();
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }
};
#endif //PROJECT1L4BANKEXTENSION2_CLSLOGINSCREEN_H