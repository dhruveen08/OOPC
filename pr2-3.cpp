#include<iostream>
using namespace std;

class AccountDetails{
    private:
        char Name[20];
        int AccNo;
        float Balance;
    
        public:
            void CreateAccount(){
                cout << "Enter Account Holder Name:";
                cin >> Name;
                cout << "Enter the Unique Account Number: ";
                cin >> AccNo;
                cout << "Enter the opening balance:";
                cin >> Balance;
            }

            void DepositAmt(long number){
                int amt;
                if (AccNo==number){
                    cout << "Enter the Amount to be deposited : ";
                    cin >> amt;
                    Balance = Balance + amt;
                    cout << "Current Balance : " << Balance;
                }
            }

            void WithdrawAmt();

            void DisplayDetails();

};

int main(){
    int i,j=0,k;
    long number;
    AccountDetails A[10];
    x: cout<<"Enter 1 to Login thru Account Number or else 2 to Create a Account : ";
    cin>>i;
    switch (i)
    {
    case 1:
        cout<<"Enter the 10 digit Account Number : ";
        cin>>number;
        break;
    
    case 2:
        A[j].CreateAccount();
        j++;
        goto x;
        break;
    default:
        cout<<"Enter the correct choice:";
        goto x;
        break;
    }
    y: cout << "Enter 1 to Deposit, 2 to Withdraw, 3 to Display and 4 to Exit : ";
    cin >> k;
    switch (k)
    {
    case 1:
        for (int a = 0; a < 10; a++)
        {
            A[a].DepositAmt(number);
        }
        goto y;

    case 2:
        for (int b = 0; b < 10; b++)
        {
            A[b].WithdrawAmt
        }
    
    default:
        break;
    }
   return 0;     
}

