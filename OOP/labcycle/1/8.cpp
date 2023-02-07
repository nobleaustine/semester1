#include<iostream>
using namespace std;

class Complex
{
    float real;
    float imag;
public:
    Complex(void) {};
    Complex(float x)
    {
        real=x;
        imag=x;
    }
    Complex(float x, float y)
    {
        real = x;
        imag = y;
    }
    void display(void)
    {
        if (imag >= 0)
        {
         cout<<"( "<<real<<" + "<<imag<<"i"<<" )";
        }
        else
        {
         cout<<"( "<<real<<" - "<<(-1)*imag<<"i"<<" )";
        }
     }
    Complex add(Complex);
};

Complex Complex::add(Complex C)
{
    Complex temp;
    temp.real = real+C.real;
    temp.imag = imag+C.imag;
    return temp;
}


int main()
{
    int x,y;
    Complex c3;
    int option=6;
    cout<<"           Program to add two complex numbers"<<endl;
    cout<<" "<<endl;
    while(option==6)
    {
    cout<<"Enter the real part of Complex Number-1           : ";
    cin>>x;
    cout<<"Enter the imaginary part of Complex Number-1      : ";
    cin>>y;
    Complex c1(x,y);
    cout<<" "<<endl;

    cout<<"Enter the common value for real and imaginary part Complex Number-2    : ";
    cin>>x;
    Complex c2(x);
    cout<<" "<<endl;
    cout<<" "<<endl;

    cout<<"Complex Number-1 : ";
    c1.display();
    cout<<" "<<endl;
    cout<<" "<<endl;

    cout<<"Complex Number-2 : ";
    c2.display();
    c3=c1.add(c2);
    cout<<" "<<endl;
    cout<<" "<<endl;

    c1.display();cout<<" + ";c2.display();cout<<" = ";c3.display();
    cout<<" "<<endl;
    cout<<" "<<endl;

          cout<<"             Would you like to continue ? "<<endl;
          cout<<"Enter 6 to continue or any other number to end the program"<<endl;
          cin>>option;
          cout<<" "<<endl;
    }
    cout<<"---------- Thank You -----------"<<endl;
return 0;}
