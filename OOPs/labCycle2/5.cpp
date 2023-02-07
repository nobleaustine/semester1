#include <iostream>
using namespace std;

class passion
{
protected:
    string pass;
public:
    void get_pass(string s)
    {
        pass=s;
    }
    void show_pass(void)
    {
        cout<<"Passion : "<<pass<<endl;
    }
};
class job
{
protected:
    string j_name;
    int salary;
public:
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
};

class person:public teacher
{
    string name;
    int age;
public:
     void get(string s,int x)
    {
        name=s;
        age=x;
    }
     void show(void)

    {
       cout<<"Name    : "<<name<<endl;
       cout<<"Age     : "<<age<<endl;
    }

};

int main()
{
    person p1;
    p1.get("Alex",24);
    p1.get_pass("Teaching");
    p1.get_sub("English");
    p1.get_salary("Teacher",30000);
    cout<<"--- Bio Data ---"<<endl;
    p1.show();
    p1.show_pass();
    p1.show_salary();
    p1.show_sub();

return 0;}

