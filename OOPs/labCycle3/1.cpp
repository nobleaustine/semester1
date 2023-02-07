#include <iostream>
using namespace std;

class passion
{
protected:
    string pass;
public:
    virtual void get_pass(string)=0;
    virtual void show_pass(void)=0;
};
class job
{
protected:
    int salary;
    string j_name;
public:
   virtual void get_salary(string,int)=0;
   virtual void show_salary(void)=0;
};
class teacher:public job,public passion
{
protected:
    string subject;
public:
    void get_sub(string s)
    {
        subject=s;
    }
    void show_sub(void)
    {
       cout<<"Subject : "<<subject<<endl;
    }
    void get_pass(string s)
    {
        pass=s;
    }
    void show_pass(void)
    {
        cout<<"Passion : "<<pass<<endl;
    }
    void get_salary(string y,int x)
    {
        salary=x;
        j_name=y;
    }
   void show_salary(void)
    {
       cout<<"Job     : "<<j_name<<endl;
       cout<<"Salary  : "<<salary<<endl;
    }


};
int main()
{
    teacher t1;
    cout<<"------ BIO DATA --------"<<endl;
    t1.get_salary("Teacher",30000);
    t1.get_pass("Teaching");
    t1.get_sub("English");
    t1.show_salary();
    t1.show_pass();
    t1.show_sub();







   return 0;}
