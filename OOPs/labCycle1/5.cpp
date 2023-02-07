#include<iostream>
using namespace std;

class matrix
{
    int row,col;
    int**m;
public:
    matrix(int,int);
    ~matrix();
    void input(void);
    void display(void);
    void add(matrix &,matrix &);
};
matrix::matrix(int x,int y)
{
    row=x;
    col=y;
    m=new int*[row];
    for(int i=0;i<row;i++)
    {
        m[i]=new int[col];
    }
    cout<<" "<<endl;
    cout<<"----------- Constructor called -------------"<<endl;
    cout<<" "<<endl;
}
matrix::~matrix()
{
    for(int i=0;i<row;i++)
    {delete m[i];}
    delete m;
    cout<<" "<<endl;
    cout<<"----------- Destructor called -------------"<<endl;
    cout<<" "<<endl;
}
void matrix::input()
{
    for(int i=0;i<row;i++)
    {for(int j=0;j<col;j++)
        {cout<<"m"<<i+1<<j+1<<"=";
        cin>>m[i][j];}
        cout<<" "<<endl;
    }
}
void matrix::display()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<m[i][j]<<" ";
        }cout<<" "<<endl;
    }
}
void matrix::add(matrix &M1,matrix &M2)
{

        for(int i=0;i<row;i++)
        {for(int j=0;j<col;j++)
        {
        m[i][j]=M1.m[i][j] + M2.m[i][j];
        }}

}
int main()
{
    int x,y,w,z;
    cout<<"           Program to add two matrices"<<endl;
    cout<<" "<<endl;
    cout<<"Enter the number of rows of the Matrix-1    : ";
    cin>>x;
    cout<<"Enter the number of columns of the Matrix-1 : ";
    cin>>y;
    cout<<" "<<endl;
    matrix m1(x,y);
    cout<<"Enter the elements of matrix-1 : "<<endl;
    cout<<" "<<endl;
    m1.input();
    cout<<"Matrix-1 :"<<endl;
    cout<<" "<<endl;
    m1.display();
    cout<<" "<<endl;
    cout<<"Enter the number of rows of the Matrix-2    : ";
    cin>>w;
    cout<<"Enter the number of columns of the Matrix-2 : ";
    cin>>z;
    cout<<" "<<endl;
    matrix m2(w,z);
    cout<<"Enter the elements of matrix-2 : "<<endl;
    cout<<" "<<endl;
    m2.input();
    cout<<"Matrix-2 : "<<endl;
    m2.display();
    cout<<" "<<endl;
    if(x==w&&y==z)
    {
    matrix m3(x,y);
    cout<<"Matrix-1 + Matrix-2 = Matrix-3 "<<endl;
    cout<<" "<<endl;
    m3.add(m1,m2);
    cout<<"Matrix-3 : "<<endl;
    cout<<" "<<endl;
    m3.display();
    }
    else
    {
            cout<<" "<<endl;
            cout<<" Addition cannot be performed as number of rows and columns are not matching "<<endl;
            cout<<" "<<endl;
    }
    return 0;
}
