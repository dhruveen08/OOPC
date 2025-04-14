#include<iostream>
using namespace std;


class ProductDetails
{
        int id;
        char name[25];
        int quantity;
        int price;
        int total;

    public:
    void AddProduct(){
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
        P[i].AddProduct();
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