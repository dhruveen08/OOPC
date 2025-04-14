#include<iostream>
using namespace std;

class employee{

    private:
        int id;
        char name[30];
        double salary;
        float bonus;

    public:

        employee (int eid, char ename[], double esalary, float ebonus = 2000){
            id = eid;
            name =  ename;
            salary = esalary;
            bonus = ebonus;
        }
        
        inline double TotalSalary(){
            return salary + bonus;
        }

        void DisplayDetails(j){
            if (j = id){

                cout<<"------------------------------";
                cout<<"Employee Id : "<<id<<endl;
                cout<<"Employee Name : "<<name<<endl;
                cout<<"Basic Salary : "<<salary<<endl;
                cout<<"Bonus : "<<bonus<<endl;
                cout<<"------------------------------";
            }
        }
};


int main (){
    int i=0;
    employee EMP[20];
    int choice;
    cout<<"Welcome to Employee Salary Management System!!";
    x : cout<<"Press \n1. to Add Employee Data, \n2. to Display Employee Information, \n3. to Exit";
    cin>>choice;

    switch (choice)
    {
    case 1:
        int eid;
        char ename[];
        double bsalary;
        float ebonus;
        cout<<"Enter Employee Id : ";
        cin>>eid;
        cout<<"Enter Employee Name : ";
        cin>>ename[]; 
        cout<<"Enter the Basic Salary : ";
        cin>>bsalary;
        cout<<"Do you want to add specific bonus (y/n) :";
        cin>>char b;
        if (b == 'y'){
            cout<<"Enter the Bonus : ";
            cin>>float ebonus;
            EMP[i].employee(eid, ename, bsalary, ebonus);
            i++;
        }
        else{
            EMP[i].employee(eid, ename, bsalary);
        }
        goto x;
        break;
    
    case 2:
        int j;
        cout<<"Enter the Employee Id:";
        cin>>j;
        for (a = 0; a < 20 ; a++ ){
            EMP[a].DisplayDetails(j);
        }
    case 3: 
        goto end;
    default:
        break;
    }


    end : return 0;
};