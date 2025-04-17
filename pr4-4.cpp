#include <iostream>
using namespace std;

class BankAccount{
    protected:
        int AccountNumber,Balance,PreviousBalance;
    public:
        BankAccount(int an,int b)
        {
            AccountNumber=an;
            Balance=b;
            PreviousBalance=Balance;
        }
};

class SavingAccount: public BankAccount{
    private:
        float InterestRate;
    public:
        SavingAccount(int an,int b,float ir):BankAccount(an,b){
            InterestRate=ir;
            cout<<"Saving account created successfully!"<<endl;
        }
        void DepositS(int amount){
            PreviousBalance=Balance;
            Balance+=amount;
            cout<<"Amount "<<amount<<" deposited successfully!"<<endl;
            cout<<"Current balance: "<<Balance<<endl;
        }
        void WithdrawS(int amount)
        {
            PreviousBalance=Balance;
            Balance-=amount;
            cout<<"Amount "<<amount<<" withdrawn successfully!"<<endl;
            cout<<"Current balance: "<<Balance<<endl;
        }
        void UndoS()
        {
            Balance=P_DETACH;
            cout<<"Undo done and current balance: "<<Balance<<endl;
        }
};

class CurrentAccount: public BankAccount{
    private:
        int OverDraftLimit;
    public:
        CurrentAccount(int an,int b,int odl=0):BankAccount(an,b){
            OverDraftLimit=odl;
            cout<<"Cuurent account created succesfully!"<<endl;
        }
        void DepositC(int amount){
            PreviousBalance=Balance;
            Balance+=amount;
            cout<<"Amount "<<amount<<" deposited successfully!"<<endl;
            cout<<"Current balance: "<<Balance<<endl;
        }
        void WithdrawC(int amount)
        {
            PreviousBalance=Balance;
            if(amount>Balance+OverDraftLimit)
            {
                cout<<"Amount is not enough to withdraw! Withdraw denied"<<endl;
            }
            else{
                Balance-=amount;
                cout<<"Amount "<<amount<<" withdrawn successfully!"<<endl;
                cout<<"Current balance: "<<Balance<<endl;
            }
        }
        void UndoC()
        {
            Balance=PreviousBalance;
            cout<<"Undo done and current balance: "<<Balance<<endl;
        }
};

int main(){
    int an,b,odl,amount;
    float ir;

    int CreatingAccount,Transactions;
    cout<<"Enter 1 to create saving account\nEnter 2 to create current account\n";
    cout<<"Enter your choice: ";
    cin>>CreatingAccount;

    switch(CreatingAccount){
        case 1:{
            cout<<"Enter Account Number: ";
            cin>>an;
            cout<<"Enter Initial Balance: ";
            cin>>b;
            cout<<"Enter Interest Rate: ";
            cin>>ir;
            SavingAccount accountS(an,b,ir);
            do{
                cout<<"Enter 1 to Deposit amount\nEnter 2 to withdraw amount\nEnter 3 to undo last transaction\nEnter 0 to exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>Transactions;

                switch(Transactions){
                    case 1:
                        cout<<"Enter amount to deposit: ";
                        cin>>amount;
                        accountS.DepositS(amount);
                        break;
                    case 2:
                        cout<<"Enter amount to withdraw: ";
                        cin>>amount;
                        accountS.WithdrawS(amount);
                        break;
                    case 3:
                        accountS.UndoS();
                        break;
                    case 0:
                        cout<<"Thank you!"<<endl;
                        break;
                    default:
                        cout<<"Enter valid choice!"<<endl;
                }
            }while(Transactions!=0);
        }
            break;
        case 2:{
            cout<<"Enter Account Number: ";
            cin>>an;
            cout<<"Enter Initial Balance: ";
            cin>>b;
            cout<<"Enter Over Draft Limit: ";
            cin>>odl;
            CurrentAccount accountC(an,b,odl);
            do{
                cout<<"Enter 1 to Deposit amount\nEnter 2 to withdraw amount\nEnter 3 to undo last transaction\nEnter 0 to exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>Transactions;

                switch(Transactions){
                    case 1:
                        cout<<"Enter amount to deposit: ";
                        cin>>amount;
                        accountC.DepositC(amount);
                        break;
                    case 2:
                        cout<<"Enter amount to withdraw: ";
                        cin>>amount;
                        accountC.WithdrawC(amount);
                        break;
                    case 3:
                        accountC.UndoC();
                        break;
                    case 0:
                        cout<<"Thank you!"<<endl;
                        break;
                    default:
                        cout<<"Enter valid choice!"<<endl;
                }
            }while(Transactions!=0);
        }
            break;
        default:
            cout<<"Enter valid choice! and try again"<<endl;
    }
    return 0;
}