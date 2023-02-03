#include <iostream>
using namespace std;

class student

{
  string name,grade;
  int roll_no;
  double m_oop,m_ct4ps,m_maths,avg;



   public:
       void input();
       string calc_grade();
       void display();
};
void student::input()
{

           cout<<"Enter the name of the student                 :";
           cin>>name;
           cout<<"Enter the roll no. of the student             :";
           cin>>roll_no;
           cout<<"Enter the marks obtained in oop out of 100    :";
           cin>>m_oop;
           while(m_oop>100||m_oop<0)
           {
           cout<<"  "<<endl;
           cout<<"----------------Invalid entry------------------"<<endl;
           cout<<"  "<<endl;
           cout<<"Enter the marks obtained in oop out of 100    :";
           cin>>m_oop;
           }
           cout<<"Enter the marks obtained in ct4ps out of 100  :";
           cin>>m_ct4ps;
           while(m_ct4ps>100||m_ct4ps<0)
           {
           cout<<"  "<<endl;
           cout<<"----------------Invalid entry------------------"<<endl;
           cout<<"  "<<endl;
           cout<<"Enter the marks obtained in ct4ps out of 100  :";
           cin>>m_ct4ps;
           }
           cout<<"Enter the marks obtained in maths out of 100  :";
           cin>>m_maths;
           while(m_maths>100||m_maths<0)
           {
           cout<<"  "<<endl;
           cout<<"------------------Invalid entry-------------------"<<endl;
           cout<<"  "<<endl;
           cout<<"Enter the marks obtained in maths out of 100    :";
           cin>>m_maths;
           }
}

string student::calc_grade()
{
    avg = (m_oop + m_ct4ps + m_maths)/3;

 if (100>=avg&&avg>95)
 {
     grade="A+";
 }
 else if(95>=avg&&avg>90)
 {
     grade="A";
 }
 else if(90>=avg&&avg>85)
 {
     grade="B+";
 }
 else if(85>=avg&&avg>80)
 {
     grade="B";
 }
 else if(80>=avg&&avg>75)
 {
     grade="C+";
 }
 else if(75>=avg&&avg>70)
 {
     grade="C";
 }
 else if(70>=avg&&avg>65)
 {
     grade="D+";
 }
 else if(65>=avg&&avg>60)
 {
     grade="D";
 }
 else if(60>=avg&&avg>55)
 {
     grade="E+";
 }
 else if(55>=avg&&avg>=50)
 {
     grade="F";
 }
 else
 {
     grade="FAIL";
 }
return grade;
  }
void student ::display()
{
    cout<<name<<"\t"<<roll_no<<"\t"<<m_oop<<"\t"<<m_ct4ps<<"\t"<<m_maths<<"\t"<<avg<<"\t\t"<<grade<<endl;



}
int main()
{
  int n;
  cout<<"                     Program to print mark list of n students "<<endl;
  cout<<"                  _____________________________________________"<<endl;
  cout<<" "<<endl;
  cout<<"Enter the number of students : ";
  cin>>n;
  student* mark_list;
  mark_list= new student[n];

for(int i=0;i<n;i++)
{
        cout<<"____________________________________________________________"<<endl;
        cout<<" "<<endl;
        mark_list[i];
        mark_list[i].input();
        mark_list[i].calc_grade();
        cout<<"____________________________________________________________ "<<endl;
        }

cout<<"                   MARK LIST"<<endl;
cout<<"                  ___________"<<endl;
cout<<"NAME ROLL NO.\tOOP\tCT4PS\tMATHS\tAVERAGE\t\tGRADE"<<endl;
cout<<"-----------------------------------------------------------------"<<endl;
for(int j=0;j<n;j++)
{
    mark_list[j].calc_grade();
    mark_list[j].display();
cout<<"------------------------------------------------------------------"<<endl;
}




            return 0;
        }
