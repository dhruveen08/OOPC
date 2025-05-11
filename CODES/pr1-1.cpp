#include <iostream>
using namespace std;

class BankAccount {
    char Holdername[20];
    int AccountNo;
    long Balance;

public:
    void AccountDetails() {
        cout << "Enter Holder name: ";
        cin >> Holdername;
        cout << "Enter Account number: ";
        cin >> AccountNo;
        Balance = 1000;
    }

    void Deposit(long x) {
        if (AccountNo == x) {
            int j;
            cout << "Enter The Amount to be deposited: ";
            cin >> j;
            Balance = Balance + j;
            cout << "The Current Account Balance is: " << Balance << endl;
        }
    }

    void Withdraw(long y) {
        if (AccountNo == y) {
            int k;
            cout << "Enter The Amount to be Withdraw: ";
            cin >> k;
            if (k > Balance) {
                cout << "Insufficient Balance!" << endl;
            } else {
                Balance = Balance - k;
                cout << "The Current Account Balance is: " << Balance << endl;
            }
        }
    }
};

int main() {
    BankAccount S[5];
    int i;
    long findAccount;

    for (i = 0; i < 5; i++) {
        cout << "\nEnter details for account " << i + 1 << ":\n";
        S[i].AccountDetails();
    }

    cout << "\nEnter the account number to deposit: ";
    cin >> findAccount;
    for (i = 0; i < 5; i++) {
        S[i].Deposit(findAccount);
    }

    cout << "\nEnter the account number to withdraw: ";
    cin >> findAccount;
    for (i = 0; i < 5; i++) {
        S[i].Withdraw(findAccount);
    }

    return 0;
}
