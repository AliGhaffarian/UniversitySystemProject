#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "iostream"
#include "Utility.cpp"
#include "Person.h"
class Employee : public Person
{
protected:
    static int idCounter= 0 ;
    int employmentID;
public:
     Employee(std::string name , std::string lname , std:;string id ): Person (std::string name , std::string lname , std::string id)
    {
        idCounter++;
        employmentID = idCounter;
    }
    void RegisterStudent(vector<Student>& StudentList){}
    {
        std::string firstName , lastName , nationalID ;
        std::cout << "Enter firstname " << std::endl;
        std::cin >> firstName;
        std::cout << "Enter lastname " << std::endl;
        std::cin >> lastName;
        std::cout << "Enter national ID " << std::endl;
        std::cin >> nationalID;
        Student temp(firstName , lastName , nationalID);
        StudentList.push_back(temp);

    }
};
#endif // EMPLOYEE_H
