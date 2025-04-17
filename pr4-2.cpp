#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    public:
        Person(){};
        Person(string name1,int age1)
        {
            name=name1;
            age=age1;
        }
        void DisplayPerson()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }
};

class Employee: public Person{
    protected:
        int EmployeeID;
    public:
        Employee():Person(){};
        Employee(string name1,int age1,int empId):Person(name1,age1){
            EmployeeID=empId;
        }
        void DisplayEmployee()
        {
            DisplayPerson();
            cout<<"Employee ID: "<<EmployeeID<<endl;
        }
};

class Manager: public Employee{
    protected:
        string Department;
    public:
        Manager():Employee(){};
        Manager(string name1,int age1,int empId,string dep):Employee(name1,age1,empId){
            Department=dep;
        }
        void DisplayManager()
        {
            DisplayEmployee();
            cout<<"Department: "<<Department<<endl;
        }
};

int main()
{
    string name1,dep;
    int age1,empId;

    int i,choice,count=0;
    Manager* Emp[15];

    program:
          cout<<"Enter Name: ";
          cin>>name1;
          cout<<"Enter Age: ";
          cin>>age1;
          cout<<"Enter Employee Id: ";
          cin>>empId;
          cout<<"Enter Department: ";
          cin>>dep;

          Emp[count] = new Manager(name1,age1,empId,dep);
          count++;

          cout<<"Do you want to add more Employee?(1 for yes/0 for no)\n";
          cout<<"Enter your choice: ";
          cin>>choice;

          if(choice!=1)
          {
            cout<<"Displaying Details of Employee\n"<<endl;
            for(i=0;i<count;i++)
            {
                cout<<"EMPLOYEE "<<i+1<<endl;
                Emp[i]->DisplayManager();
            }
            return 0;
          }

          else{
            goto program;
          }
          return 0;
}