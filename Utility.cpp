#ifndef UtilityH
#define UtilityH

int CharFrequency(std::string str, char c)
{
    int counter = 0;
    for ( int i = 0 ; i < str.size(); i++)
    {
        if (str[i] == c)
            counter++;
    }

    return counter;
}

int CharPos (std::string str, char c, int pos = 0)
{
    for (int i = pos ; i < str.size() ; i++)
    {
        if( str[i] == c )
            return i;
    }

    return -1;
}

bool IsDigit(std::string str)
{

    for (int i = 0 ; i < str.size() ; i++)
        if(!isdigit(str[i]))
            return false;
    return true;
}


#endif
