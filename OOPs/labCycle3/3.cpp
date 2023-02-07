#include <iostream>
using namespace std;

int main()
{
cout<<"Program to demonstrate exception handling"<<endl;
int option=6;
	while(option==6)
	{
		float a,b,c,d,x,y;
		cout<<" "<<endl;
		cout<<"Enter values of a : ";
		cin>>a;
		cout<<"Enter values of b : ";
		cin>>b;
		cout<<" "<<endl;

		cout<<"Enter values of c : ";
		cin>>c;
		cout<<"Enter values of d : ";
		cin>>d;
		cout<<" "<<endl;

		x = a-b;
		cout<<"x = a-b "<<endl;
		cout<<"x = "<<x<<endl;
		cout<<" "<<endl;

		y = c-d;
		cout<<"y = c-d "<<endl;
		cout<<"y = "<<y<<endl;
		try
		{
			if(y!=0)
			{
			    cout<<" "<<endl;
				cout<<"x/y = "<<x/y<<endl;
				cout<<" "<<endl;
			}
			else
				throw(y);
		}
		catch(float c)
		{
		    cout<<" "<<endl;
			cout<<"        Exception identified : x = "<< x <<endl;
			cout<<"--------- Division by zero is not defined --------"<<endl;
			cout<<" "<<endl;
		}
		cout<<"         Do you want to continue ?"<<endl;
		cout<<"Press 6 to continue or any other number to exit"<<endl;
		cin>>option;



	}

	cout<<"---------- Thank You ---------"<<endl;
	return 0;

}
