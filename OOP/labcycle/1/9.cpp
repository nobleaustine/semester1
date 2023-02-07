#include <iostream>
using namespace std;

class gen
{
    int no_members;
    static int cnt;
public:
    gen(int x)
    {   no_members=x;
        cnt=cnt+1;
    }
    void display(void)
    {
        cout<<"Number of members : "<<no_members<<endl;
    }
    static void showcount(void)
    {
        cout<<"    Generation :-"<<cnt<<endl;
        cout<<"    -------------- "<<endl;
    }

};
int gen::cnt;
int main()
{
    int x;
    int option=6;
    while(option==6)
    {
    cout<<"Program to show the members in each generation "<<endl;
    cout<<" "<<endl;
    cout<<"Enter the number of members in your grandmother's generation : ";
    cin>>x;
    gen g1(x);
    cout<<" "<<endl;
    gen::showcount();
    cout<<" "<<endl;
    g1.display();
    cout<<" "<<endl;
    cout<<"Enter the number of members in your mother's generation      : ";
    cin>>x;
    gen g2(x);
    cout<<" "<<endl;
    gen::showcount();
    cout<<" "<<endl;
    g2.display();
    cout<<" "<<endl;
    cout<<"Enter the number of members in your generation               : ";
    cin>>x;
    gen g3(x);
    cout<<" "<<endl;
    gen::showcount();
    cout<<" "<<endl;
    g3.display();
    cout<<" "<<endl;

    cout<<"             Would you like to continue ? "<<endl;
    cout<<"Enter 6 to continue or any other number to end the program"<<endl;
    cin>>option;
    cout<<" "<<endl;
    }
    cout<<"---------- Thank You -----------"<<endl;
return 0;}

