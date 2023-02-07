#include <iostream>

using namespace std;
class MATRIX
{
    int row,col;
    int**m;
public:
    MATRIX(int,int);
    ~MATRIX();
    void input(void);
    void display(void);
    void matrix_add(MATRIX &,MATRIX &);
    void matrix_mul(MATRIX &,MATRIX &);
    void matrix_transpose(MATRIX &);
    int matrix_trace(void);

};
MATRIX::MATRIX(int x,int y)
{
    row=x;
    col=y;
    m=new int*[row];
    for(int i=0;i<row;i++)
    {m[i]=new int[col];}
}
MATRIX::~MATRIX()
{
    for(int i=0;i<row;i++)
    {delete m[i];}
    delete m;
}
void MATRIX::input()
{
    cout<<" "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<"m("<<i+1<<j+1<<")"<<"=";
            cin>>m[i][j];
        }
        cout<<" "<<endl;
    }

}
void MATRIX::display()
{
    cout<<" "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<" "<<endl;
        cout<<" "<<endl;
    }
}
void MATRIX::matrix_add(MATRIX &M1,MATRIX &M2)
{
     for(int i=0;i<row;i++)
     {
         for(int j=0;j<col;j++)
        {m[i][j]=M1.m[i][j] + M2.m[i][j];}
     }

}
void MATRIX::matrix_mul(MATRIX &M1,MATRIX &M2)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            m[i][j]=0;
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            for(int k=0;k<M1.col;k++)
            {
                m[i][j]= m[i][j]+ M1.m[i][k]*M2.m[k][j];
            }
        }
    }

}
void MATRIX::matrix_transpose(MATRIX &M)
{
   for(int i=0;i<row;i++)
   {
       for(int j=0;j<col;j++)
       {
           m[i][j]=M.m[j][i];
       }
   }
}
int MATRIX::matrix_trace(void)
{
   int sum=0;
   for(int i=0;i<row;i++)
   {
       for(int j=0;j<col;j++)
       {
           if(i==j)
           {
             sum=sum+m[i][j];
           }

       }
   }
   return sum;
}

int main()
{
    int x,y,w,z;
    int check =6;
    cout<<"------------ MATRIX CALCULATION PROGRAM ----------------"<<endl;
    cout<<" "<<endl;
 while(check==6)
 {

            cout<<"Enter the number of rows of the Matrix-1    : ";
            cin>>x;
            cout<<"Enter the number of columns of the Matrix-1 : ";
            cin>>y;
            cout<<" "<<endl;

            cout<<"Enter the number of rows of the Matrix-2    : ";
            cin>>w;
            cout<<"Enter the number of columns of the Matrix-2 : ";
            cin>>z;

             MATRIX m1(x,y);
             MATRIX m2(w,z);

            cout<<" "<<endl;
            cout<<"Enter the elements of Matrix-1 : "<<endl;
            m1.input();
            cout<<"Matrix-1 :"<<endl;
            m1.display();

            cout<<"Enter the elements of Matrix-2 : "<<endl;
            m2.input();
            cout<<"Matrix-2 : "<<endl;
            m2.display();

            if(x==w&&y==z)
            {


            MATRIX m3(x,y);
            m3.matrix_add(m1,m2);
            cout<<" "<<endl;
            cout<<"Matrix-1 + Matrix-2 = Matrix-3 "<<endl;
            cout<<" "<<endl;
            cout<<"Matrix-3 : "<<endl;
            m3.display();
            }

            else
            {
            cout<<" "<<endl;
            cout<<"The given two matrices cannot be added"<<endl;
            cout<<" "<<endl;
            }

            if(y!=w)
            {
            cout<<" "<<endl;
            cout<<"The given two matrices cannot be multiplied"<<endl;
            cout<<" "<<endl;
            }
            else
            {
            MATRIX m4(x,z);
            m4.matrix_mul(m1,m2);
            cout<<"Matrix-1 x Matrix-2 = Matrix-4 "<<endl;
            cout<<" "<<endl;
            cout<<"Matrix-4 : "<<endl;
            m4.display();
            }



            MATRIX m5(y,x);
            m5.matrix_transpose(m1);
            cout<<"Transpose of Matrix-1 :"<<endl;
            m5.display();
            MATRIX m6(z,w);
            m6.matrix_transpose(m2);
            cout<<"Transpose of Matrix-2 :"<<endl;
            m6.display();




            if(x!=y)
            {
                cout<<" "<<endl;
                cout<<" Matrix-1 is not a square matrix hence trace cannot be determined "<<endl;
                cout<<" "<<endl;
            }
            else
            {
                cout<<" "<<endl;
                cout<<"The trace of the Matrix-1 = "<<m1.matrix_trace()<<endl;
                cout<<" "<<endl;
            }
            if(w!=z)
            {
                cout<<" "<<endl;
                cout<<" Matrix-2 is not a square matrix hence trace cannot be determined "<<endl;
                cout<<" "<<endl;
            }
            else
            {
                cout<<" "<<endl;
                cout<<"The trace of the Matrix-2 = "<<m2.matrix_trace()<<endl;
                cout<<" "<<endl;
            }

          cout<<" "<<endl;
          cout<<"             Would you like to continue ? "<<endl;
          cout<<"Enter 6 to continue or any other number to end the program"<<endl;
          cin>>check;
          cout<<" "<<endl;

    }
    cout<<"------------ Thank You----------------"<<endl;
    return 0;
}
