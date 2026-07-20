//
// Created by imad on 21/06/2026.
//

#ifndef PROJECT1L4BANKEXTENSION2_CLSFINDUSERSCREEN_H
#define PROJECT1L4BANKEXTENSION2_CLSFINDUSERSCREEN_H

#pragma once
#include <iostream>
#include "../Core/clsScreen.h"
#include "../Core/clsPerson.h"
#include "../../Core/clsUser.h"
#include "../Core/clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";
    }

public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");

        string UserName;
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }
        _PrintUser(User1);
    }
};
#endif //PROJECT1L4BANKEXTENSION2_CLSFINDUSERSCREEN_H