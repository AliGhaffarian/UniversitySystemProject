#ifndef STUDENT_H
#define STUDENT_H
#include "iostream"
#include "Person.cpp"

struct grade
{
    std::string name = "InvalidCourseName";//set
    float score = -1;//set
};

struct term
{
    std::vector<grade> gradeList;//set
    float termAverage = -1;//set
    int currentunits = -1;
};

struct studentInfo
{
    std::string studentMajor = "InvalidMajor";
    int studentID = -1;
    Date dateOfJoin = Date(0, 0, 0);
    std::vector<term> termList;//set
    float totallAverage;
};

class Student : public Person
{
    friend class Teacher;
    friend class Employee;
    const Student& operator = (const Student& right)
    {
          this->personInfo.firstName = right.personInfo.firstName;
          this->personInfo.LastName = right.personInfo.LastName;
          this->personInfo.dateOfBirth = right.personInfo.dateOfBirth ;
          this->personInfo.nationalID = right.personInfo.nationalID ;
          this->studentinfo.dateOfJoin = right.studentinfo.dateOfJoin;
          this->studentinfo.studentID = right.studentinfo.studentID;
          this->studentinfo.termList.resize(right.studentinfo.termList.size());
          for (int i = 0; i < right.studentinfo.termList.size(); i++)
          {
            this->studentinfo.termList[i].gradeList.resize(right.studentinfo.termList[i].gradeList.size());
            for(int j = 0 ; j < right.studentinfo.termList[i].gradeList.size() ; j++ )
            {
                this->studentinfo.termList[i].gradeList[j].score = right.studentinfo.termList[i].gradeList[j].score;
                this->studentinfo.termList[i].gradeList[j].name = right.studentinfo.termList[i].gradeList[j].name;
            }
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
        *this = right;
    }
//----------------------------------------------------------------------------------------------------------------
    Student(std::string name, std::string lname, std::string id, Date join) : Person( name, lname, id)
    {
         personInfo.type = 1;
         idCounter++;
        this->studentinfo.studentID = idCounter;
    }
//----------------------------------------------------------------------------------------------------------------
    void SetCourseName(std::string name )
    {
        int termSize = this->studentinfo.termList.size() - 1;
        int courseSize = this->studentinfo.termList[termSize].gradeList.size();
        this->studentinfo.termList[termSize].gradeList.resize(courseSize + 1);
        this->studentinfo.termList[termSize].gradeList[courseSize].name = name;
    }
//----------------------------------------------------------------------------------------------------------------
    void RegisterGrade(float gradee , std::string name , int termIndex) //for add a course to student
    {
        if(gradee >= 0 && gradee <=20 && !IsDigit(name))
        {
           grade temp;
           temp.name = name ;
           temp.score = gradee ;
           this->studentinfo.termList[termIndex].gradeList.push_back(temp);
        }
    }
//----------------------------------------------------------------------------------------------------------------
    void SetGrade(int termIndex , float termGrade , int gradeIndex )
    {

        this->studentinfo.termList[termIndex].gradeList[gradeIndex].score = termGrade;

    }
//----------------------------------------------------------------------------------------------------------------
    void SetTerm()
    {
         std::cout<<this->personInfo.firstName <<"  "<< this->studentinfo.termList.size() << "\n\n";
        this->studentinfo.termList.resize(this->studentinfo.termList.size() + 1);
        std::cout<< this->studentinfo.termList.size();
    }
//----------------------------------------------------------------------------------------------------------------
    void SetMajor(std::string& major)
    {
        if(!IsDigit(major))
        {
            major[0] = toupper(major[0]);
            this->studentinfo.studentMajor = major;
        }
    }
//----------------------------------------------------------------------------------------------------------------
    std::string GetMajor()
    {
        return this->studentinfo.studentMajor;
    }
//---------------------------------------------------------------------------------------------------------------

    void pure() {}
//----------------------------------------------------------------------------------------------------------------
    void Report(int termIndex)
    {
        if(termIndex <= this->studentinfo.termList.size())
     {
         termIndex--;
         std::cout<< this->studentinfo.termList[termIndex].gradeList.size();
        for(int i = 0 ; i < this->studentinfo.termList[termIndex].gradeList.size() ; i++)
        {
            std::cout<< "\n\n sdgsagsadgasg \n" ;
            std::cout<< "Course name : " << this->studentinfo.termList[termIndex].gradeList[i].name
            << "\t grade : " << this->studentinfo.termList[termIndex].gradeList[i].score<<"\n";
        }
     }
     else
        std::cout<< "term is not available \n";
     getchar();
     getchar();
    }
//----------------------------------------------------------------------------------------------------------------
    int CourseInTerm(std::string courseName)// find index of the term which have the course in itself
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
    int FindCours(std::string courseName) //find index of course
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
//----------------------------------------------------------------------------------------------------------------
    studentInfo GetStudent()
    {
        return studentinfo;
    }
//----------------------------------------------------------------------------------------------------------------
     int FindeCourseUnit(std::vector<Course>courseList , std::string name)
     {
         for(int i = 0 ; i < courseList.size() ; i++)
         {
             if(courseList[i].courseInfo.name == name)
                return courseList[i].courseInfo.unit;
         }
         return -1;
     }
//----------------------------------------------------------------------------------------------------------------
     void AverageCalculate(int termIndex ,std::vector<Course>courseList)
     {
         float tempGrade = 0;
         float tempSumOfUnits =0;
         for(int i = 0 ; i < this->studentinfo.termList[termIndex].gradeList.size() ; i++)
         {
             int tempUnit=FindeCourseUnit(courseList ,studentinfo.termList[termIndex].gradeList[i].name );
             tempGrade += this->studentinfo.termList[termIndex].gradeList[i].score*tempUnit;
             tempSumOfUnits +=tempGrade;
         }
         this->studentinfo.termList[termIndex].currentunits = tempSumOfUnits;
         this->studentinfo.termList[termIndex].termAverage = tempGrade/tempSumOfUnits;
     }
//----------------------------------------------------------------------------------------------------------------
     void TotallAverage ()
     {
         float temp = 0;
         for(int i = 0 ; i < this->studentinfo.termList.size() ;i ++)
         {
             temp += this->studentinfo.termList[i].termAverage;
         }
         this->studentinfo.totallAverage = temp;
     }
//----------------------------------------------------------------------------------------------------------------
     int GetTermSize(std::vector<Person*>& listt)
     {
         return this->studentinfo.termList.size();
     }
//----------------------------------------------------------------------------------------------------------------
     int GetPickedUnits(int termIndex)
     {
         if(this->studentinfo.termList.size() > termIndex)
            return this->studentinfo.termList[termIndex].currentunits;
        else
            return -1;
     }

};
int Student::idCounter = 0;
#endif // STUDENT_H
