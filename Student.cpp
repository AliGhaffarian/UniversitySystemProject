#ifndef STUDENT_H
#define STUDENT_H
#include "iostream"
#include "Person.cpp"

struct grade
{
    std::string name;//set
    float score;//set
};

struct term {
    std::vector<grade> gradeList;//set
    float termAverage;//set
};

struct studentInfo
{
    int studentID = -1;
    Date dateOfJoin = Date(0, 0, 0);
    std::vector<term> termList;//set
    float totallAverage;
};

class Student :public Person
{

    const Student& operator = (const Student& right)
    {

          this->studentinfo.dateOfJoin = right.studentinfo.dateOfJoin;
          this->studentinfo.studentID = right.studentinfo.studentID;
          this->studentinfo.termList.resize(right.studentinfo.termList.size());
          for (int i = 0; i < right.studentinfo.termList.size(); i++)
          {
            this->studentinfo.termList[i].gradeList = right.studentinfo.termList[i].gradeList;
            this->studentinfo.termList[i].termAverage = right.studentinfo.termList[i].termAverage;
          }
          this->studentinfo.totallAverage = right.studentinfo.totallAverage;

        return *this;
    }

protected:
    static int idCounter;
    studentInfo studentinfo;
//----------------------------------------------------------------------------------------------------------------
public:
    Student()//default
    {
        personInfo.type = 1;
        idCounter++;
        this->studentinfo.studentID = idCounter;
    }
//----------------------------------------------------------------------------------------------------------------
    Student(const Student& right)//copy
    {
        this->studentinfo.dateOfJoin = right.studentinfo.dateOfJoin;
        this->studentinfo.studentID = right.studentinfo.studentID;
        this->studentinfo.termList.resize(right.studentinfo.termList.size());
        for (int i = 0; i < right.studentinfo.termList.size(); i++)
        {
        this->studentinfo.termList[i].gradeList = right.studentinfo.termList[i].gradeList;
        this->studentinfo.termList[i].termAverage = right.studentinfo.termList[i].termAverage;
        }
        this->studentinfo.totallAverage = right.studentinfo.totallAverage;
    }
//----------------------------------------------------------------------------------------------------------------
    Student(std::string name, std::string lname, std::string id, Date join) : Person( name, lname, id)
    {
         idCounter++;
        this->studentinfo.studentID = idCounter;
    }
//----------------------------------------------------------------------------------------------------------------
    void SetGrade(float grade , std::string name , int termnum)
    {
        if(grade >= 0 && grade <=20)
        {
           this->studentinfo.termList[termnum].gradeList.resize(this->studentinfo.termList[termnum].gradeList.size() + 1);
           this->studentinfo.termList[termnum].gradeList[this->studentinfo.termList[termnum].gradeList.size() - 1].name = name;
           this->studentinfo.termList[termnum].gradeList[this->studentinfo.termList[termnum].gradeList.size() - 1].score = grade;
        }
    }
//----------------------------------------------------------------------------------------------------------------
    void SetTerm(int termnum)
    {
        this->studentinfo.termList.resize(this->studentinfo.termList.size() + 1);
    }
//----------------------------------------------------------------------------------------------------------------
    void pure() {}
//----------------------------------------------------------------------------------------------------------------
    void Report()
    {
    }
//----------------------------------------------------------------------------------------------------------------
    int CourseInTerm(std::string courseName)
    {
        for(int i = 0 ; i < studentinfo.termList.size() ; i++)
        {
            for( int j = 0 ; j < studentinfo.termList[i].gradeList.size() ; j++ )
            {
                if(studentinfo.termList[i].gradeList[j].name == courseName)
                {
                    return i;
                }
            }
        }
        return -1;
    }
//----------------------------------------------------------------------------------------------------------------
    int FindCours(std::string courseName)
    {
        int temp = CourseInTerm(courseName);
        for( int i = 0 ; i<studentinfo.termList[temp].gradeList.size() ; i++)
        {
            if(studentinfo.termList[temp].gradeList[i].name == courseName)
            {
                return i;
            }
        }
        return -1;
    }
};
int Student::idCounter = 0;
#endif // STUDENT_H
