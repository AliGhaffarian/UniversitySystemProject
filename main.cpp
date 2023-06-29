#include <iostream>
#include "Employee.cpp"
#include "Teacher.cpp"
using namespace std;


int main()
{
    Teacher a;
    Person *h;
    Student S;
    h = &S;
    std::vector<Course> courseList;
    std::string s = "1000/1/1";
    Date someDate(100, 111, 11);
    cout << someDate << endl;
    cout << someDate.FailedToConstructValidDate();
    return 0;

}
