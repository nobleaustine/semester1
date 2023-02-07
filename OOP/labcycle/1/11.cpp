#include <iostream>
using namespace std;
class class_2;
class class_1
{
	int data;
public:
    class_1(int x)
    {
        data=x;
    }
    void display();
	friend void swap_pri(class_1 &,class_2 &);
};
void class_1::display()
{
    cout<<"Private data member of class_1 : "<<data<<endl;
}
class class_2
{
   int data;
public:
    class_2(int x)
    {
        data=x;
    }
    void display();
	friend void swap_pri(class_1 &,class_2 &);
};
void class_2::display()
{
    cout<<"Private data member of class_2 : "<<data<<endl;
}

void swap_pri(class_1 &x,class_2 &y)
{
	int temp;
	temp = x.data;
	x.data = y.data;
	y.data = temp;
}
int main()
{
    int option=6;
    int x;
    cout<<"  Program to swap private data members"<<endl;

    while(option==6)
    {
    cout<<" "<<endl;
    cout<<"Enter the private data member of class_1 : ";
    cin>>x;
    class_1 obj1(x);
    cout<<" "<<endl;

    cout<<"Enter the private data member of class_2 : ";
    cin>>x;
    class_2 obj2(x);
    cout<<" "<<endl;

    cout<< "Data before swapping : "<<endl;
    cout<<" "<<endl;
	obj1.display();
	obj2.display();
	swap_pri(obj1,obj2);
	cout<<" "<<endl;
	cout<<"Data after swapping : "<<endl;
    cout<<" "<<endl;
	obj1.display();
	obj2.display();
     cout<<" "<<endl;
     cout<<"             Would you like to continue ? "<<endl;
     cout<<"Enter 6 to continue or any other number to end the program"<<endl;
     cin>>option;
     cout<<" "<<endl;
    }
    cout<<"---------- Thank You -----------"<<endl;
return 0;}


