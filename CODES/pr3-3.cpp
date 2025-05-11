#include<iostream>
using namespace std;

class BankAccount {
    char AccHolderName[20];
    long long Balance;
    long AccNum;

public:
    void AddAccDetails() {
        cout << "\n--- Add New Account ---"<<endl;
        cout << "Enter Account Number         : ";
        cin >> AccNum;
        cout << "Enter Account Holder's Name : ";
        cin >> AccHolderName;

        while (true) {
            cout << "Enter Initial Balance        : ";
            cin >> Balance;

            if (Balance < 0) {
                cout << "Initial balance cannot be negative. Please try again."<<endl;
            } else {
                break;
            }
        }

        cout << "Account added successfully!"<<endl;
    }

    void DisplayAccDetails() {
        cout << "\n--- Account Details ---"<<endl;
        cout << "Account Number        : " << AccNum << endl;
        cout << "Account Holder's Name : " << AccHolderName << endl;
        cout << "Current Balance       : " << Balance << endl;
    }

    long GetAccNum() {
        return AccNum;
    }

    long long GetBalance() {
        return Balance;
    }

    bool WithdrawMoney(long long Amount) {
        if (Amount > Balance || Amount < 0) {
            return false;
        }
        Balance -= Amount;
        return true;
    }

    bool DepositMoney(long long Amount) {
        if (Amount < 0) {
            return false;
        }
        Balance += Amount;
        return true;
    }
};

int FindAccount(long AccNum, BankAccount Acc[], int NumAcc) {
    for (int i = 0; i < NumAcc; i++) {
        if (Acc[i].GetAccNum() == AccNum) {
            return i;
        }
    }
    return -1;
}

int main() {
    BankAccount Acc[100];
    int NumAcc = 0;
    int Choice;
    long long Amount;


    cout << "  Enter Your Choice "<<endl;
    cout << "1. Add New Account"<<endl;
    cout << "2. Transfer Money"<<endl;
    cout << "3. Show Total Accounts"<<endl;
    cout << "4. Exit"<<endl;


    while (true) {

        cin >> Choice;

        switch (Choice) {
        case 1: {
            Acc[NumAcc].AddAccDetails();
            NumAcc++;
            break;
        }

        case 2: {
            long AccFindW, AccFindD;
            int ResultD, ResultW;

            cout << "\nMoney Transfer"<<endl;
            cout << "Enter Sender's Account Number   : ";
            cin >> AccFindW;
            ResultW = FindAccount(AccFindW, Acc, NumAcc);

            if (ResultW == -1) {
                cout << "Sender's account not found."<<endl;
                break;
            }

            cout << "Enter Receiver's Account Number : ";
            cin >> AccFindD;
            ResultD = FindAccount(AccFindD, Acc, NumAcc);

            if (ResultD == -1) {
                cout << "Receiver's account not found."<<endl;
                break;
            }

            cout << "Enter Amount to Transfer        : ";
            cin >> Amount;

            if (Amount <= 0) {
                cout << "Amount must be greater than zero."<<endl;
                break;
            }

            if (!Acc[ResultW].WithdrawMoney(Amount)) {
                cout << "Transfer failed: Insufficient balance."<<endl;
                break;
            }

            Acc[ResultD].DepositMoney(Amount);

            cout << "\nTransfer successful!"<<endl;
            cout << "\nTransaction Summary";
            Acc[ResultW].DisplayAccDetails();
            Acc[ResultD].DisplayAccDetails();
            break;
        }

        case 3: {
            cout << "\nTotal Accounts Created: " << NumAcc << endl;
            break;
        }
        case 4:
        {
            cout << "\nThank you,Exit."<<endl;
            return 0;
        }

        default: {
            cout << "\nInvalid choice! Please try again."<<endl;
        }
        }
    }
}