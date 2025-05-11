#include<iostream>
#include<math.h>
using namespace std;

class LoanAccount{
    private:
        int id;
        char name[20];
        long totalamt;
        float interest;
        float time;
        double emi;
        double CalEMI(){
            float rate = interest/12/100;      //Convert the Annual rate to Monthly Rate
            emi = ((totalamt*rate)*pow((1 + rate),time))/(pow((1 + rate),time) - 1);
            return emi;
        } 

    public:
        
        void Add_Details(){
                cout<<"Enter Load id :";
                cin>>id;
                cout<<"Enter the Applicant's Name :";
                cin>>name;
                cout<<"Enter the Total Loan Amount :";
                cin>>totalamt;
                cout<<"Enter the Rate of Interest :";
                cin>>interest;
                cout<<"Enter the Time period in Months :";
                cin>>time;
                CalEMI();
        }

        void Display_Details(){;
            cout<<"------------------------------"<<endl;
            cout<<"Name of the Applicant : "<<name<<endl;
            cout<<"Loan Id : "<<id<<endl;
            cout<<"Total Loan Amount : "<<totalamt<<endl;
            cout<<"Rate of Interest : "<<interest<<endl;
            cout<<"Time Period : "<<time<<endl;
            cout<<"The EMI generated is : "<<emi<<endl;
            cout<<"------------------------------"<<endl;
        }
};


int main(){
    LoanAccount L;
    cout<<"Enter the required information :"<<endl;
    L.Add_Details();
    L.Display_Details();
    return 0;
};
