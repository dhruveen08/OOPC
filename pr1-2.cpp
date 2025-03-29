#include<iostream>
using namespace std;

/*Write a program for an inventory management system using both procedural and
object-oriented approaches. The system should handle products with attributes:
ID, name, quantity, and price.
Implement these functionalities:
o Add a new product.
o Update the quantity of an existing product.
o Calculate the total value of all products.
Objective: Compare the procedural and object-oriented implementations by
evaluating code reusability and complexity.
*/

class ProductDetails
{
        int id;
        char name[25];
        int quantity;
        int price;
        int total;

    public:
    void Addproduct(){
        cout<<"Enter The Id:";
        cin>>id;
        cout<<"Enter name of the product:";
        cin>>name;
        cout<<"Enter the price:";
        cin>>price;
        quantity=1;
    }
    
    int CheckId(){
        for (int i=0; i<2; i++){
            int j= id;
            return j;
        }
    }

    void UpdateQuant(){
        quantity++;
    }
    
    void TotalCost(){
        static int total;
        total=total+(price*quantity);
    }
    
    
};


int main(){

    int i;
    int prodid;

    ProductDetails P[2];

    for(i=0;i<2;i++)
    {
        P[i].Addproduct();
    }
    cout<<"Enter the Id to change the quantity:";
    cin>>prodid;
    
    for(i=0;i<2;i++)
    {
        P[i].UpdateQuant();
        break;
    }

    for(i=0;i<2;i++)
    {
        P[i].TotalCost();
        break;
    }
   return 0; 
}