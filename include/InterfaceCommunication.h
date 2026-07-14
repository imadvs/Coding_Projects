//
// Created by imad on 12/07/2026.
//

#ifndef P03_BANK_SYSTEM_INTERFACECOMMUNICATION_H
#define P03_BANK_SYSTEM_INTERFACECOMMUNICATION_H

#pragma once
#include <iostream>
#include <string>
using namespace std;

class InterfaceCommunication
{
public:
    virtual void SendEmail(string Title, string Body) = 0;
    virtual void SendFax(string Title, string Body) = 0;
    virtual void SendSMS(string Title, string Body) = 0;
};

#endif //P03_BANK_SYSTEM_INTERFACECOMMUNICATION_H
