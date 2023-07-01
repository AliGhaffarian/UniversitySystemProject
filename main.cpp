#include <iostream>
#include "Employee.cpp"
#include "Teacher.cpp"
#include <windows.h>
#include <conio.h>
using namespace std;
std::vector<Person*> personList;
std::vector<Course> coursList;
void LoginPage();
int Identify(std::vector<Person*>&  , std::string  , std::string );
int findPerson(std::vector<Person*>& , std::string  , std::string );
void StudentMenu(std::vector<Person*>& , int );
void EmployeeMenu(std::vector<Person*>& , int );
void TeacherMenu(std::vector<Person*>& , int );
int findCourse(std::string );
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
     std::cout<< select << "        " << personIndex;
     switch(name[0]-48)
     {
      case 1:
          Employee* employee;
          employee = new Employee;
          personList.push_back(employee);
          system("cls");
          EmployeeMenu(personList , 0);
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
                EmployeeMenu(personList , personIndex);
            }
           else if(select == 3)
           {
              system("cls");
              TeacherMenu(personList , personIndex);
           }
           else
           {
              system("cls");
              std::cout<<"this username does not exist pleas try again \n\n";
           }

        }
     }
 }

 int Identify(std::vector<Person*>& person , std::string inputName , std::string inputLname)
 {
     inputName[0] = toupper(inputName[0]);
     inputLname[0] = toupper(inputLname[0]);
     for(int i = 0 ; i < person.size() ; i++ )
     {
         if(inputName == person[i]->GetPerson().firstName && inputLname == person[i]->GetPerson().LastName)
         {
             return person[i]->GetPerson().type;
         }
     }
     return -1;
 }

 int findPerson(std::vector<Person*>& person , std::string inputName , std::string inputLname)
 {
      inputName[0] = toupper(inputName[0]);
      inputLname[0] = toupper(inputLname[0]);
      for(int i = 0 ; i < person.size() ; i++ )
     {
         if(inputName == person[i]->GetPerson().firstName && inputLname == person[i]->GetPerson().LastName)
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
     << "3.applying for delete a term \n\n"<< "4.back to login page \n\n";
     int select;
     std::cin>>select;
     switch(select)
     {
     case 1:
          int temp;
          system("cls");
          std::cout<<"which term you want to see \n\n";
          std::cin>> temp;
          studentt[index]->Report(temp);
          system("cls");
        break;

     case 2:
          system("cls");
        break;

     case 3:
          system("cls");
        break;
     case 4:
        system("cls");
        LoginPage();
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
     << "9.delete a course  \n\n" << "10.add term to a student \n \n" <<"11.add course to a student \n \n"
     <<"12.back to login menu \n \n ------>  ";
     int select = 0;
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
     case 10:
         {
             system("cls");
             std::string tempName,tempLname;
             std::cout<< "Enter full name of student \n";
             std::cin >> tempName >> tempLname ;
             int caseIndex = findPerson(personList , tempName , tempLname );
             personList[caseIndex]->SetTerm();
             if(caseIndex != -1)
             {
                 std::cout << "\nstudent terms increased by 1   \t press enter key to continue \n\n";
                    getchar();
                    getchar();
             }
             char junk;
             break;
         }
     case 11:
      {
          system("cls");
          std::string tempName,tempLname , tempCourse;
          std::cout<< "Enter full name of student \n\n";
          std::cin >> tempName  ;
          std::cin >> tempLname ;
          std::cout<< "Enter course name that you want to add \n\n";
          std::cin >> tempCourse ;
          int courseIndex = findCourse(tempCourse);
          int caseIndex = findPerson(personList , tempName , tempLname );
          if(personList[caseIndex]->GetTermSize(personList) > 0 && personList[caseIndex]->GetPickedUnits(personList[caseIndex]->GetTermSize(personList) - 1) < 21 && caseIndex != -1 && courseIndex != -1)
      {
          system("cls");
          personList[caseIndex]->SetCourseName(tempCourse);

      }
        else if(courseIndex != -1)
        {
            std::cout << "this student has not any term yet please first register term for it \n\n";

        }
        else if (courseIndex == -1)
        {
            std::cout << "this course does not exist in courslist \n\n";
        }
        system("cls");
         break;
     }
     case 12:
     {
         system("cls");
         LoginPage();
         break;
     }
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

 void TeacherMenu(std::vector<Person*>& teacher, int index)
 {
     while(true)
    {
     system("cls");
     int teacherSelect;
     std::string courseName,studentFname,studentLname;
     std::cout << "1.Register grades \n\n"<< "2.back to login menu \n\n---->   ";
     std::cin>>teacherSelect;
     if(teacherSelect == 1)
       {
         system("cls");
         std::cout<<"enter student full :   ";
         std::cin >>studentFname >> studentLname ;
         std::cout << "Enter your Course name :   ";
         std::cin >> courseName ;
         int studentIndex = findPerson(personList , studentFname , studentLname);
         int coursIndex = personList[studentIndex]->FindCours(courseName);
         if(coursIndex != -1 && studentIndex != -1)
         {
             float grade;
             std::cout<<"enter grade \n";
             std::cin>>grade;
             personList[index]->RegisterGrade(personList , coursIndex ,studentIndex, grade , courseName);
         }
         else if(studentIndex== -1)
         {
             std::cout<<"student not found\n\n";
         }
         else if(coursIndex == -1)
         {
             std::cout<<"course not found\n\n";
         }
       }
       else if (teacherSelect == 2)
       {
           system("cls");
           LoginPage();
       }
    }
 }

 int findCourse(std::string courseName)
 {
    courseName[0] = toupper(courseName[0]);
    for(int i = 0 ; i < coursList.size() ; i++)
    {
        if(courseName == coursList[i].GetCourse().name)
        return i;
    }
    return -1;
 }
