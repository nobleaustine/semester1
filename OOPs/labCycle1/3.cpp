
#include <iostream>
#include <string>
using namespace std;
int cnt=0;
string n="  ";

class ACCOUNT
{
    string cust_name,acc_type;
    int acc_no;
    int balance;
public:
    string check_type();
    void account();
    void withdraw();
    void deposit();
    void bal_enquiry();
    void acc_state();
};
string ACCOUNT:: check_type()
{return acc_type;}

void ACCOUNT::account()
{
    string n1,n2;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    cout<<"Enter your first name  : ";
    cin>>n1;
    cout<<"Enter your second name : ";
    cin>>n2;
    cust_name=n1+n+n2;
    cout<<n<<endl;
    cout<<"You can have two types of accounts : "<<endl;
    cout<<n<<endl;
    cout<<"You can have a fixed type account where you can not deposit or withdraw money for five years."<<endl;
    cout<<"You can also have unfixed type account where you can deposit or withdraw money at your will."<<endl;
    cout<<n<<endl;
    cout<<"To have a fixed type of account enter : fixed"<<endl;
    cout<<"To have a loose type of account enter : unfixed"<<endl;
    cout<<n<<endl;
    cout<<"Enter your account type : ";
    cin>>acc_type;
    acc_no=cnt;
    while(acc_type!="fixed"&&acc_type!="unfixed")
    {
      cout<<n<<endl;
      cout<<"-------- Invalid Account Type --------"<<endl;
      cout<<n<<endl;
      cout<<"Enter your account type : ";
      cin>>acc_type;
    }
    cout<<n<<endl;
    cout<<"Enter an initial deposit(deposit>=500) : ";
    cin>>balance;
    while(balance<500)
    {
        cout<<n<<endl;
        cout<<"------------ Invalid Amount -----------"<<endl;
        cout<<n<<endl;
        cout<<"Enter an initial deposit(deposit>=500) : ";
        cin>>balance;
    }

    cout<<"----------------------------------------------------------------------------------------------"<<endl;
}
void ACCOUNT::deposit()
{
  int dep;
  cout<<"---------------------------------------"<<endl;
  cout<<"Enter the amount to be deposited : ";
  cin>>dep;
  balance=balance+dep;
  cout<<n<<endl;
  cout<<"Your current balance = "<<balance<<endl;
  cout<<n<<endl;
  cout<<"---------------------------------------"<<endl;
}
 void ACCOUNT::withdraw()
{
  int draw;
  cout<<"---------------------------------------"<<endl;
  cout<<"Enter the amount to be withdrawn : ";
  cin>>draw;
  if(balance-draw>=500)
  {balance=balance-draw;}
  else
  {
      while(balance-draw<500)
      {
      cout<<n<<endl;
      cout<<"------ Insufficient Balance ------"<<endl;
      cout<<n<<endl;
      cout<<"Enter the amount to be withdrawn : ";
      cin>>draw;}
  }
  balance=balance-draw;
  cout<<n<<endl;
  cout<<"Your current balance = "<<balance<<endl;
  cout<<n<<endl;
  cout<<"--------------------------------------"<<endl;}
 void ACCOUNT:: bal_enquiry()
{
     cout<<"--------------------------------"<<endl;
     cout<<"Your current balance = "<<balance<<endl;
     cout<<"--------------------------------"<<endl;
 }
 void ACCOUNT::acc_state()
{
     cout<<"---------------------------------------"<<endl;
     cout<<"Name         : "<<cust_name<<endl;
     cout<<"Account no   : "<<acc_no+666<<endl;
     cout<<"Account type : "<<acc_type<<endl;
     cout<<"Balance      : "<<balance<<endl;
     cout<<"---------------------------------------"<<endl;
}
string continue_not()
{
    string option;
    cout<<"------------------------------------"<<endl;
    cout<<n<<endl;
    cout<<"Would you like to continue banking ?"<<endl;
    cout<<"           yes or no?               "<<endl;
    cin>>option;
    cout<<n<<endl;
    while(option!="yes" && option!="no")
    {
    cout<<"---------- Invalid Entry -----------"<<endl;
    cout<<n<<endl;
    cout<<"Would you like to continue banking ?"<<endl;
    cout<<"            yes or no?              "<<endl;
    cin>>option;
    cout<<n<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<<n<<endl;
    return option;
}
int get_num()
{
    int x;
    cout<<"------------------------------------"<<endl;
    cout<<"Enter your account number : ";
    cin>>x;
    while(x<666)
    {
    cout<<n<<endl;
    cout<<"---------- Invalid Account Number -----------"<<endl;
    cout<<n<<endl;
    cout<<"Enter your account number :";
    cin>>x;
    }
    while(x-666>cnt)
    {
    cout<<n<<endl;
    cout<<"---------- Invalid Account Number -----------"<<endl;
    cout<<n<<endl;
    cout<<"Enter your account number :";
    cin>>x;
    }
    cout<<"------------------------------------ "<<endl;
    return x-666;}

int main()
{
    string t="************************* THANK YOU ***********************************";
    string f="Your account type is fixed type you cannot deposit or withdraw cash";
    string choose;
    ACCOUNT account_list[100];
    cout<<"*************  Welcome to XYZ bank online portal  *****************"<<endl;
    while(choose!="end")
    {   cout<<n<<endl;
        cout<<"Enter the following option to continue :"<<endl;
        cout<<n<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"To create new account               : new"<<endl;
        cout<<"To deposit money to your account    : deposit"<<endl;
        cout<<"To withdraw money from your account : withdraw"<<endl;
        cout<<"To check your balance               : balance"<<endl;
        cout<<"To get your account statement       : statement"<<endl;
        cout<<"To end your banking                 : end"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<n<<endl;
        cin>>choose;
        if(choose=="new")
        {
          account_list[cnt].account();
          cout<<"--------------------------------------------------------------------------------"<<endl;
          cout<<n<<endl;
          cout<<"Your account number is "<<cnt+666<<" save it for future access into your account"<<endl;
          cout<<n<<endl;
          cout<<"--------------------------------------------------------------------------------"<<endl;
          cnt=cnt+1;
          if(continue_not()=="no")
           {cout<<t<<endl;
           break;}
        }
        else if(choose=="deposit")
        {
         int temp1=get_num();
         string temp2=account_list[temp1].check_type();
        if(temp2=="unfixed")
           {account_list[temp1].deposit();
            if(continue_not()=="no")
             {cout<<t<<endl;
             break;}
           }
        else
           {cout<<f<<endl;
            if(continue_not()=="no")
             {cout<<t<<endl;
             break;}
           }
        }
        else if(choose=="withdraw")
        {
        int temp1=get_num();
        string temp2=account_list[temp1].check_type();
        if(temp2=="unfixed")
           {account_list[temp1].withdraw();
            if(continue_not()=="no")
             {cout<<t<<endl;
             break;}
           }
        else
           {cout<<f<<endl;
            if(continue_not()=="no")
             {cout<<t<<endl;
             break;}
           }
        }
        else if (choose=="balance")
        {
        account_list[get_num()].bal_enquiry();
        if(continue_not()=="no")
          {cout<<t<<endl;
          break;}
        }
        else if (choose=="statement")
        {
        int temp=get_num();
        account_list[temp].acc_state();
        if(continue_not()=="no")
          {cout<<t<<endl;
          break;}
        }
        else if(choose=="end")
        {
        cout<<t<<endl;
        break;}
        else
        {
         cout<<"----------- Invalid Entry ------------"<<endl;
        }

















    }
return 0;}




