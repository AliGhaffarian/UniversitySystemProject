#ifndef COURSEH
#define COURSEH
#include "iostream"
#include "Utility.cpp"
struct CourseInfo
{


    std::string name = "InvalidCourseName";
    float grade = -1;
    int unit = -1;
    int accessType = -1;//defining who can have this course


};

class Course
{


    friend std::istream& operator >> (std::istream& input , Course& course)
    {
       std::string name;
       float grade;
       int unit;
       int accessType;
       input >> name >> grade >> unit >> accessType;
       course.SetName(name);
       course.SetGrade(grade);
       course.SetUnit(unit);
       course.SetAcces(accessType);
       return input;
    }


    friend std::ostream& operator << (std::ostream& output , Course& course)
    {
       output << "course name :  "<< course.courseInfo.name << "\t" << "grade :  "<< course.courseInfo.grade
       << "\t" << "unit" <<course.courseInfo.unit << std::endl;
       return output;
    }


    CourseInfo courseInfo;



public:

    Course()
    {
    }

    Course(std::string name , float grade , int unit , int accessType)
    {
       SetName(name);
       SetGrade(grade);
       SetUnit(unit);
       SetAcces(accessType);
    }

    Course(const Course& course)//copy constructor
    {
       this->courseInfo.name = course.courseInfo.name;
       this->courseInfo.grade = course.courseInfo.grade;
       this->courseInfo.unit = course.courseInfo.unit;
       this->courseInfo.accessType= course.courseInfo.accessType;
    }

    void SetName(const std::string& name)
    {
       if(IsName(name))
       {
          this->courseInfo.name = name;
       }
    }

    void SetGrade(const float grade)
    {
       if(IsGrade(grade))
       {
          this->courseInfo.grade = grade;
       }
    }

    void SetUnit(const int unit)
    {
       if(IsUnit(unit))
       {
          this->courseInfo.unit = unit;
       }
    }

    void SetAcces(const int access)
    {
       this->courseInfo.accessType = access;
    }

    bool IsGrade(float grade)
    {
       return (grade >= 0 && grade <= 20);
    }

    bool IsUnit(int unit)
    {
       return (unit <= 4 && unit >= 1);
    }
};
#endif // COURSEH
