#include <iostream>
using namespace std;

class student
{
protected:
    int roll_number;
public:
    void input_roll(int x)
    {
        roll_number=x;
    }
    void display_roll(void)
    {
        cout<<"Roll Number : "<<roll_number<<endl;
    }

};
class test : virtual public student
{
protected:
    float oop,ct4ps,maths;
public:
    void get_marks(float x,float y,float z)
    {
        oop=x;
        ct4ps=y;
        maths=z;
    }
    void display_marks(void)
    {
        cout<<"  SUBJECT REPORT "<<endl;
        cout<<"Marks of oop     : "<<oop<<endl;
        cout<<"Marks of ct4ps   : "<<ct4ps<<endl;
        cout<<"Marks of maths   : "<<maths<<endl;
    }
};
class sports: virtual public student
{
protected:
     float football;
     float batminton;
public:
    void get_grade(float x,float y)
    {
        football=x;
        batminton=y;
    }
    void display_grade(void)
    {
        cout<<"      SPORTS REPORT"<<endl;
        cout<<"Score of football match  : "<<football<<endl;
        cout<<"Score of batminton match : "<<batminton<<endl;
    }
};

class result : public test,public sports
{
    float average;
public:
    void display(void)
    {
        average= (oop+ct4ps+maths+football+batminton)/5;
        cout<<"  TOTAL REPORT "<<endl;
        cout<<"Average score : "<<average;
    }

};



int main()
{
    result stu1;
    stu1.input_roll(10);
    stu1.get_marks(80,75,85);
    stu1.get_grade(75,70);
    cout<<"------ Student Report Card ------"<<endl;
    cout<<" "<<endl;
    stu1.display_roll();
    cout<<" "<<endl;
    stu1.display_marks();
    cout<<" "<<endl;
    stu1.display_grade();
    cout<<" "<<endl;
    stu1.display();
      cout<<" "<<endl;

}

