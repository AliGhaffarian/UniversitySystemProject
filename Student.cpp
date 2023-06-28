#ifndef STUDENT_H
#define STUDENT_H
#include "iostream"
#include "Utility.cpp"
#include "Person.h"
struct studentInfo
{
    int studentID = -1;
    Date dateOfJoin = Date(0 , 0 , 0);
    vector <term> termList;
    float totallAverage;
};

struct term {
    vector <grade> gradeList;
    float termAverager;
};

struct grade
{
   std::string name;
   float score;
};
class Student:public Person {
protected:
    static int idCounter = 0 ;
    studentInfo studentinfo;
public:
    Student()
    {
        idCounter++;
        studentInfo.studentID = idCounter;
    }
    Student(std::string name , std::string lname , std:;string id , Date join ): Person (std::string name , std::string lname , std::string id)
    {
        idCounter++;
        studentInfo.studentID = idCounter;
        dateof
    }
    void Report(){}



};
#endif // STUDENT_H
