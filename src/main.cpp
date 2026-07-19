#include <iostream>
#include "../include/Login_screens/clsLoginScreen.h"

int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
    return 0;
}

