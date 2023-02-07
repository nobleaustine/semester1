# include <iostream>
#include <cstring>
using namespace std;

class shape
{
protected:
    float area;
public:
   virtual void input()=0;
   virtual void calculate()=0;
   virtual void display()=0;
};
class circle: public shape
{
  float radius;
public:
   void input(void)
{cout<<"Enter the radius of the circle : ";
 cin>>radius;}
   void calculate(void)
{ area=(3.14)*(radius*radius);}
   void display(void)
{cout<<"Area of the circle = "<<area<<endl;}
};
class rectangle: public shape
{
  float length;
  float breadth;
public:
   void input(void)
{cout<<"Enter the length of the rectangle : ";
 cin>>length;
 cout<<"Enter the breadth of the rectangle : ";
 cin>>breadth;}
   void calculate(void)
{ area=length*breadth;}
   void display(void)
{cout<<"Area of the rectangle = "<<area<<endl;}
};
class ellipse: public shape
{
  float maj_axis;
  float min_axis;
public:
   void input(void)
{cout<<"Enter the major axis of the rectangle : ";
 cin>>maj_axis;
 cout<<"Enter the minor axis of the rectangle : ";
 cin>>min_axis;}
   void calculate(void)
{ area=3.14*(maj_axis*min_axis);}
   void display(void)
{cout<<"Area of the ellipse = "<<area<<endl;}
};
class square: public shape
{
  float length;
public:
   void input(void)
{cout<<"Enter the length of the square : ";
 cin>>length;
}
   void calculate(void)
{ area=length*length;}
   void display(void)
{cout<<"Area of the square = "<<area<<endl;}
};
int main()

{
string option;
shape* bptr;
cout<<"    Program to calculate area of shapes"<<endl;
cout<<" "<<endl;
while(option!="end")
{

cout<<"Choose any of the following options to continue  "<<endl;
cout<<"To calculate the area of a circle    : circle"<<endl;
cout<<"To calculate the area of a rectangle : rectangle"<<endl;
cout<<"To calculate the area of a square    : square"<<endl;
cout<<"To calculate the area of a ellipse   : ellipse"<<endl;
cout<<"To end the program                   : end"<<endl;
cin>>option;
cout<<" "<<endl;
if(option=="circle")
{
bptr=new circle;
bptr->input();
cout<<" "<<endl;
bptr->calculate();
bptr->display();
cout<<" "<<endl;
}
else if(option=="rectangle")
{
bptr=new rectangle;
bptr->input();
cout<<" "<<endl;
bptr->calculate();
bptr->display();
cout<<" "<<endl;
}
else if(option=="ellipse")
{
bptr=new ellipse;
bptr->input();
cout<<" "<<endl;
bptr->calculate();
bptr->display();
cout<<" "<<endl;
}
else if(option=="square")
{
bptr=new square;
bptr->input();
cout<<" "<<endl;
bptr->calculate();
bptr->display();
cout<<" "<<endl;
}
else
{
    cout<<" "<<endl;
    cout<<"------------- Invalid Entry -------------"<<endl;
    cout<<" "<<endl;}
}
cout<<"Thank You "<<endl;
return 0;}
