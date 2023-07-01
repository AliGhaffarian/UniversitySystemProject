#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "iostream"
#include "Student.cpp"
#include "Teacher.cpp"
class Employee : public Person
{
    const Employee& operator = (const Employee& right)
    {
        this->personInfo.firstName = right.personInfo.firstName;
        this->personInfo.LastName = right.personInfo.LastName;
        this->personInfo.dateOfBirth = right.personInfo.dateOfBirth ;
        this->personInfo.nationalID = right.personInfo.nationalID ;
        this->personInfo.type = right.personInfo.type;
        this->employmentID = right.employmentID;
    }
protected:
    static int idCounter ;
    int employmentID;
//----------------------------------------------------------------------------------------------------------------
public:
    Employee(){}

    Employee (std::string name, std::string lname, std:: string id) : Person( name, lname , id)
    {
         personInfo.type = 2;
        idCounter++;
        employmentID = idCounter;
    }

    Employee(const Employee& right)
    {
        *this = right;
    }
    void pure () {}
//----------------------------------------------------------------------------------------------------------------
    void RegisterStudent(std::vector<Person*>& StudentList)
    {
        Student* temp;
        temp = new Student;
        StudentList.push_back(temp);
        std::string firstName, lastName, nationalID , major;
        std::cout << "Enter firstname " << std::endl;
        std::cin >> firstName;
        StudentList[StudentList.size()-1]->SetFirstName(firstName);
        std::cout << "Enter lastname " << std::endl;
        std::cin >> lastName;
        StudentList[StudentList.size()-1]->SetLastName(lastName);
        std::cout << "Enter national ID " << std::endl;
        std::cin >> nationalID;
        StudentList[StudentList.size()-1]->SetNationalID(nationalID);
        std::cout << "Enter student major " << std::endl;
        std::cin >> major;
        StudentList[StudentList.size()-1]->SetMajor(major);
    }
//----------------------------------------------------------------------------------------------------------------
    void EditStudent(std::string name , std::vector<Person*>& List)
    {
        for(int i = 0 ; i < List.size() ; i++)
            {
                if( name == List[i]->GetFirstName() )
                {
                    List.erase(List.begin() + i);
                    RegisterStudent(List);
                }
            }
    }
//----------------------------------------------------------------------------------------------------------------
   void RegisterTeacher (std::vector<Person*>& TeacherList)
   {
       Teacher* temp;
       temp = new Teacher;
       TeacherList.push_back(temp);
       std::string firstName, lastName, nationalID,department;
       std::cout << "Enter firstname " << std::endl;
       std::cin >> firstName;
       TeacherList[TeacherList.size()-1]->SetFirstName(firstName);
       std::cout << "Enter lastname " << std::endl;
       std::cin >> lastName;
       TeacherList[TeacherList.size()-1]->SetLastName(lastName);
       std::cout << "Enter national ID " << std::endl;
       std::cin >> nationalID;
       TeacherList[TeacherList.size()-1]->SetNationalID(nationalID);
       std::cout << "Enter teacher department " << std::endl;
       std::cin >> department;
       TeacherList[TeacherList.size()-1]->SetDepartment(department);
   }
//----------------------------------------------------------------------------------------------------------------
   void EditTeacher(std::string name , std::vector<Person*>& List)
   {
       for(int i = 0 ; i < List.size() ; i++)
            {
                if( name == List[i]->GetFirstName() )
                {
                    List.erase(List.begin() + i);
                    RegisterTeacher(List);
                }
            }
   }
//----------------------------------------------------------------------------------------------------------------
   void RegisterCourse(std::vector<Course>& courseList)
    {
        Course temp;
        std::cin >> temp;
        courseList.push_back(temp);
    }
//----------------------------------------------------------------------------------------------------------------
    void EditCourse(std::vector<Course>& courseList , std::string courseName)
    {
        for(int i = 0 ; i<courseList.size() ; i++)
        {
            if(courseName == courseList[i].GetCourseName() )
            {
                courseList.erase(courseList.begin() + i);
                RegisterCourse(courseList);
            }
        }
    }
//----------------------------------------------------------------------------------------------------------------
    void AddCourse(std::vector<Course>& courseList , std::vector<Person*>& studentList , int index , std::string courseName )  // add an existing course to student
    {
        std::cout<<" \n add course \n";
        if (CourseExist(courseName , courseList))
        {
            std::cout<<" \n add course \n";
             studentList[index]->SetCourseName(courseName);
        }
    }
//----------------------------------------------------------------------------------------------------------------
    int SearchStudent( std::string studentName ,std::vector<Person*>& studentList )
    {
      for(int i = 0 ; i < studentList.size() ; i++ )
        {
            if(studentList[i]->GetPerson().type == 1 && studentList[i]->GetPerson().firstName == studentName)
            {
                return i;
            }
        }
      return -1;
    }
//----------------------------------------------------------------------------------------------------------------
    bool CourseExist(std::string name , std::vector<Course>& coursList)
    {
        for(int i = 0 ; i < coursList.size() ; i++)
        {
            if (name == coursList[i].GetCourse().name)
                return true;
        }
        return false;
    }
//----------------------------------------------------------------------------------------------------------------
    void RegisterTerm (std::vector<Person*> listt , int index )
    {
        listt[index]->SetTerm();
    }
};
#endif // EMPLOYEE_H
