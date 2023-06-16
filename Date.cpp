#ifndef DateH
#define DateH
#include <iostream>
#include <string>

#include "Utility.cpp"

class Date
{
    friend std::ostream& operator << (std::ostream& output, const Date& date)
    {
        output << date.year << '/' << date.month << '/' << date.day;
        return output;
    }

    friend std::istream& operator >> (std::istream& input, Date& date)
    {
        std::string dateStr;

        input >> dateStr;

        date = Date(dateStr);

        return input;
    }

    int day;
    int month;
    int year;

public:

    Date()
    {
    }

    Date(const Date& date)
    {
        this->year = date.year;
        this->month = date.month;
        this->day = date.day;
    }

    Date(int year, int month, int day)
    {
        SetYear(year);
        SetMonth(month);
        SetDay(day);
    }
    Date (const std::string& dateStr)
    {
        *this = Date(StrToDate(dateStr));
    }

    Date StrToDate(const std::string& dateStr)
    {
        if(!StrIncludesDate(dateStr))
            return Date();

        int firstSlashPos = CharPos(dateStr, '/', 0);
        int secondSlashPosh = CharPos(dateStr, '/', firstSlashPos + 1 );

        return Date(stoi(dateStr.substr(0, firstSlashPos)), stoi(dateStr.substr(firstSlashPos + 1, secondSlashPosh - firstSlashPos - 1)), stoi(dateStr.substr( secondSlashPosh + 1)));

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

    void SetDay(int day)
    {
        this->day = IsDay(day)? day : -1;
    }

    void SetMonth(int month)
    {
        this->month = IsMonth(month) ? month : -1;
    }

    void SetYear(int year)
    {
        this->year = IsYear(year) ? year : -1;
    }

    bool FailedToConstructValidDate(const Date& date)
    {
        return (date.day == -1 || date.month == -1 || date.year == -1);
    }


    bool FailedToConstructValidDate()
    {
        return (this->day == -1 || this->month == -1 || this->year == -1);
    }

    bool StrIncludesDate(const std::string& dateStr)
    {

        if(CharFrequency(dateStr, '/') != 2)
            return 0;

        int firstSlashPos = CharPos(dateStr, '/', 0);
        int secondSlashPos = CharPos(dateStr, '/', firstSlashPos + 1);

        return (   IsDigit(dateStr.substr(0, firstSlashPos))
                && IsDigit(dateStr.substr(firstSlashPos + 1, secondSlashPos - firstSlashPos - 1))
                && IsDigit(dateStr.substr(secondSlashPos + 1))
                );
    }
};
#endif //Date
