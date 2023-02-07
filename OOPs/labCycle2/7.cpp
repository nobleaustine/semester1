# include <iostream>

using namespace std;

class alpha
{

    int data1;
    float data2;
public:
    alpha(int x,float y)
    {
        data1=x;
        data2=y;
        cout<<" "<<endl;
        cout<<"--------- alpha constructor initialized ---------"<<endl;
        cout<<" "<<endl;
    }
    void display_alpha(void)
    {
        cout<<"Data1 of alpha = "<<data1<<endl;
        cout<<"Data2 of alpha = "<<data2<<endl;
    }
};

class beta
{
    int data1;
    char data2;
public:
    beta(int x,char y)
    {
        data1=x;
        data2=y;
        cout<<" "<<endl;
        cout<<"--------- beta constructor initialized ---------"<<endl;
        cout<<" "<<endl;

    }
    void display_beta(void)
    {
         cout<<"Data1 of beta = "<<data1<<endl;
         cout<<"Data2 of beta = "<<data2<<endl;
    }
};
class gamma:public alpha,public beta
{
    string data;
public:
    gamma(int x,int y,float w,char z,string v):alpha(x,w),beta(y,z)
    {
        data=v;
        cout<<" "<<endl;
        cout<<"--------- gamma constructor initialized ---------"<<endl;
        cout<<" "<<endl;
    }
    void display_gamma(void)
    {
          cout<<"Data of gamma = "<<data<<endl;
    }
};
int main()
{
    cout<<"Program to show constructor initialization during inheritance  "<<endl;
    cout<<" "<<endl;
    int x,y;
    float w;
    char z;
    string v;
    cout<<"Enter data1 of alpha class (integer) : ";
    cin>>x;
    cout<<"Enter data2 of alpha class (float)   : ";
    cin>>w;
    cout<<" "<<endl;
    cout<<"Enter data1 of beta class (integer)  : ";
    cin>>y;
    cout<<"Enter data2 of beta class(char)      : ";
    cout<<" "<<endl;
    cin>>z;
    cout<<"Enter data of gamma class(string)    : ";
    cin>>v;
    gamma obj(x,y,w,z,v);
    obj.display_alpha();
    cout<<" "<<endl;
    obj.display_beta();
    cout<<" "<<endl;
    obj.display_gamma();
return 0;}

