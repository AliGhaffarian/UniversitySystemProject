#include <iostream>
#include "Person.h"
#include "Date.cpp"
#include "Course.cpp"
using namespace std;


int main ()
{
    std::string s = "1000/1/1";
    Date someDate(100,111,11);
    cout << someDate << endl;
    cout << someDate.FailedToConstructValidDate();
    return 0;

}
