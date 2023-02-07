#include <iostream>

using namespace std;
class Complex
{
    int real,imag;
public:
    Complex()
    { real=0;
      imag=0;
    }
    void input(void);
    void display(void);
    friend Complex operator+(Complex,Complex);
    friend Complex operator*(Complex,Complex);
};
void Complex::input(void)
{
    cout<<"Enter the real part of the complex number      : ";
    cin>>real;
    cout<<"Enter the imaginary part of the complex number : ";
    cin>>imag;
}
void Complex::display(void)
{
    if(imag>=0)
    {
        cout<<real<<" + "<<imag<<"i";
    }
    else
    {

        cout<<real<<" - "<<-1*imag<<"i";

    }
}
Complex operator+(Complex C1,Complex C2)
{
    Complex C3;
    C3.real=C1.real+C2.real;
    C3.imag=C1.imag+C2.imag;
    return C3;
}
Complex operator*(Complex C1,Complex C2)
{
    Complex C3;
    C3.real=((C1.real*C2.real)-(C1.imag*C2.imag));
    C3.imag=((C1.real*C2.imag)+(C1.imag*C2.real));
    return C3;
}
void input_output(Complex& C1,Complex& C2)
{


}

int main()
{
     cout<<"Program to add and multiply two complex numbers"<<endl;
    Complex c1,c2,c3,c4;
    int option=6;
    while(option==6)
    {
        cout<<" "<<endl;
        cout<<"Enter first complex number : "<<endl;
        cout<<" "<<endl;
        c1.input();
        cout<<" "<<endl;
        cout<<"Enter second complex number : "<<endl;
        cout<<" "<<endl;
        c2.input();
        cout<<" "<<endl;


        c3=c1+c2;
        cout<<" "<<endl;
        cout<<"(";c1.display();cout<<")";cout<<" + ";cout<<"(";c2.display();cout<<")";cout<<" = ";c3.display();
        cout<<" "<<endl;


        c3=c1*c2;
        cout<<" "<<endl;
        cout<<"(";c1.display();cout<<")";cout<<" * ";cout<<"(";c2.display();cout<<")";cout<<" = ";c3.display();


          cout<<" "<<endl;
          cout<<" "<<endl;
          cout<<"             Would you like to continue ? "<<endl;
          cout<<"Enter 6 to continue or any other number to end the program"<<endl;
          cin>>option;
          cout<<" "<<endl;

}
cout<<"------------ Thank You --------------"<<endl;



return 0;
}
