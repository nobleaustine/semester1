#include <iostream>
#include <cstring>
using namespace std ;

class STRING
{
    char* str;
    int length;
public:
    STRING()
    {
    length=0;
    str=new char[length+1];
    }
    STRING(const char*s)
    {
     length=strlen(s);
     str=new char[length+1];
     strcpy(str,s);
    }
    void display(){cout<<str;}
	friend STRING concatenate(STRING s1,STRING s2);
	friend void compare(STRING s1,STRING s2);
};
 STRING concatenate(STRING s1,STRING s2)
{
	    STRING s;
	    s.length=s1.length + s2.length;
	    s.str= new char[s.length +1];
	    strcpy(s.str,s1.str);
	    strcat(s.str,s2.str);
	    return s;
}
 void compare(STRING s1,STRING s2)
 {
	    if(s1.length>s2.length)
        {
         cout<<s1.str<<" has more number of characters "<<endl;
        }
        else if (s1.length<s2.length)
        {
         cout<<s2.str<<" has more number of characters "<<endl;
        }
	    else
        {
            cout<<" Both have same number of characters "<<endl;
        }
	}

int main()
{int option =6;

    cout<<" Program to compare and concatenate strings "<<endl;
    cout<<" "<<endl;

    char* temp1 = new char[50];
    char* temp2 = new char [50];

  while(option==6)
    {
    cout<<" Enter the first string  : ";
    cin>>temp1;
    STRING s1(temp1);
    cout<<" "<<endl;

    cout<<" Enter the second string : ";
    cin>>temp2;
    STRING s2(temp2);

    STRING s3=concatenate(s1,s2);
    cout<<"  "<<endl;
    cout<<" ";s1.display();cout<<" + ";s2.display();cout<<" = ";s3.display();cout<<" "<<endl;
    cout<<"  "<<endl;
    compare(s1,s2);
    cout<<" "<<endl;
    cout<<"              Would you like to continue ? "<<endl;
    cout<<"Enter 6 to continue or any other digit to exit the program"<<endl;
    cin>>option;
     }
    cout<<"************* thank you ****************"<<endl;

return 0;

}


