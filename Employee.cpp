#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "iostream"
#include "Student.cpp"
class Employee : public Person
{
protected:
    static int idCounter ;
    int employmentID;
//----------------------------------------------------------------------------------------------------------------
public:
    Employee (std::string name, std::string lname, std:: string id) : Person( name, lname , id)
    {
         personInfo.type = 2;
        idCounter++;
        employmentID = idCounter;
    }
//----------------------------------------------------------------------------------------------------------------
    void RegisterStudent(std::vector<Person*>& StudentList)
    {
        Student* temp;
        temp = new Student;
        StudentList.push_back(temp);
        std::string firstName, lastName, nationalID;
        std::cout << "Enter firstname " << std::endl;
        std::cin >> firstName;
        StudentList[StudentList.size()-1]->SetFirstName(firstName);
        std::cout << "Enter lastname " << std::endl;
        std::cin >> lastName;
        StudentList[StudentList.size()-1]->SetLastName(lastName);
        std::cout << "Enter national ID " << std::endl;
        std::cin >> nationalID;
        StudentList[StudentList.size()-1]->SetNationalID(nationalID);
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
   void RegisterCourse(std::vector<Course>& courseList)
    {
        Course temp;
        std::cin >> temp ;
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
};
#endif // EMPLOYEE_H
