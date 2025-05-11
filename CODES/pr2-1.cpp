#include<iostream>
using namespace std;

class PlotData
{
private:
    int l,w,a,p;

public:
    
    void AddData(){
        cout<<"Enter The Length :";
        cin>>l;
        cout<<"\nEnter The Width :";
        cin>>w;
        a= l*w;
        p= 2*(l+w);
        cout<<"Area: "<<a<<endl;
        cout<<"Perimeter: "<<p;
    }
    void UpdateData(){
        cout<<"Enter The Updated Length :";
        cin>>l;
        cout<<"\nEnter The Updated Width :";
        cin>>w;
        a= l*w;
        p= 2*(l+w);
        cout<<"Area"<<a<<endl;
        cout<<"Perimeter"<<p;
    }

    void DisplayData(){
        cout<<"The length of the plot is :"<<l<<endl;
        cout<<"The width of the plot is :"<<w<<endl;
        cout<<"Area :"<<a<<endl;
        cout<<"Perimeter :"<<p;
    }
};

int main(){
    int ch,c=0,pn;
    PlotData P[25];
    next : cout<<"\nEnter 1 to Add ; 2 to Update ; 3 to Display ; Else to Exit";
    cin>>ch;
    switch (ch)
    {
    case 1:
        P[c].AddData();
        c++;
        break;
    case 2:
        cout<<"Enter The Plot Number to Update Details :";
        x : cin>>pn;
        if (pn<=c){
            P[pn-1].UpdateData();
        }
        else{
            cout<<"Enter The Correct Plot Number :";
            goto x;
        }
        break;
    case 3:
        cout<<"Enter The Plot Number to Display Details :";
        y : cin>>pn;
        if (pn<=c){
            P[pn-1].DisplayData();
            break;
        }
        else{
            cout<<"Enter The Correct Plot Number :";
            goto y;
        }
    default :
        goto e; 
    }
    goto next;
    e : return 0;
};