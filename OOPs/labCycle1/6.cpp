#include <iostream>

using namespace std;
class TIME
{
    int hours,minutes,seconds;
public:
    void input();
    void add(TIME,TIME);
    void display();
};
void TIME::input()
{
    cout<<"Enter hours = ";
    cin>>hours;
    cout<<"Enter minutes = ";
    cin>>minutes;
    cout<<"Enter seconds = ";
    cin>>seconds;
}
void TIME::add(TIME t1,TIME t2)
{
  seconds=t1.seconds+t2.seconds;
  minutes=seconds/60;
  seconds=seconds%60;
  minutes=minutes+t1.minutes+t2.minutes;
  hours=minutes/60;
  minutes=minutes%60;
  hours=hours+t1.hours+t2.hours;
}
void TIME::display()
{
    cout<<hours<<" hours, "<<minutes<<" minutes and "<<seconds<<" seconds "<<endl;
}

int main()
{
    string choice="yes";
    cout<<"              Program to add two time periods "<<endl;
    cout<<"            ___________________________________"<<endl;
    TIME time1,time2,time3;
    while(choice=="yes")
    {
    cout<<"   "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"        Enter 1st time period :"<<endl;;
    cout<<"   "<<endl;
    time1.input();
    cout<<"--------------------------------------"<<endl;
    cout<<"        Enter 2nd time period :"<<endl;
    cout<<"   "<<endl;
    time2.input();
    time3.add(time1,time2);
    cout<<"   "<<endl;
    cout<<"Sum of 1st and 2nd time period : "<<endl;
    cout<<"   "<<endl;
    time3.display();
    cout<<"   "<<endl;
    cout<<"Do you want to continue?"<<endl;
    cout<<"       yes or no        "<<endl;
    cin>>choice;
    cout<<"   "<<endl;
    }
    while(choice!="yes"&&choice!="no")
    {
    cout<<"------------- Invalid Entry -------------"<<endl;
    cout<<"   "<<endl;
    cout<<"Do you want to continue?"<<endl;
    cout<<"       yes or no        "<<endl;
    cin>>choice;
    }
    cout<<"*************** Thank You ****************"<<endl;

    return 0;
}
