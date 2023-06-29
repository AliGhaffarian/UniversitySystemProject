#ifndef PersonH
#define PersonH
#include "InputUtility.cpp"
#include <iostream>
#include "Course.cpp"
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
    virtual void Register(const PersonalInfo& personInfo)
    {
        SetFirstName(personInfo.firstName);
        SetLastName(personInfo.LastName);
        SetNationalID(personInfo.nationalID);
        SetDate(personInfo.dateOfBirth);
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
    void SetGrade(){}
//----------------------------------------------------------------------------------------------------------------
    virtual void SetTerm(){}
};

#endif // Person