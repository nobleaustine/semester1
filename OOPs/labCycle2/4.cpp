#include <iostream>

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
    matrix operator + (matrix &);
    matrix operator * (matrix &);
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
}
matrix::~matrix()
{
    for(int i=0;i<row;i++)
    {delete m[i];}
    delete m;
}
void matrix::input()
{
    for(int i=0;i<row;i++)
    {for(int j=0;j<col;j++)
        {cout<<"m"<<"("<<i+1<<j+1<<")"<<"=";
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
matrix matrix::operator + (matrix &M)
{
        matrix temp(row,col);
        for(int i=0;i<row;i++)
        {for(int j=0;j<col;j++)
        {
        temp.m[i][j]=m[i][j] + M.m[i][j];
        }}
    return temp;
}
 matrix matrix:: operator * (matrix &M)
 {
    matrix temp(row,M.col);
    for(int i=0;i<row;i++)
    {for(int j=0;j<M.col;j++)
    {
        temp.m[i][j]=0;
    }}
    for(int i=0;i<row;i++)
    {for(int j=0;j<M.col;j++)
    {for(int k=0;k<M.row;k++)
    {
     temp.m[i][j]= temp.m[i][j]+ m[i][k]*M.m[k][j];
    }}}
    return temp;
 }



int main()
{
     cout<<"     Program to add and multiply two matrices"<<endl;
    int w,x,y,z;
    int option=6;
    while(option==6)
    {
        cout<<" "<<endl;

        cout<<"Enter the number of rows of the Matrix-1    : ";
        cin>>x;
        cout<<"Enter the number of columns of the Matrix-1 : ";
        cin>>y;
        cout<<" "<<endl;
         matrix m1(x,y);
        cout<<" "<<endl;

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
         matrix m2(w,z);
         cout<<" "<<endl;
        cout<<"Enter the elements of matrix-2 : "<<endl;
        cout<<" "<<endl;
        m2.input();
        cout<<"Matrix-2 : "<<endl;
        cout<<" "<<endl;
        m2.display();
        cout<<" "<<endl;

        if(x==w&&y==z)
        {

        matrix m3(x,y);
        m3=m1+m2;
        cout<<"Matrix-1 + Matrix-2 = Matrix-3 "<<endl;
        cout<<" "<<endl;
        cout<<"Matrix-3 : "<<endl;
        cout<<" "<<endl;
        m3.display();}

        else
        {
            cout<<" "<<endl;
            cout<<" Addition cannot be performed as number of rows and columns are not matching "<<endl;
            cout<<" "<<endl;
        }

        if(y==w)
        {

        matrix m4(x,z);
        m4=m1*m2;
        cout<<"Matrix-1 x Matrix-2 = Matrix-4 "<<endl;
        cout<<" "<<endl;
        cout<<"Matrix-4 : "<<endl;
        cout<<" "<<endl;
        m4.display();

        }
        else
        {
            cout<<" "<<endl;
            cout<<" Multiplication cannot be performed as number of rows and columns are not matching "<<endl;
            cout<<" "<<endl;
        }

          cout<<" "<<endl;
          cout<<"             Would you like to continue ? "<<endl;
          cout<<"Enter 6 to continue or any other number to end the program"<<endl;
          cin>>option;
          cout<<" "<<endl;


}
cout<<"-------- Thank You ---------"<<endl;
    return 0;
}
