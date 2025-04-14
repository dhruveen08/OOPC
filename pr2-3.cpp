#include <iostream>
using namespace std;

class Account
{
    char HolderName[30];
    int AccountNo;
    double CurrentBalance;

    public:

    void CreateAccount()
    {
        cout << "--------------------------" << endl;
        cout<<"Enter Holder Name : ";
        cin>>HolderName;
        cout<<"Enter Account Number : ";
        cin>>AccountNo;
    b1:
        cout<<"Enter your Balance : ";
        cin>>CurrentBalance;
        cout << "--------------------------" << endl;
        if(CurrentBalance<1000)
        {
            cout<<"Minimum required balance is 1000..."<<endl;
            cout << "--------------------------" << endl;
            goto b1;
        }
    }
    int GetNO()
    {
        return AccountNo;
    }

    void DepositMoney()
    {
        double NewAmount;
        cout << "--------------------------" << endl;
        cout<<"Enter your amount that you want to deposit : ";
        cin>>NewAmount;
        CurrentBalance+=NewAmount;
        cout<<"Your new balance is : "<<CurrentBalance<<endl;
        cout << "--------------------------" << endl;
    }


    void WithdrawMoney()
    {
        double WithdrawAmount;
        cout << "--------------------------" << endl;
        cout<<"Enter your amount that you want to withdraw : ";
        cin>>WithdrawAmount;

                if( WithdrawAmount > CurrentBalance )
                {
                    cout<<"Account has insufficient balance...";
                    cout << "--------------------------" << endl;
                }
                else
                {
                   CurrentBalance=CurrentBalance-WithdrawAmount;
                   cout<<"New Balance : "<<CurrentBalance<<endl;
                   cout << "--------------------------" << endl;
                }
    }

    void DisplayDetails()
    {
        cout << "--------------------------" << endl;   
        cout<<"Holder Name : "<<HolderName<<endl;
        cout<<"Number : "<<AccountNo<<endl;
        cout<<"CurrentBalance : "<<CurrentBalance<<endl;
        cout << "--------------------------" << endl;
        }
};
int main()
{
    Account A[20];
    int NumAcc=0;
    int choice;
    int CheckAccountNo;
    bool flag=false;
   next:
    cout<<"Enter '1' for create Account."<<endl;
    cout<<"Enter '2' for deposit money."<<endl;
    cout<<"Enter '3' for withdraw money."<<endl;
    cout<<"Enter '4' for Display Details."<<endl;
    cout<<"Enter '5' for Exit."<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            A[NumAcc].CreateAccount();
            NumAcc++;
            break;
        }
        case 2:
        {
            cout << "Enter Account no for check : ";
            cin >> CheckAccountNo;
            for (int i = 0; i < NumAcc; i++)
            {
                if(A[i].GetNO() == CheckAccountNo)
                {
                    flag=true;
                    A[i].DepositMoney();
                    break;
                }
            }
            if(!flag)
            { 
                cout << "Enter valid ID." << endl;
            }
            break;
        }
        
        case 3:
        {
            cout << "Enter product ID for check : ";
            cin >> CheckAccountNo;
            for (int i = 0; i < NumAcc; i++)
            {
                if(A[i].GetNO() == CheckAccountNo)
                {
                    flag = true;
                    A[i].WithdrawMoney();
                    break;
                }
                
            }
            if(!flag)
            { 
                cout << "Enter valid ID." << endl;
            }
            break;  
        }

        case 4:
        {
            cout << "Enter product ID for check : ";
            cin >> CheckAccountNo;
            for (int i = 0; i < NumAcc; i++)
            {
                if(A[i].GetNO() == CheckAccountNo)
                {
                    flag = true;
                    A[i].DisplayDetails();
                    break;
                }
                
            }
            if(!flag)
            { 
                cout << "Enter valid ID." << endl;
            }
            break;  
        }
        case 5:
        {
            cout<<"Thank you, Exit.";
            return 0;
        }
        default:
            cout << "Invalid choice, try again." << endl;
    }
    goto next;
}