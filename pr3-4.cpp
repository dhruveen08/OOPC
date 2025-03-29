#include <iostream>
using namespace std;

// Template class for managing collections
template <typename T>
class Collection {
private:
    T* arr; // Dynamic array to store elements
    int size;

public:
    // Constructor
    Collection(int n) : size(n) {
        arr = new T[n];
    }

    // Destructor
    ~Collection() {
        delete[] arr;
    }

    // Function to input elements
    void inputElements() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Function to display elements
    void display() const {
        cout << "Collection: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    // Function to find the maximum element
    T findMax() const {
        T maxVal = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    // Function to reverse the collection
    void reverse() {
        for (int i = 0, j = size - 1; i < j; i++, j--) {
            swap(arr[i], arr[j]);
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the collection: ";
    cin >> n;

    // Integer Collection
    Collection<int> intCollection(n);
    intCollection.inputElements();
    intCollection.display();
    cout << "Max Value: " << intCollection.findMax() << "\n";
    intCollection.reverse();
    intCollection.display();

    // Floating-Point Collection
    Collection<double> floatCollection(n);
    floatCollection.inputElements();
    floatCollection.display();
    cout << "Max Value: " << floatCollection.findMax() << "\n";
    floatCollection.reverse();
    floatCollection.display();
    
    return 0;
}