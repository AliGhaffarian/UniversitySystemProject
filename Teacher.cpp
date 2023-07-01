#ifndef TEACHER_CPP
#define TEACHER_CPP
#include "Student.cpp"
struct Students
{
    std::string studentName;
    std::string courseName;
};

struct TeacherInfo
{
    float paymentPerMonth;
    int membershipNumber;
    std::string department;
    std::vector<Students> coursList;
};
class Teacher:public Person
{
    friend class Employee;
    const Teacher& operator = (const Teacher& right)
    {
        this->personInfo.firstName = right.personInfo.firstName;
        this->personInfo.LastName = right.personInfo.LastName;
        this->personInfo.dateOfBirth = right.personInfo.dateOfBirth ;
        this->personInfo.nationalID = right.personInfo.nationalID ;
        this->personInfo.type = right.personInfo.type;
        this->teacherInfo.coursList.resize(right.teacherInfo.coursList.size());
        for(int i = 0 ; i < right.teacherInfo.coursList.size() ; i++)
        {
            this->teacherInfo.coursList[i].courseName = right.teacherInfo.coursList[i].courseName;
            this->teacherInfo.coursList[i].studentName = right.teacherInfo.coursList[i].studentName;
        }
        this->teacherInfo.department = right.teacherInfo.department ;
        this->teacherInfo.membershipNumber = right.teacherInfo.membershipNumber ;
        this->teacherInfo.paymentPerMonth =right.teacherInfo.paymentPerMonth ;
        return *this;
    }
protected:
    TeacherInfo teacherInfo;
    static int teacherCounter;
public:
    void pure(){}

    Teacher() {
        personInfo.type = 3;
        teacherCounter++;
        teacherInfo.membershipNumber = teacherCounter;
    }

    Teacher(std::string name, std::string lname, std::string id , float payment , std::string department): Person( name, lname, id)
    {
        this->teacherInfo.paymentPerMonth = (payment > 0) ? payment : -1;
        this->teacherInfo.department = department ;
        this->teacherInfo.membershipNumber = ++teacherCounter;
        this->personInfo.type = 3;
    }
//----------------------------------------------------------------------------------------------------------------
    Teacher (const Teacher& right)
    {
        *this = right;
    }

    void RegisterGrade(std::vector<Person*>& student , int gradeIndex , int studentIndex, float grade,std::string courseName)
    {
        int termIndex = student[studentIndex]->CourseInTerm(courseName);
        if(this->teacherInfo.department == student[studentIndex]->GetMajor() ){
        student[studentIndex]->SetGrade(termIndex , grade , gradeIndex);
        }
        else
            std::cout<<"you dont have access to register grade for this course\n";
    }

    void SetDepartment(std::string name)
    {
        if(!IsDigit(name))
        {
            name[0]=toupper(name[0]);
            teacherInfo.department =name;
        }
    }
};
int Teacher::teacherCounter = 0;
#endif // TEACHER_CPP
