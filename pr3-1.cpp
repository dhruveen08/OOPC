#include<iostream>
#include<cstring> 
using namespace std;

class Employee {
private:
    int id;
    char name[30];
    double salary;
    float bonus;

public:
    Employee() {
        id = 0;
        strcpy(name, "N/A");
        salary = 0;
        bonus = 2000;
    }

    Employee(int eid, const char ename[], double esalary, float ebonus = 2000) {
        id = eid;
        strcpy(name, ename);
        salary = esalary;
        bonus = ebonus;
    }

    inline double TotalSalary() {
        return salary + bonus;
    }

    void DisplayDetails(int searchId) {
        if (searchId == id) {
            cout << "------------------------------" << endl;
            cout << "Employee Id     : " << id << endl;
            cout << "Employee Name   : " << name << endl;
            cout << "Basic Salary    : " << salary << endl;
            cout << "Bonus           : " << bonus << endl;
            cout << "Total Salary    : " << TotalSalary() << endl;
            cout << "------------------------------" << endl;
        }
    }
};

int main() {
    Employee EMP[20];
    int i = 0;
    int choice;

    cout << "Welcome to Employee Salary Management System!!" << endl;

    while (true) {
        cout << "\nPress \n1. to Add Employee Data, \n2. to Display Employee Information, \n3. to Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                int eid;
                char ename[30];
                double bsalary;
                char opt;
                float ebonus;

                cout << "Enter Employee Id : ";
                cin >> eid;
                cout << "Enter Employee Name : ";
                cin >> ename;
                cout << "Enter the Basic Salary : ";
                cin >> bsalary;
                cout << "Do you want to add specific bonus (y/n)? : ";
                cin >> opt;

                if (opt == 'y' || opt == 'Y') {
                    cout << "Enter the Bonus : ";
                    cin >> ebonus;
                    EMP[i] = Employee(eid, ename, bsalary, ebonus);
                } else {
                    EMP[i] = Employee(eid, ename, bsalary);
                }
                i++;
                break;
            }

            case 2: {
                int j;
                cout << "Enter the Employee Id to Display: ";
                cin >> j;
                bool found = false;
                for (int a = 0; a < i; a++) {
                    EMP[a].DisplayDetails(j);
                    found = true;
                }
                if (!found) {
                    cout << "Employee not found." << endl;
                }
                break;
            }

            case 3:
                cout << "Thank you for using the system!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    }

    return 0;
}
