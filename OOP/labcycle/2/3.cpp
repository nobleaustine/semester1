#include <iostream>

using namespace std;
class Vector
{
    int v[3];
public:
    Vector();
    friend int operator *(Vector,Vector);
    friend istream & operator >> (istream &,Vector &);
    friend ostream & operator << (ostream &,Vector &);
};
 Vector::Vector()
{
  for(int i=0;i<3;i++)
  {v[i]=0;}
}

istream & operator >> (istream &vin,Vector &V)
{
  for(int i=0;i<3;i++)
  {
      vin>>V.v[i];
  }
  return (vin);
}
ostream & operator <<(ostream& vout,Vector& V)
{
    vout<<"[ ";
    for(int i=0;i<3;i++)
    {
        vout<<V.v[i]<<" ";
    }
    vout<<"]";
    return (vout);
}
int operator *(Vector V1,Vector V2)
{
    int temp=0;
    for(int i=0;i<3;i++)
    {
     temp=temp+V1.v[i]*V2.v[i];
    }
    return temp;
}



int main()
{
    cout<<" Program to carry out dot product of two vectors "<<endl;
    Vector v1,v2;
    int temp,option=6;
    int scale;
    while(option==6)
    {

    cout<<" "<<endl;
    cout<<"Enter the first vector  : ";
    cin>>v1;
    cout<<" "<<endl;
    cout<<"Vector-1 : ";
    cout<<v1;
    cout<<" "<<endl;
     cout<<" "<<endl;

    cout<<"Enter the second vector : ";
    cin>>v2;
    cout<<" "<<endl;
    cout<<"Vector-2 : ";
    cout<<v2;
    cout<<" "<<endl;
    cout<<" "<<endl;
    temp=v1*v2;
    cout<<"The dot product of the two vectors is "<<temp<<endl;
    cout<<" "<<endl;


          cout<<" "<<endl;
          cout<<"             Would you like to continue ? "<<endl;
          cout<<"Enter 6 to continue or any other number to end the program"<<endl;
          cin>>option;
          cout<<" "<<endl;
    }
cout<<"--------- Thank You ---------"<<endl;
    return 0;
}
