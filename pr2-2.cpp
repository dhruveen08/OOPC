#include<iostream>
#include<cstring>
using namespace std;

class Student {
    int rollnum;
    char name[10];
    float marks1, marks2, marks3, average;

    inline void CalculateAverage() {
        average = (marks1 + marks2 + marks3) / 3.0;
    }

public:
    Student() {
        rollnum = 0;
        strcpy(name, "N/A");
        marks1 = 0;
        marks2 = 0;
        marks3 = 0;
        average = 0;
    }

    Student(int rn, char n[], int m1, int m2, int m3) {
        rollnum = rn;
        strcpy(name, n);
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }

    void AddStudentDetails() {
        cout << "Enter Roll No: ";
        cin >> rollnum;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks of Subject 1: ";
        cin >> marks1;
        cout << "Enter Marks of Subject 2: ";
        cin >> marks2;
        cout << "Enter Marks of Subject 3: ";
        cin >> marks3;
        CalculateAverage();
        cout << "Student's Details are Successfully Added!" << endl;
    }

    void DisplayStudentDetails() {
        cout << "Student's Details:" << endl;
        cout << "Roll number: " << rollnum << endl;
        cout << "Name: " << name << endl;
        cout << "Marks of Subject 1: " << marks1 << endl;
        cout << "Marks of Subject 2: " << marks2 << endl;
        cout << "Marks of Subject 3: " << marks3 << endl;
        cout << "Average: " << average << endl;
    }

    inline int GetRollNo() {
        return rollnum;
    }
};

int main() {
    class Student S[100];
    int num_stu = 0;
    int choice, stu_find;

    cout << "Enter 1 to Add Student's Details." << endl;
    cout << "Enter 2 to Display Student's Details." << endl;
    cout << "Else to Exit." << endl;
    cout << "=====================================" << endl;

next:
    cout << "Enter Your Choice Which You Want: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        S[num_stu].AddStudentDetails();
        num_stu++;
        break;
    }

    case 2: {
        cout << "Enter Student's Roll No.: ";
        cin >> stu_find;

        bool found = false;

        for (int i = 0; i < num_stu; i++) {
            if (S[i].GetRollNo() == stu_find) {
                S[i].DisplayStudentDetails();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student Not Found!" << endl;
        }

        break;
    }
    }
    goto next;
}