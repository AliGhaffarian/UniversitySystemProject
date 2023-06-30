#ifndef PersonH
#define PersonH
#include "InputUtility.cpp"
#include <iostream>
#include "Course.cpp"
#include "Utility.cpp"
#include <vector>

// this way we can change the program faster
struct PersonalInfo
{
    int type;
    std::string firstName = "InvalidFirstName";
    std::string LastName = "InvalidLastName";
    std::string nationalID = "InvalidNationalID";
    Date dateOfBirth = Date(0, 0, 0);
};
//----------------------------------------------------------------------------------------------------------------
class Person
{

    friend int SearchStudent(const std::string& studentName ,const std::vector<Person*>& studentList )
     {
         for(int i = 0 ; i < studentList.size() ; i++ )
         {
             if(studentList[i]->personInfo.type == 1 && studentList[i]->personInfo.firstName == studentName)
             {
            return i;
            }
        }
        return -1;
    }
    //----------------------------------------------------------------------------------------------------------------
    friend int SearchTeacher( const std::string& teacherName ,const std::vector<Person*>& teacherList )
     {
         for(int i = 0 ; i < teacherList.size() ; i++ )
         {
             if(teacherList[i]->personInfo.type == 3 && teacherList[i]->personInfo.firstName == teacherName)
             {
                 return i;
             }
         }
         return -1;
     }


protected:

    PersonalInfo personInfo;

//----------------------------------------------------------------------------------------------------------------
public:
    Person(){}

    virtual void pure() = 0;

    Person(std::string name, std::string lname, std::string id)
    {
        SetFirstName(name);
        SetLastName(lname);
        SetNationalID(id);
    }
//----------------------------------------------------------------------------------------------------------------
    virtual void Register(std::string& name , std::string& lName , std::string& id , Date& date)
    {
        SetFirstName(name);
        SetLastName(lName);
        SetNationalID(id);
        SetDate(date);
    }
//----------------------------------------------------------------------------------------------------------------
    void SetFirstName(const std::string& firstName)
    {
        if (IsName(firstName))
        {
            this->personInfo.firstName = firstName;
            this->personInfo.firstName[0] = toupper(this->personInfo.firstName[0]);
        }
    }
//----------------------------------------------------------------------------------------------------------------
    void SetLastName(const std::string& lastName)
    {
        if (IsName(lastName))
        {
            this->personInfo.LastName = lastName;
            this->personInfo.LastName[0] = toupper(this->personInfo.LastName[0]);
        }
    }
//----------------------------------------------------------------------------------------------------------------
    void SetNationalID(const std::string& nationalID)
    {
        if (IsNationalID(nationalID))
        {
            this->personInfo.nationalID = nationalID;
        }
    }
//----------------------------------------------------------------------------------------------------------------
    void SetDate(const Date& dateOfBirth)
    {
        this->personInfo.dateOfBirth = dateOfBirth;
    }
//----------------------------------------------------------------------------------------------------------------
    bool IsNationalID(const std::string& ID)
    {
        return (IsDigit(ID));
    }
//----------------------------------------------------------------------------------------------------------------
    std::string GetFirstName() const
    {
        return personInfo.firstName;
    }
//----------------------------------------------------------------------------------------------------------------
    PersonalInfo GetPerson() const
    {
        return personInfo;
    }
//----------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------

    virtual void SetCourseName(std::string name , int termIndex) {}

    virtual void RegisterGrade(float gradee , std::string name , int termIndex) {}

    virtual void SetGrade(int termIndex , float termGrade , int gradeIndex ) {}

    virtual void SetTerm(int termnum) {}

    virtual void Report(int termIndex) {}

    virtual int CourseInTerm(std::string courseName) {}

    virtual int FindCours(std::string courseName) {}

    virtual int FindeCourseUnit(std::vector<Course>courseList , std::string name) {}

    virtual void AverageCalculate(int termIndex ,std::vector<Course>courseList) {}

    virtual void TotallAverage () {}

    virtual void RegisterStudent(std::vector<Person*>& StudentList) {}

    virtual void RegisterTeacher (std::vector<Person*>& TeacherList) {}

    virtual void EditStudent(std::string name , std::vector<Person*>& List) {}

    virtual void RegisterCourse(std::vector<Course>& courseList) {}

    virtual void EditCourse(std::vector<Course>& courseList , std::string courseName) {}

    virtual void AddCourse(std::vector<Course> courseList , std::vector<Person*> studentList , int index , std::string courseName , int termIndex) {}

    virtual int SearchStudent( std::string studentName ,std::vector<Person*>& studentList ) {}

    virtual bool CourseExist(std::string name , std::vector<Course>& coursList) {}

    virtual void EditTeacher(std::string name , std::vector<Person*>& List) {}

    virtual void RegisterGrade(Person* Student , int termIndex , int gradeIndex , float grade) {}

};

#endif // Person
