#include <iostream>
using namespace std;

class person{
    private:
        string name;
        int age;

    public:
        person(string n,int a){
            name = n;
            age = a;
        }

        void DisplayPerson(){
            cout<<name<<endl<<age<<endl;
        }

};

class Employee : private person
{
private:
    int EmpId;
public:
    Employee(int e, string n, int a) : person(n,a ){
        EmpId = e;
    }

    void DisplayEmp(){
        DisplayPerson();
        cout<<EmpId<<endl;
    }
};

class Manager : private Employee
{
private:
    string dept;
public:
    Manager(string d, int e, string n, int a) : Employee(e, n, a){
        dept = d;
    }
    
    void DisplayMngr(){
        DisplayEmp();
        cout<<dept<<endl;
    }
};

int main(){

    Manager M("CE",1001,"Dhruvin",20);
    M.DisplayMngr();
    return 0;
}