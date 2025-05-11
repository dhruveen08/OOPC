#include <iostream>
using namespace std;


int RecursiveSum(int arr[], int n) {
    if (n <= 0)
        return 0; 
    return RecursiveSum(arr, n - 1) + arr[n - 1];
}

int IterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;

    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int SumRec = RecursiveSum(arr, size);
    int SumIter = IterativeSum(arr, size);

    cout << "Recursive Sum: " << SumRec << endl;
    cout << "Iterative Sum: " << SumIter << endl;

   
    delete[] arr;

    return 0;
}