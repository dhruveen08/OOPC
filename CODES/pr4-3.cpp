#include <iostream>
using namespace std;

class Fuel {
protected:
    string FuelType;
public:
    Fuel(string f="") {
        FuelType=f;
    }
};

class Brand {
protected:
    string BrandName;
public:
    Brand(string b="") {
        BrandName=b;
    }
};

class Car:public Fuel,public Brand {
private:
    string CarName;
public:
    Car():Fuel(""),Brand("") {
        CarName="";
    }
    void SetDetails(string cn,string f,string b) {
        CarName=cn;
        FuelType=f;
        BrandName=b;
    }
    void DisplayDetail() {
        cout<<"\n*** Car Details ***"<<endl;
        cout<<"Car Name: "<<CarName<<endl;
        cout<<"Fuel Type: "<<FuelType<<endl;
        cout<<"Brand Name: "<<BrandName<<endl;
    }
};

int main() {
    Car cars[50];
    string cn,f,b;
    int i=0;
    char choice;
    do {
        cout<<"\nEnter details for car "<<i+1<<":"<<endl;
        cout<<"Enter Car Name: ";
        cin>>cn;
        cout<<"Enter Fuel Type: ";
        cin>>f;
        cout<<"Enter Brand Name: ";
        cin>>b;
        cars[i].SetDetails(cn,f,b);
        i++;
        cout<<"Do you want to add another car? (y/n): ";
        cin>>choice;
    } while((choice=='y'||choice=='Y')&&i<100);

    cout<<"\nDisplaying all car details:\n";
    for(int j=0;j<i;j++) {
        cars[j].DisplayDetail();
    }
    return 0;
}