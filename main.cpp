#include <iostream>
#include "Person.h"
#include "Date.cpp"
using namespace std;


int main ()
{
    std::string s = "1000/1/1";
    Date someDate(100,111,1);
    cout << someDate << endl;
    cout << someDate.FailedToConstructValidDate();
    return 0;

}
