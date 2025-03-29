#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    static int totalAccounts; // Static variable to track total accounts
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(int accNum, string name, double initialBalance) {
        accountNumber = accNum;
        accountHolder = name;
        balance = initialBalance;
        totalAccounts++;
    }

    // Destructor
    ~BankAccount() {
        totalAccounts--;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Function to withdraw money
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << "\n";
            return true;
        } else {
            cout << "Insufficient funds or invalid amount.\n";
            return false;
        }
    }

    // Function to transfer money between accounts
    void transfer(BankAccount &recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            cout << "Transfer successful.\n";
        } else {
            cout << "Transfer failed.\n";
        }
    }

    // Display account details
    void displayAccount() const {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << accountHolder << "\n";
        cout << "Balance: " << balance << "\n";
    }

    // Static function to get total accounts
    static int getTotalAccounts() {
        return totalAccounts;
    }
};

// Initialize static member
int BankAccount::totalAccounts = 0;

int main() {
    // Creating accounts
    BankAccount acc1(1001, "Alice", 5000);
    BankAccount acc2(1002, "Bob", 3000);
    
    // Display initial account details
    acc1.displayAccount();
    acc2.displayAccount();
    
    // Perform transactions
    acc1.deposit(2000);
    acc1.withdraw(1500);
    acc1.transfer(acc2, 1000);
    
    // Display final details
    acc1.displayAccount();
    acc2.displayAccount();
    
    // Show total accounts
    cout << "Total Accounts: " << BankAccount::getTotalAccounts() << "\n";
    
    return 0;
}
