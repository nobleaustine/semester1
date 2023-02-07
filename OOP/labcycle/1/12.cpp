#include <iostream>
using namespace std;

class Complex
{
    float real;
    float imag;
public:
    Complex(void) {};
    Complex(float x, float y)
    {
        real = x;
        imag = y;
    }
    void display(void)
    {
        if (imag >= 0)
        {cout<<"("<<real<<" + "<<imag<<"i"<<")";}
        else
        {cout<<"("<<real<<" - "<<(-1)*imag<<"i"<<")";}

    }
    friend Complex add(Complex,Complex);
};

Complex add(Complex C1,Complex C2)
{
    Complex temp;
    temp.real = C1.real+C2.real;
    temp.imag = C1.imag+C2.imag;
    return temp;
}
int main()
{
    cout<<"     Program to add two complex numbers "<<endl;
    cout<<" "<<endl;
    int option=6;
    int x,y;
    while(option==6)
    {
    cout<<"Enter the real part of Complex Number-1   : ";
    cin>>x;
    cout<<"Enter imaginary part of  Complex Number-1 : ";
    cin>>y;
    Complex c1(x,y);
    cout<<" "<<endl;
    cout<<"Enter the real part of Complex Number-2   : ";
    cin>>x;
    cout<<"Enter imaginary part of  Complex Number-2 : ";
    cin>>y;
    Complex c2(x,y);
    Complex c3;
    c3=add(c1,c2);
    cout<<" "<<endl;
    c1.display();cout<<" + ";c2.display();cout<<" = ";c3.display();
    cout<<" "<<endl;
    cout<<" "<<endl;
     cout<<" "<<endl;
     cout<<"             Would you like to continue ? "<<endl;
     cout<<"Enter 6 to continue or any other number to end the program"<<endl;
     cin>>option;
     cout<<" "<<endl;

    }
    cout<<"---------- Thank You -----------"<<endl;
    return 0;}
