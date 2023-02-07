#include <iostream>
#include <cmath>

using namespace std;
string per()
{
    string check;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"        yes or no?       "<<endl;
    cin>>check;
    if(check!="yes"&&check!="no")
    {
    cout<<" "<<endl;
    cout<<"------------ Invalid Entry -------------"<<endl;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"        yes or no?       "<<endl;
    cin>>check;
    }
    return check;
}

int area(int a)
{
   int ar=a*a;
   return ar;
}
int area(int a,int b)
{
   int ar=a*b;
   return ar;
}
int area(int a,int b,int c)
{  int s=(a+b+c)/2;
   int ar2=s*(s-a)*(s-b)*(s-c);
   int ar=pow(ar2,0.5);
   return ar;
}
double area(double r)
{
   double ar=3.14*r*r;
   return ar;
}
double area(double a,double b)
{
   double ar=3.14*a*b;
   return ar;
}
double area(double a,double b,double h)
{
   double ar=0.5*h*(a+b);
   return ar;
}

int main()
{
    int choose;
    string t="******************** THANK YOU *********************";

    cout<<"               Program to print the area of figures                  "<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
 while(choose!=7)
    {
    cout<<" "<<endl;
    cout<<"Enter the appropriate number to calculate the area of the figures"<<endl;
    cout<<" "<<endl;
    cout<<"To calculate the area of square      :  1"<<endl;
    cout<<"To calculate the area of rectangle   :  2"<<endl;
    cout<<"To calculate the area of triangle    :  3"<<endl;
    cout<<"To calculate the area of circle      :  4"<<endl;
    cout<<"To calculate the area of ellipse     :  5"<<endl;
    cout<<"To calculate the area of a trapezium :  6"<<endl;
    cout<<"To exit the program                  :  7"<<endl;
    cout<<" "<<endl;
    cin>>choose;

  if(choose==1)
    {
    int l;
    cout<<"---------------------- SQUARE ---------------------------"<<endl;
    cout<<"Enter the length of the square (only integer value) : ";
    cin>>l;
    cout<<"Area of the square = "<<area(l)<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    cout<<" "<<endl;
    if(per()=="no")
     {cout<<" "<<endl;
      cout<<t<<endl;
         break;}
    }

  else if(choose==2)
    {
    int l,b;
    cout<<"------------------------- RECTANGLE -------------------------"<<endl;
    cout<<"Enter the length of the rectangle (only integer value)  : ";
    cin>>l;
    cout<<"Enter the breadth of the rectangle (only integer value) : ";
    cin>>b;
    cout<<"Area of rectangle = "<<area(l,b)<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    if(per()=="no")
     {cout<<" "<<endl;
      cout<<t<<endl;
         break;}
    }

  else if(choose==3)
    {
    int a,b,c;
    cout<<"------------------------- TRIANGLE ------------------------"<<endl;
    cout<<"Enter the side 1 of the triangle (only integer value) : ";
    cin>>a;
    cout<<"Enter the side 2 of the triangle (only integer value) : ";
    cin>>b;
    cout<<"Enter the side 3 of the triangle (only integer value) : ";
    cin>>c;
    cout<<"Area of triangle = "<<area(a,b,c)<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    if(per()=="no")
     {cout<<" "<<endl;
      cout<<t<<endl;
         break;}
    }

  else if(choose==4)
    {
    double r;
    cout<<"----------------------- CIRCLE -------------------------"<<endl;
    cout<<"Enter the radius of the circle : ";
    cin>>r;
    cout<<"Area of the circle = "<<area(r)<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    if(per()=="no")
     {cout<<" "<<endl;
      cout<<t<<endl;
     break;}
    }

  else if(choose==5)
    {
    double a,b;
    cout<<"-------------------------- ELLIPSE --------------------------"<<endl;
    cout<<"Enter the major axis of the ellipse : ";
    cin>>a;
    cout<<"Enter the minor axis of the ellipse : ";
    cin>>b;
    cout<<"Area of ellipse = "<<area(a,b)<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    if(per()=="no")
     {cout<<" "<<endl;
      cout<<t<<endl;
     break;}
    }

 else if (choose==6)
    {
    double a,b,h;
    cout<<"--------------------------------- TRAPEZIUM -------------------------------"<<endl;
    cout<<"Enter the smallest parallel side of the trapezium : "<<endl;
    cin>>a;
    cout<<"Enter the largest parallel side of the trapezium  : "<<endl;
    cin>>b;
    cout<<"Enter the height of the trapezium                 : "<<endl;
    cin>>h;
    cout<<"Area of trapezium = "<<area(a,b,h)<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    if(per()=="no")
     {cout<<" "<<endl;
      cout<<t<<endl;
     break;}
    }

  else if (choose==7)
    {
    cout<<" "<<endl;
    cout<<t<<endl;
    }

  else
    {
    cout<<" "<<endl;
    cout<<"---------------- Invalid Entry -----------------"<<endl;
    }
}
return 0;
}
