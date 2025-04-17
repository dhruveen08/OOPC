#include<iostream>
using namespace std;

class Inventory {
    int itemid;
    char itemname[20];
    float price;
    int quantity;

public:
    void AddItemDetails() {
        cout << "Enter item ID: ";
        cin >> itemid;
        cout << "Enter item's name: ";
        cin >> itemname;
        cout << "Enter price of item: ";
        cin >> price;
        quantity = 1;
    }

    int GetItemId() {
        return itemid;
    }

    void IncreaseItemQuantity() {
        int newquantity;
        cout << "Enter quantity to be increased: ";
        cin >> newquantity;
        quantity += newquantity;
        cout << "Item's quantity is successfully increased!" << endl;
    }

    void DecreaseItemQuantity() {
        int newquantity;
        cout << "Enter quantity to be decreased: ";
        cin >> newquantity;
        if (quantity >= newquantity) {
            quantity -= newquantity;
            cout << "Item's quantity is successfully decreased!" << endl;
        } else {
            cout << "Insufficient quantity for decrement!" << endl;
        }
    }

    void DisplayItemDetails() {
        cout << "\nItem's details:" << endl;
        cout << "ID: " << itemid << endl;
        cout << "Name: " << itemname << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

int main() {
    Inventory items[100];
    int numitems = 0;
    int itemfind, choice;

    cout << "Enter 1 to add item." << endl;
    cout << "Enter 2 to increase quantity." << endl;
    cout << "Enter 3 to decrease quantity." << endl;
    cout << "Enter 4 to display item's details." << endl;
    cout << "Enter 0 to exit." << endl;
    cout << "==================================" << endl;

    while (true) {
        cout << "\nEnter the option which you want: ";
        cin >> choice;

        bool found = false;

        switch (choice) {
        case 1:
            items[numitems].AddItemDetails();
            numitems++;
            break;

        case 2:
            cout << "Enter item ID: ";
            cin >> itemfind;
            for (int i = 0; i < numitems; i++) {
                if (items[i].GetItemId() == itemfind) {
                    items[i].IncreaseItemQuantity();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Item not found!" << endl;
            break;

        case 3:
            cout << "Enter item ID: ";
            cin >> itemfind;
            for (int i = 0; i < numitems; i++) {
                if (items[i].GetItemId() == itemfind) {
                    items[i].DecreaseItemQuantity();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Item not found!" << endl;
            break;

        case 4:
            cout << "Enter item ID: ";
            cin >> itemfind;
            for (int i = 0; i < numitems; i++) {
                if (items[i].GetItemId() == itemfind) {
                    items[i].DisplayItemDetails();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Item not found!" << endl;
            break;

        case 0:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
