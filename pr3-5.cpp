#include <iostream>
using namespace std;

// Function to compute the sum of digits of a number
int digitSum(long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Recursive function to compute the super digit
int superDigit(long long num) {
    if (num < 10) return num; // Base case: single-digit number
    return superDigit(digitSum(num)); // Recursive call
}

int main() {
    string n;
    int k;
    
    cout << "Enter n (as string): ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    // Compute sum of digits of n
    long long sum_n = 0;
    for (char digit : n) {
        sum_n += (digit - '0'); // Convert char to int and sum
    }

    // Compute super digit of sum_n * k
    long long initialSum = sum_n * k;
    int result = superDigit(initialSum);

    cout << "Super Digit: " << result << endl;
    return 0;
}