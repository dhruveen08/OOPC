#include<iostream>
using namespace std;
class Bank_Acccount
{
    char Holdername[20];
    int AccountNo;
    long Balance;
    public:
    void Account_details()
    {
        cout<<"Enter Holder name:";
        cin>>Holdername;
        cout<<"Enter Account number:";
        cin>>AccountNo;
        Balance=1000;
    }
    void Deposit(long x)
    {
        if(AccountNo==x)
        {
            int j;
            cout<<"Enter The Amount to be deposited:";
            cin>>j;
            Balance= Balance+ j;
            cout<<"The Current Account Balance is:"<<Balance;

        }
    }
    void Withdraw(long y)
    {
        if(AccountNo==y)
        {
            int k;
            cout<<"Enter The Amount to be Withdraw:";
            cin>>k;
            Balance= Balance- k;
            cout<<"The Current Account Balance is:"<<Balance;
        }
    }
};
int main()
{
    Bank_Acccount S[5];
    int i;
    long findAccount;
    for(i=0;i<5;i++)
    {
        S[i].Account_details();
    }
    cout<<"Enter the account number:";
    cin>>findAccount;
    for( i=0;i<5;i++)
    {
        S[i].Deposit(findAccount);
        break;
    }
    cout<<"Enter the account number:";
    cin>>findAccount;
    for( i=0;i<5;i++)
    {
        S[i].Withdraw(findAccount);
        break;
    }

    return 0;
}

