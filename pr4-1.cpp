#include<iostream>
using namespace std;

class shape{
    private:
        float radius;

    public:
        void insert(){
            cout<<"Enter the Radius: "<<endl;
            cin>>radius;
        }

        float getR(){
            return radius;
        }
};


class circle : private shape{

    private:
        float area;

    public:
       void CalculateArea(){
        insert();
        area= 3.14*getR()*getR();
       }

       void DisplayArea(){
        cout<<"The Area of the Circle is :"<<area<<endl;

       }
};


int main(){

    circle c;
    c.CalculateArea();
    c.DisplayArea();
    cout<<sizeof(c)<<endl;

    return 0;
}