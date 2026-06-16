//
// Created by imad on 4/29/26.
//

#ifndef PROJECT1L4BANKEXTENSION2_CLSSCREEN_H
#define PROJECT1L4BANKEXTENSION2_CLSSCREEN_H



#pragma once
#include <iostream>


using namespace std;

class clsScreen
{
protected :
    static void _DrawScreenHeader(string Title,string SubTitle ="")
{
    cout << "\t\t\t\t\t______________________________________";
    cout << "\n\n\t\t\t\t\t  " << Title;
    if (SubTitle != "")
    {
        cout << "\n\t\t\t\t\t  " << SubTitle;
    }
    cout << "\n\t\t\t\t\t______________________________________\n\n";
}


};



#endif //PROJECT1L4BANKEXTENSION2_CLSSCREEN_H