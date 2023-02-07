#include <iostream>
using namespace std;


template< class T>
class calculator
{
    T num1;
    T num2;

public:
    calculator(T x,T y)
    {
        num1=x;
        num2=y;
    }
    T add(void)
    {return(num1+num2);}
    T sub(void)
    {return(num1-num2);}
    T mul(void)
    {return(num1*num2);}
    T div(void)
    {return(num1/num2);}
};
string per()
{
    string check;
    cout<<" "<<endl;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"        yes or no?       "<<endl;
    cin>>check;
    if(check!="yes"&&check!="no")
    {
        cout<<" "<<endl;
        cout<<"------------ Invalid Entry -------------"<<endl;
        cout<<" "<<endl;
        cout<<"Do you want to continue ?"<<endl;
        cout<<"        yes or no?       "<<endl;
        cin>>check;
    }
    cout<<" "<<endl;
    return check;
}
int main()
{int x,y;
float w,z;
int option;
cout<<"Program to find sum, difference, product and quotient of two numbers"<<endl;
while(option!=3)
{

    cout<<" "<<endl;
    cout<<"Choose any of the following to continue "<<endl;
    cout<<"To calculate for integers choose : 1 "<<endl;
    cout<<"To calculate for decimals choose : 2 "<<endl;
    cout<<"To end the program               : 3 "<<endl;
    cin>>option;
    if(option==1)
    {
        cout<<"--- Calculator for integers ---"<<endl;
        cout<<"  "<<endl;
        cout<<" Enter the value of first number  :";
        cin>>x;
        cout<<" Enter the value of second number :";
        cin>>y;
        calculator<int> calc1(x,y);
        cout<<"  "<<endl;
        cout<<x<<" + "<<y<<" = "<<calc1.add()<<endl;
        cout<<x<<" - "<<y<<" = "<<calc1.sub()<<endl;
        cout<<x<<" * "<<y<<" = "<<calc1.mul()<<endl;
        cout<<x<<" / "<<y<<" = "<<calc1.div()<<endl;
        if(per()=="no")
               {break;}
    }
    else if(option==2)
    {
       cout<<"--- Calculator for decimals ---"<<endl;
        cout<<"  "<<endl;
        cout<<" Enter the value of first number  :";
        cin>>w;
        cout<<" Enter the value of second number :";
        cin>>z;
        calculator<float>calc2(w,z);
        cout<<"  "<<endl;
        cout<<x<<" + "<<y<<" = "<<calc2.add()<<endl;
        cout<<x<<" - "<<y<<" = "<<calc2.sub()<<endl;
        cout<<x<<" * "<<y<<" = "<<calc2.mul()<<endl;
        cout<<x<<" / "<<y<<" = "<<calc2.div()<<endl;
        if(per()=="no")
               {break;}
    }
    else if(option==3)
    {
        break;
    }
    else
    {
        cout<<"-------- Invalid Entry --------"<<endl;
        if(per()=="no")
               {break;}
    }
}
cout<<"-------- Thank You --------"<<endl;


return 0;}
