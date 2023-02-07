#include <iostream>
#include <cmath>

using namespace std;
class Vector
{
    int x,y,z;
    float magnitude;
public:
    Vector()
    {
        x=0;
        y=0;
        z=0;
    }
    void input(void);
    void display(void);
    int operator ==(Vector);
    int operator !=(Vector);
    int operator >=(Vector);
    int operator <=(Vector);
    int operator  >(Vector);
    int operator  <(Vector);
};
void Vector::input()
{
    cout<<"Enter the x coordinate : ";
    cin>>x;
    cout<<"Enter the y coordinate : ";
    cin>>y;
    cout<<"Enter the z coordinate : ";
    cin>>z;
    magnitude=pow(x,2)+pow(y,2)+pow(z,2);
    magnitude=pow(magnitude,0.5);
    cout<<" "<<endl;
    cout<<"The magnitude of the given vector is "<<magnitude<<endl;
}
void Vector::display()
{
    cout<<x<<" "<<y<<" "<<z;
}
int Vector::operator==(Vector v)
{
    if(magnitude==v.magnitude)return(1);
    else return(0);
}
int Vector::operator!=(Vector v)
{
    if(magnitude!=v.magnitude)return(1);
    else return(0);
}
int Vector::operator>=(Vector v)
{
    if(magnitude>=v.magnitude)return(1);
    else return(0);
}
int Vector::operator<=(Vector v)
{
    if(magnitude<=v.magnitude)return(1);
    else return(0);
}
int Vector::operator>(Vector v)
{
    if(magnitude>v.magnitude)return(1);
    else return(0);
}
int Vector::operator<(Vector v)
{
    if(magnitude<v.magnitude)return(1);
    else return(0);
}
void input_output(Vector& v1,Vector& v2)
{
}



int main()
{
    Vector V1,V2;
    int option=6;
    while(option==6)
    {

    cout<<"Enter vector-1 : "<<endl;
    cout<<" "<<endl;
    V1.input();
    cout<<" "<<endl;
    cout<<"Enter vector-2 : "<<endl;
    cout<<" "<<endl;
    V2.input();
    cout<<" "<<endl;

        if(V1==V2)
        {cout<<"| ";
         V1.display();
         cout<<" |";
         cout<<" == ";
         cout<<"| ";
         V2.display();
         cout<<" |"<<endl;
          cout<<" "<<endl;

        {cout<<"| ";
         V1.display();
         cout<<" |";
         cout<<" >= ";
         cout<<"| ";
         V2.display();
         cout<<" |"<<endl;}

 cout<<" "<<endl;


        {cout<<"| ";
         V1.display();
         cout<<" |";
         cout<<" <= ";
         cout<<"| ";
         V2.display();
         cout<<" |"<<endl;}

}


        else if(V1!=V2)
        {cout<<"| ";
         V1.display();
         cout<<" |";
         cout<<" != ";
         cout<<"| ";
         V2.display();
         cout<<" |"<<endl;
         cout<<" "<<endl;

        if(V1>V2)
        {cout<<"| ";
         V1.display();
         cout<<" |";
         cout<<" >  ";
         cout<<"| ";
         V2.display();
         cout<<" |"<<endl;}


        else if(V1<V2)
        {cout<<"| ";
         V1.display();
         cout<<" |";
         cout<<" <  ";
         cout<<"| ";
         V2.display();
         cout<<" |"<<endl;}
         else
             {

              }
              cout<<" "<<endl;
        if(V1>=V2)
        {cout<<"| ";
         V1.display();
         cout<<" |";
         cout<<" >= ";
         cout<<"| ";
         V2.display();
         cout<<" |"<<endl;}


        else if(V1<=V2)
        {cout<<"| ";
         V1.display();
         cout<<" |";
         cout<<" <= ";
         cout<<"| ";
         V2.display();
         cout<<" |"<<endl;}
         else
             {

              }
       }


          cout<<" "<<endl;
          cout<<"             Would you like to continue ? "<<endl;
          cout<<"Enter 6 to continue or any other number to end the program"<<endl;
          cin>>option;
          cout<<" "<<endl;

 }
 cout<<"-------- Thank You ----------"<<endl;
    return 0;
}
