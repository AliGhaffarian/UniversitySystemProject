#ifndef COURSEH
#define COURSEH
#include "iostream"
#include "Date.cpp"
struct CourseInfo
{


    std::string name = "InvalidCourseName";
    int unit = -1;
    std::string accessType = "InvalidAccessType";//defining who can have this course
};

class Course
{


    friend std::istream& operator >> (std::istream& input, Course& course)
    {
        std::string name;
        int unit;
        std::string accessType;
        std::cout << "Enter Course name :  ";
        input >> name;
        std::cout << "\n Which scientific Group is this course belong to";
        input >> accessType;
        std::cout << "\n Enter Course's unit :  ";
        input >> unit;
        course.SetName(name);
        course.SetUnit(unit);
        course.SetAcces(accessType);
        return input;
    }


    friend std::ostream& operator << (std::ostream& output, Course& course)
    {
        output << "course name :  " << course.courseInfo.name <<
            "\t" << "unit" << course.courseInfo.unit << std::endl;
        return output;
    }

protected:

    CourseInfo courseInfo;

public:

    Course()
    {
    }

    Course(std::string name, int unit, std::string accessType)
    {
        SetName(name);
        SetUnit(unit);
        SetAcces(accessType);
    }

    Course(const Course& course)//copy constructor
    {
        this->courseInfo.name = course.courseInfo.name;
        this->courseInfo.unit = course.courseInfo.unit;
        this->courseInfo.accessType = course.courseInfo.accessType;
    }

    void SetName(const std::string& name)
    {
        if (IsName(name))
        {
            this->courseInfo.name = name;
        }
    }

    void SetUnit(const int unit)
    {
        if (IsUnit(unit))
        {
            this->courseInfo.unit = unit;
        }
    }

    void SetAcces(const std::string access)
    {
        this->courseInfo.accessType = access;
        this->courseInfo.accessType[0] = toupper(this->courseInfo.accessType[0]);
    }

    bool IsGrade(float grade)
    {
        return (grade >= 0 && grade <= 20);
    }

    bool IsUnit(int unit)
    {
        return (unit <= 4 && unit >= 1);
    }
    std::string GetCourseName() const
    {
        return courseInfo.name;
    }
};
#endif // COURSEH
