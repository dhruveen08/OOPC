#include <iostream>
using namespace std;

class ArraySum {
private:
    int* arr; // Dynamic array for storing elements
    int size;

public:
    // Constructor to initialize the array
    ArraySum(int n) : size(n) {
        if (n <= 0) {
            cout << "Invalid array size. Setting size to 1.\n";
            size = 1;
        }
        arr = new int[size];
    }

    // Destructor to free allocated memory
    ~ArraySum() {
        delete[] arr;
    }

    // Copy Constructor
    ArraySum(const ArraySum& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Copy Assignment Operator
    ArraySum& operator=(const ArraySum& other) {
        if (this == &other) return *this;
        delete[] arr;
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    // Function to take input from the user
    void inputElements() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Recursive function to calculate sum
    int recursiveSum(int n) {
        if (n <= 0) return 0; // Base case
        return arr[n - 1] + recursiveSum(n - 1);
    }

    // Iterative function to calculate sum
    int iterativeSum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }

    // Function to compare results
    void compareResults() {
        int recSum = recursiveSum(size);
        int iterSum = iterativeSum();
        
        cout << "Recursive Sum: " << recSum << "\n";
        cout << "Iterative Sum: " << iterSum << "\n";
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size. Exiting program.\n";
        return 1;
    }

    ArraySum arraySum(n);
    arraySum.inputElements();
    arraySum.compareResults();
    
    return 0;
}