//
// Created by imad on 27/06/2026.
//

#ifndef PROJECT1L4BANKEXTENSION2_SHOWLOGSCREEN_H
#define PROJECT1L4BANKEXTENSION2_SHOWLOGSCREEN_H

#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class  clsLogScreen: public clsScreen
{
    private:

public:
    static void ShowLogScreen();
    {
       _DrawScreenHeader("\tLog Screen")
    }
};

#endif //PROJECT1L4BANKEXTENSION2_SHOWLOGSCREEN_H
