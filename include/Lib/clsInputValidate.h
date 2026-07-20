#ifndef PROJECT1L4BANKEXTENSION2_CLSINPUTVALIDATE_H
#define PROJECT1L4BANKEXTENSION2_CLSINPUTVALIDATE_H
#include "../Core/clsDate.h"
#include <limits>

using namespace std;

class clsInputValidate {
public:
    template <typename T>
    static bool IsNumberBetween(T Number, T from, T to) {
        if (Number >= from && Number <= to) return true;
        else return false;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
        //Date>=From && Date<=To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
            &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
        ) {
            return true;
        }

        //Date>=To && Date<=From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
            &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
        ) {
            return true;
        }

        return false;
    }

    // Replaces ReadShortNumber, ReadIntNumber, ReadFloatNumber, ReadDblNumber
    template<typename T>
    static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
        T Number;
        while (!(cin >> Number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    // Replaces ReadShortNumberBetween, ReadIntNumberBetween, ReadFloatNumberBetween, ReadDblNumberBetween
    template<typename T>
    static T ReadNumberBetween(T From, T To,
                               string ErrorMessage = "Number is not within range, Enter again:\n") {
        T Number = ReadNumber<T>();

        while (!IsNumberBetween(Number, From, To)) {
            cout << ErrorMessage;
            Number = ReadNumber<T>();
        }
        return Number;
    }

    static bool IsValideDate(clsDate Date) {
        return clsDate::IsValidDate(Date);
    }

    static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
        return ReadNumber<float>(ErrorMessage);
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
        return ReadNumber<double>(ErrorMessage);
    }

    static short ReadShortNumberBetween(short From, short To,
                                        string ErrorMessage = "Number is not within range, Enter again:\n") {
        return ReadNumberBetween<short>(From, To, ErrorMessage);
    }

    static float ReadFloatNumberBetween(float From, float To,
                                        string ErrorMessage = "Number is not within range, Enter again:\n") {
        return ReadNumberBetween<float>(From, To, ErrorMessage);
    }

    static double ReadDblNumberBetween(double From, double To,
                                       string ErrorMessage = "Number is not within range, Enter again:\n") {
        return ReadNumberBetween<double>(From, To, ErrorMessage);
    }

    static string ReadString() {
        string S1 = "";
        getline(cin >> ws, S1);
        return S1;
    }
};
#endif //PROJECT1L4BANKEXTENSION2_CLSINPUTVALIDATE_H
