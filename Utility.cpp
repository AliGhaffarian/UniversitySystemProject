#ifndef UtilityH
#define UtilityH
#include "Person.cpp"
#include <vector>
#include <iostream>
#include "Course.cpp"
int CharFrequency(std::string str, char c)
{
    int counter = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == c)
            counter++;
    }

    return counter;
}

int CharPos(std::string str, char c, int pos = 0)
{
    for (int i = pos; i < str.size(); i++)
    {
        if (str[i] == c)
            return i;
    }

    return -1;
}

bool IsDigit(std::string str)
{

    for (int i = 0; i < str.size(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

bool IsName(const std::string& name)
{
    return (name.size() > 0 && !IsDigit(name));
}

int SearchTeacher()
{
    return 1;
}

int SearchCourse()
{
    return 1;
}
#endif
