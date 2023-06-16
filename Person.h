#ifndef PersonH
#define PersonH
#include "InputUtility.cpp"
#include <iostream>
#include "Date.cpp"

// this way we can change the program faster

struct PersonalInfo
{


    std::string firstName = "InvalidFirstName";
    std::string LastName = "InvalidLastName";
    std::string nationalID = "InvalidNationalID";
    Date dateOfBirth = Date(0,0,0);
};


class Person
{


    PersonalInfo personInfo;

    public:

    Person ()
    {
        //using namespace std;
        //Register(personInfo);
    }
    void Register(const PersonalInfo& personInfo)
    {
        //register first name
        if (personInfo.firstName.size() > 0 && !IsDigit(personInfo.firstName))
        {
            this->personInfo.firstName = personInfo.firstName;
            MakeUpperCase(this->personInfo.firstName);
        }
        //register lastname
        if (personInfo.firstName.size() > 0 && !IsDigit(personInfo.firstName))
        {
            this->personInfo.LastName = personInfo.LastName;
            MakeUpperCase(this->personInfo.LastName);
        }
        //register nationalid
        // will write a better nationalnumber register soon
        if (IsDigit(personInfo.nationalID))
        {
            this->personInfo.nationalID = personInfo.nationalID;
        }
        //the date will register by its constructor
        this->personInfo.dateOfBirth = personInfo.dateOfBirth;

    }

};

#endif // Person
