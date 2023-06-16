#ifndef DateH
#define DateH
#include <iostream>
#include <string>
class Date
{


    int day;
    int month;
    int year;

public:

    Date(){}
    Date(int year, int month, int day)
    {

    }
    Date (const std::string& dateStr)
    {
        *this = StrToDate(dateStr);
    }

    Date StrToDate(const std::string& dateStr)
    {
        if(!StrIncludesDate(dateStr))
            return Date();
    }

    bool IsDay(int day)
    {
        if(day <= 31 && day >=1)
            return true;
        return false;
    }

    bool IsMonth(int month)
    {
        if(month <= 12 && month >=1)
            return true;
        return false;
    }

    bool IsYear(int year)
    {
        if(year >=0)
            return true;
        return false;
    }

    bool IsDigit(std::string str)
    {
        for (int i = 0 ; i < str.size() ; i++)
            if(!isdigit(str[i]))
                return false;
        return true;
    }

    bool StrIncludesDate(const std::string& dateStr)
    {

        if (dateStr[4] != '/')
            return false;
        if (dateStr[6] != '/')
            return false;

        if (!IsDigit(dateStr.substr(0, 4)))
            return false;
        if (!IsDigit(dateStr.substr(5, 6)))
            return false;
        if (!IsDigit(dateStr.substr(7)))
            return false;

    }
};
#endif //Date
