#include "Student.cpp"
struct TeacherCourses
{

    Course course;
    int amountOfStudents;
    std::vector<Student> studentList;
};
struct TeacherInfo
{
    float paymentPerMonth;
    int membershipNumber;
    std::string department;
    std::vector<TeacherCourses> coursList;
};
class Teacher:public Person
{
protected:
    TeacherInfo teacherInfo;
    static int teacherCounter;
public:
    void pure(){}
    Teacher(){}
    void RegisterGrade(Person* student , std::string courseName)
    {
        int flag = 1;
        for(int i = 0 ; i < teacherInfo.coursList.size() ; i++)
        {
            if(teacherInfo.coursList[i].course.GetCourseName() == courseName)
            {
                flag = 0;
                for(int j = 0 ; j < teacherInfo.coursList[i].amountOfStudents ; j++)
                {
                    float temp;
                    std::cout << "Enter student "<<teacherInfo.coursList[i].studentList[j].GetFirstName() << "grade (Press 1 for exit):  ";
                    std::cin >> temp ;
                     if(temp == 1)
                     {
                         break;
                     }
                     else
                     {
                         teacherInfo.coursList[i].studentList[j].studentinfo.termList[teacherInfo.coursList[i].studentList[j].CourseInTerm(courseName)].gradeList[teacherInfo.coursList[i].studentList[j].FindCours(courseName)].score = temp;
                     }
                     std::cout<<"\n";
                }
            }
        }
        if(flag)
            std::cout<<"the course does not exist"<< std::endl;
    }
};
int Teacher::teacherCounter = 0;
