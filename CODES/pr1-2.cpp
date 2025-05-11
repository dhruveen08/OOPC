#include <iostream>
using namespace std;

class ProductDetails {
    int id;
    char name[25];
    int quantity;
    int price;

public:
    void AddProduct() {
        cout << "Enter The Id: ";
        cin >> id;
        cout << "Enter name of the product: ";
        cin >> name;
        cout << "Enter the price: ";
        cin >> price;
        quantity = 1;
    }

    int GetId() {
        return id;
    }

    void UpdateQuant() {
        quantity++;
    }

    int TotalCost() {
        return price * quantity;
    }

    void ShowProduct() {
        cout << "Product ID: " << id << ", Name: " << name << ", Quantity: " << quantity
             << ", Price: " << price << ", Total: " << TotalCost() << endl;
    }
};

int main() {
    int i, prodid;
    ProductDetails P[2];

    for (i = 0; i < 2; i++) {
        P[i].AddProduct();
    }

    cout << "\nEnter the Id to change the quantity: ";
    cin >> prodid;

    for (i = 0; i < 2; i++) {
        if (P[i].GetId() == prodid) {
            P[i].UpdateQuant();
            break;
        }
    }

    int grandTotal = 0;
    cout << "\nProduct Summary:\n";
    for (i = 0; i < 2; i++) {
        P[i].ShowProduct();
        grandTotal += P[i].TotalCost();
    }

    cout << "\nGrand Total of All Products: " << grandTotal << endl;

    return 0;
}
