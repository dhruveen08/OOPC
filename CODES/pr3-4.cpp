#include <iostream>
using namespace std;

template <typename T>
void DisplayElements(T arr[], int size)
{
    cout << "\nInput Summary"<<endl;
    cout << "Original elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1) cout << " - ";
    }
    cout << endl;
}

template <typename T>
void MaxValue(T arr[], int size)
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i]) max = arr[i];
    }
    cout << "Max Value"<<endl;
    cout << "Maximum element: " << max << endl;
}

template <typename T>
void ReverseCollection(T arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }

    cout << "Reversed Collection"<<endl;
    cout << "Reversed elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1) cout << " - ";
    }
    cout << endl;
}

int main()
{
    int choice;

    do {
        cout << "Select Data Type to Process:"<<endl;
        cout << "1. Integer"<<endl;
        cout << "2. Float"<<endl;
        cout << "3. Character"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int arr[100], element;
            int i = 0;
            cout << "\nEnter integers (enter 0 to stop):"<<endl;
            while (true)
            {
                cin >> element;
                if (element == 0) break;
                arr[i++] = element;
            }
            if (i == 0) break;
            DisplayElements(arr, i);
            MaxValue(arr, i);
            ReverseCollection(arr, i);
            break;
        }

        case 2:
        {
            float arr[100], element;
            int i = 0;
            cout << "\nEnter float values (enter 0 to stop):"<<endl;
            while (true)
            {
                cin >> element;
                if (element == 0.0) break;
                arr[i++] = element;
            }
            if (i == 0) break;
            DisplayElements(arr, i);
            MaxValue(arr, i);
            ReverseCollection(arr, i);
            break;
        }

        case 3:
        {
            char arr[100], element;
            int i = 0;
            cout << "\nEnter characters (enter '!' to stop):"<<endl;
            while (true)
            {
                cin >> element;
                if (element == '!') break;
                arr[i++] = element;
            }
            if (i == 0) break;
            DisplayElements(arr, i);
            MaxValue(arr, i);
            ReverseCollection(arr, i);
            break;
        }

        case 4:
            cout << "\nThank you,Exit."<<endl;
            break;

        default:
            cout << "\nInvalid choice! Please try again."<<endl;
        }

    } while (choice != 4);

    return 0;
}