#include <iostream>
using namespace std;

int DigitSum(long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int SuperDigit(long long num) {
    if (num < 10) return num; 
    return SuperDigit(DigitSum(num));
}

int main() {
    string n;
    int k;
    
    cout << "Enter n (as string): ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    long long sum_n = 0;
    for (char digit : n) {
        sum_n += (digit - '0');
    }

    long long initialSum = sum_n * k;
    int result = SuperDigit(initialSum);

    cout << "Super Digit: " << result << endl;
    return 0;
}