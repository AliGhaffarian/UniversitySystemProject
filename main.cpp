#include <iostream>
#include "Employee.cpp"
#include "Teacher.cpp"
#include <windows.h>
using namespace std;
std::vector<Person*> personList;
std::vector<Course> coursList;
void LoginPage();
int Identify(std::vector<Person*>& person , std::string inputName , std::string InputLame);
int findPerson(std::vector<Person*>& , std::string inputName , std::string InputLame);
void StudentMenu(std::vector<Person*>& , int index);
void EmployeeMenu(std::vector<Person*>& , int index);
int main()
{
    LoginPage();
    return 0;

}
 void LoginPage()
 {
     while(true)
    {
     int select,personIndex;
     string name,lname;
     std::cout<< "Please Enter your name and lastname" <<"\n";
     std::cin >> name >> lname;
     select = Identify(personList , name , lname);
     personIndex = findPerson(personList , name , lname);
     switch(name[0]-48)
     {
      case 1:
          Employee* employee;
          employee = new Employee;
          personList.push_back(employee);
          system("cls");
        //  EmployeeMenu(personList);
         break;
      default:
          if(select == 1)
           {
               system("cls");
               StudentMenu( personList , personIndex );
           }
           else if(select == 2)
            {
                system("cls");
                //teacherui
             }
           else if(select == 3)
           {
              system("cls");
              //empui
           }
           else
           {
              system("cls");
              std::cout<<"this username does not exist pleas try again \n\n";
           }

        }
     }
 }

 int Identify(std::vector<Person*>& person , std::string inputName , std::string InputLname)
 {
     for(int i = 0 ; i < person.size() ; i++ )
     {
         if(inputName == person[i]->GetPerson().firstName && InputLname == person[i]->GetPerson().LastName)
         {
             return person[i]->GetPerson().type;
         }
     }
     return -1;
 }

 int findPerson(std::vector<Person*>& person , std::string inputName , std::string InputLname)
 {
      for(int i = 0 ; i < person.size() ; i++ )
     {
         if(inputName == person[i]->GetPerson().firstName && InputLname == person[i]->GetPerson().LastName)
         {
             return i;
         }
     }
     return -1;
 }

 void StudentMenu(std::vector<Person*>& studentt, int index)
 {
     char userInput = 'y';
     while(userInput == 'y' || userInput == 'Y')
     {
     std::cout<<"1.report of term \n\n" <<"2.applying for delete a course \n\n"
     << "3.applying for delete a term \n\n";
     int select;
     std::cin>>select;
     switch(select)
     {
     case 1:
         int temp;
          system("cls");
          std::cout<<"which term you want to see \n\n\n";
          std::cin>> temp;
          studentt[index]->Report(temp);
        break;

     case 2:
          system("cls");
        break;

     case 3:
          system("cls");
        break;
     default:
        std::cout<<"wrong input, press y to try again and n to back to login menu \n";
        std::cin>>userInput;
        if(userInput == 'n' || userInput == 'N')
        {
            system("cls");
            LoginPage();
        }
     }
     }
 }

 void EmployeeMenu(std::vector<Person*>& employee, int index)
 {
      char userInput = 'y';
     while(userInput == 'y' || userInput == 'Y')
     {
     std::cout<<"1.register new student \n\n" <<"2.register new teacher \n\n"
     << "3.register new course \n\n" << "4.edit a student information \n\n" << "5.edit a teacher info \n\n"
     << "6.edit a course information \n\n" << "7.delete a student \n\n" << "8.delete a teacher \n\n"
     << "9.delete a course  \n\n" << "10.add course to a student";
     int select;
     std::cin>>select;
     switch(select)
     {
     case 1:
         {
          system("cls");
          personList[index]->RegisterStudent(personList);
          system("cls");
          break;
         }
     case 2:
         {
          system("cls");
          personList[index]->RegisterTeacher(personList);
          system("cls");
          break;
         }
     case 3:
         {


          system("cls");
          personList[index]->RegisterCourse(coursList);
          system("cls");
          break;
         }
     case 4:
         {


         system("cls");
         std::string name;
         std::cout<<"Enter student name \n\n";
         std::cin >> name;
         personList[index]->EditStudent(name , personList );
         system("cls");
         break;
         }
     case 5:
         {


         system("cls");
         std::string name;
         std::cout<<"Enter teacher name \n\n";
         std::cin >> name;
         personList[index]->EditTeacher(name , personList);
         system("cls");
         break;
         }
     case 6:
         {


         system("cls");
         std::string name;
         std::cout<<"Enter course name \n\n";
         std::cin >> name;
         personList[index]->EditCourse(coursList , name);
         system("cls");
         system("cls");
         break;
         }
     case 7:
          system("cls");
        break;
     case 8:
        system("cls");
        break;
     case 9:
         system("cls");
         break;
     default:
        std::cout<<"wrong input, press y to try again and n to back to login menu \n";
        std::cin>>userInput;
        system("cls");
        if(userInput == 'n' || userInput == 'N')
        {
            LoginPage();
        }
     }
     }
 }
