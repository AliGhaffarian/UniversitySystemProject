#ifndef PersonH
#define PersonH

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
    }

};

#endif // Person
