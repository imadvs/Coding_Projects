//
// Created by imad on 4/29/26.
//

#ifndef PROJECT1L4BANKEXTENSION2_CLSMAINSCREEN_H
#define PROJECT1L4BANKEXTENSION2_CLSMAINSCREEN_H


#pragma once
#include <iostream>
#include <iomanip>
#include <limits>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenueOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
        eExit = 8
    };

    static void _ClearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        cout << "\033[2J\033[H";
#endif
    }

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1,8,"Enter Number between 1 to 8? ");
        return Choice;
    }

    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << ""
             << "\n\tPress Enter to go back to Main Menue...\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        //  cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        cout << "\nDelete Client Screen Will be here...\n";
    }

    static void _ShowUpdateClientScreen()
    {
        cout << "\nUpdate Client Screen Will be here...\n";
    }

    static void _ShowFindClientScreen()
    {
        cout << "\nFind Client Screen Will be here...\n";
    }

    static void _ShowTransactionsMenue()
    {
        cout << "\nTransactions Menue Will be here...\n";
    }

    static void _ShowManageUsersMenue()
    {
        cout << "\nUsers Menue Will be here...\n";
    }

    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
            _ClearScreen();
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eAddNewClient:
            _ClearScreen();
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eDeleteClient:
            _ClearScreen();
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eUpdateClient:
            _ClearScreen();
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eFindClient:
            _ClearScreen();
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eShowTransactionsMenue:
            _ClearScreen();
            _ShowTransactionsMenue();
            break;
        case enMainMenueOptions::eManageUsers:
            _ClearScreen();
            _ShowManageUsersMenue();
            break;
        case enMainMenueOptions::eExit:
            _ClearScreen();
            _ShowEndScreen();
            // Login();
            break;
        }
    }

public:

    static void ShowMainMenue()
    {
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption(static_cast<enMainMenueOptions>(_ReadMainMenueOption())
        );
    }
};

#endif // PROJECT1L4BANKEXTENSION2_CLSMAINSCREEN_H