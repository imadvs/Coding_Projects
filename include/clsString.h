//
// created by imad on 4/14/26.
//

#ifndef project1l4bankextension2_clsstring_h
#define project1l4bankextension2_clsstring_h

//programmingadvices.com
//mohammed abu-hadhoud

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class clsString
{
public:
    string value;

    clsString()
    {

        value = "";
    }
    clsString(string value)
    {

        value = value;
    }

    void setvalue(string value) {
        value = value;
    }
    string getvalue() {
        return value;
    }

    static short length(string s1)
    {
        return s1.length();
    };
    short length()
    {
        return value.length();
    };

    static short countwords(string s1)
    {

        string delim = " "; // delimiter
        short counter = 0;
        short pos = 0;
        string sword; // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = s1.find(delim)) != std::string::npos)
        {
            sword = s1.substr(0, pos); // store the word
            if (sword != "")
            {
                counter++;
            }

            //erase() until positon and move to next word.
            s1.erase(0, pos + delim.length());
        }

        if (s1 != "")
        {
            counter++; // it counts the last word of the string.
        }

        return counter;

    }
    short countwords()
    {
        return countwords(value);
    };

    static string upperfirstletterofeachword(string s1)
    {
        bool isfirstletter = true;

        for (short i = 0; i < s1.length(); i++)
        {
            if (s1[i] != ' ' && isfirstletter)
            {
                s1[i] = toupper(s1[i]);
            }
            isfirstletter = (s1[i] == ' ' ? true : false);
        }
        return s1;
    }
    void upperfirstletterofeachword()
    {
        // no need to return value , this function will directly update the object value
        value = upperfirstletterofeachword(value);
    }

    static string lowerfirstletterofeachword(string s1)
    {
        bool isfirstletter = true;

        for (short i = 0; i < s1.length(); i++)
        {
            if (s1[i] != ' ' && isfirstletter)
            {
                s1[i] = tolower(s1[i]);
            }
            isfirstletter = (s1[i] == ' ' ? true : false);
        }
        return s1;
    }
    void lowerfirstletterofeachword()
    {

        // no need to return value , this function will directly update the object value
        value = lowerfirstletterofeachword(value);
    }

    static string lowerallstring(string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = tolower(s1[i]);
        }
        return s1;
    }
    void lowerallstring()
    {
        value = lowerallstring(value);
    }

    static string upperallstring(string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = toupper(s1[i]);
        }
        return s1;
    }
    void upperallstring()
    {
        value = upperallstring(value);
    }

    static char invertlettercase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    static string  invertallletterscase(string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = invertlettercase(s1[i]);
        }
        return s1;
    }
    void  invertallletterscase()
    {
        value = invertallletterscase(value);
    }

    enum enwhattocount { capitalletters = 0, smallletters = 1, all = 2};

    static short countletters(string s1, enwhattocount what_to_count = enwhattocount::all)
    {
        short count = 0;
        for (short i = 0; i < s1.length(); i++)
        {
            if (what_to_count == all && isalpha(s1[i]))
                count++;
            else if (what_to_count == capitalletters && isupper(s1[i]))
                count++;
            else if (what_to_count == smallletters && islower(s1[i]))
                count++;
        }
        return count;
    }

    static short  countcapitalletters(string s1)
    {

        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (isupper(s1[i]))
                counter++;

        }

        return counter;
    }
    short  countcapitalletters()
    {
        return countcapitalletters(value);
    }

    static short  countsmallletters(string s1)
    {

        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (islower(s1[i]))
                counter++;

        }

        return counter;
    }
    short  countsmallletters()
    {
        return countsmallletters(value);
    }

    static short  countspecificletter(string s1, char letter, bool matchcase = true)
    {

        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (matchcase)
            {
                if (s1[i] == letter)
                    counter++;
            }
            else
            {
                if (tolower(s1[i]) == tolower(letter))
                    counter++;
            }

        }

        return counter;
    }
    short  countspecificletter( char letter, bool matchcase = true)
    {
        return countspecificletter(value,letter, matchcase);
    }

    static bool isvowel(char char1)
    {
        char1 = tolower(char1);
        return (char1 == 'a' || char1 == 'e' || char1 == 'i' || char1 == 'o' || char1 == 'u');
    }

    static short countvowels(string str1)
    {
        short counter = 0;
        for (short i = 0; i < str1.length(); i++)
        {
            if (isvowel(str1[i]))
            {
                counter++;
            }
        }
        return counter;
    }
    short countvowels()
    {
        return countvowels(value);
    }

    static vector <string> Split(string str1, string delim = " ")
    {
        vector <string> vstring;

        short pos = 0;
        string sword;

        while ((pos = str1.find(delim)) != string::npos)
        {
            sword = str1.substr(0, pos);
            if (sword != "")
            {
                vstring.push_back(sword);
            }
            str1.erase(0, pos + delim.length());
        }
        if (str1 != "")
        {
            vstring.push_back(str1);
        }
        return vstring;
    }
    vector <string> Split()
    {
        return Split(value, " ");
    }

    static string trimleft(string str1)
    {
        for (short i = 0; i < str1.length(); i++)
        {
            if (str1[i] != ' ')
            {
                return str1.substr(i, str1.length() - i);
            }
        }
        return "";
    }
    void trimleft()
    {
        value = trimleft(value);
    }

    static string trimright(string str1)
    {
        for (short i = str1.length() - 1; i >= 0; i--)
        {
            if (str1[i] != ' ')
            {
                return str1.substr(0, i + 1);
            }
        }
        return "";
    }
    void trimright()
    {
        value = trimright(value);
    }

    static string trim(string str1)
    {
        return trimleft(trimright(str1));
    }
    void trim()
    {
        value = trim(value);
    }

    static string joinstring(vector<string> vstrings, string delimiter)
    {
        string s1 = "";
        for (string& s : vstrings)
        {
            s1 = s1 + s + delimiter;
        }
        return s1.substr(0, s1.length() - delimiter.length());
    }
    static string joinstring(string arrstrings[], short length, string delimiter)
    {
        string s1 = "";
        for (int i = 0; i < length; i++)
        {
            s1 = s1 + arrstrings[i] + delimiter;
        }
        return s1.substr(0, s1.length() - delimiter.length());
    }

    static string reversewordsinstring(string s1)
    {
        vector <string> vstring;
        string s2 = "";

        vstring = Split(s1, " ");

        vector <string>::iterator iter = vstring.end();
        while (iter != vstring.begin())
        {
            iter--;
            s2 += *iter + " ";
        }
        s2 = s2.substr(0, s2.length() - 1);
        return s2;
    }
    void reversewordsinstring()
    {
        value = reversewordsinstring(value);
    }

    static string replaceword(string s1, string stringtoreplace, string srepalceto, bool matchcase = true)
    {

        vector<string> vstring = Split(s1, " ");

        for (string& s : vstring)
        {

            if (matchcase)
            {
                if (s == stringtoreplace)
                {
                    s = srepalceto;
                }

            }
            else
            {
                if (lowerallstring(s) == lowerallstring(stringtoreplace))
                {
                    s = srepalceto;
                }

            }

        }

        return joinstring(vstring, " ");
    }
    string replaceword(string stringtoreplace, string srepalceto)
    {
        return replaceword(value, stringtoreplace, srepalceto);
    }

    static string removepunctuations(string s1)
    {
        string s2 = "";

        for (short i = 0; i < s1.length(); i++)
        {
            if (!ispunct(s1[i]))
            {
                s2 += s1[i];
            }
        }
        return s2;
    }
    void removepunctuations()
    {
        value = removepunctuations(value);
    }
};
#endif //project1l4bankextension2_clsstring_h