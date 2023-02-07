#include <iostream>
#include <cstring>

using namespace std;
int count1=0;
int count2=0;
class item
{
    string name;
    int code;
    int quantity;
    float price;
public:
    item()
     {
        quantity=0;
        price=0;
     }
    void input(string w,int x,float y,int z)
    {
        name=w;
        code=x;
        price=y;
        quantity=z;
    }
    int get_code(void)
    {
        return code;
    }
    void add_item(int);
    void delete_item(int);
    int get_quantity(void)
    {
        return quantity;
    }
    void alter_quantity(int x)
    {
        quantity=x;
    }
    int get_cost(void)
    {
        return price*quantity;
    }
    void display(void)
    {
        cout<<name<<"\t"<<code<<"\t"<<quantity<<"\t"<<price<<endl;
    }
};
void item:: add_item(int x)
{
  quantity=quantity+x;
}
void item:: delete_item(int x)
{
   quantity=quantity-x;
}
string permission()
{
    string check;
    cout<<" "<<endl;
    cout<<"Do you want to continue ?"<<endl;
    cout<<"        yes or no?       "<<endl;
    cin>>check;
    if(check!="yes"&&check!="no")
    {
        cout<<" "<<endl;
        cout<<"------------ Invalid Entry -------------"<<endl;
        cout<<" "<<endl;
        cout<<"Do you want to continue ?"<<endl;
        cout<<"        yes or no?       "<<endl;
        cin>>check;
    }
    return check;
}
int main()
{
    item inventory[50];
    item shopping_list[50];

    int option;
    bool verify=false;

    while(option!=11)
    {
        cout<<"============ INVENTORY =============="<<endl;
        cout<<" "<<endl;
        cout<<"Choose any of the following option to continue"<<endl;
        cout<<"To enter a new product to the inventory   : 1 "<<endl;
        cout<<"To add an item to the stock               : 2 "<<endl;
        cout<<"To purchase an item                       : 3 "<<endl;
        cout<<"To increase the number of items purchased : 4 "<<endl;
        cout<<"To decrease the number of items purchased : 5 "<<endl;
        cout<<"To remove an item from the stock          : 6 "<<endl;
        cout<<"To remove a product from the inventory    : 7 "<<endl;
        cout<<"To return a product                       : 8 "<<endl;
        cout<<"To get the bill of items                  : 9 "<<endl;
        cout<<"To get the list of items                  : 10"<<endl;
        cout<<"To exit from the program                  : 11"<<endl;
        cin>>option;

        if(option==1)
        {
            string name;
            float price;
            int code,quantity;
            cout<<"------------------New Item----------------"<<endl;
            cout<<"Enter the name of the item  : ";
            cin>>name;
            cout<<"Enter the item code         : ";
            cin>>code;
            cout<<"Enter the item price        : ";
            cin>>price;
            cout<<"Enter the number of items   : ";
            cin>>quantity;

            inventory[count1].input(name,code,price,quantity);
            count1=count1+1;
            cout<<" "<<endl;
            cout<<"New item added"<<endl;
            cout<<" "<<endl;

            int sum=0;
           cout<<"----------------- list of items ----------------"<<endl;
           for(int i=0;i<count1;i++)
           {
              sum=sum+inventory[i].get_cost();
           }
           cout<<"NAME"<<"\tCODE"<<"\tNUMBER"<<"\tPRICE"<<endl;
           cout<<"-------------------------------------------------"<<endl;
           for(int i=0;i<count1;i++)
           {
              inventory[i].display();
           }
           cout<<"  "<<endl;
           cout<<"\t\t\tThe total cost = "<<sum<<endl;


            if(permission()=="no")
               {break;}
        }

        else if(option==2)
        {
             int temp1,temp2;
             cout<<"----------------- Adding to stock----------------"<<endl;
             cout<<"Enter the item code       : ";
             cin>>temp1;
             cout<<"Enter the number of items : ";
             cin>>temp2;
             for(int i=0;i<count1;i++)
             {
                 if(temp1==inventory[i].get_code())
                 {
                     inventory[i].add_item(temp2);
                     cout<<" "<<endl;
                     cout<<"Number of items increased"<<endl;
                     cout<<" "<<endl;
                     verify=true;
                 }
             }
             if(verify==false)
             {
                 cout<<" "<<endl;
                 cout<<"------- Invalid Item Code ---------"<<endl;
                 cout<<" "<<endl;
                 verify=false;

             }


             if(permission()=="no")
                {break;}

        }

        else if(option==3)
        {
          while(option==3)
          {

             int temp1,temp2;
             cout<<"----------------- Purchase----------------"<<endl;
             cout<<"Enter the item code       : ";
             cin>>temp1;
             cout<<"Enter the number of items : ";
             cin>>temp2;
             for(int i=0;i<count1;i++)
             {
                 if(temp1==inventory[i].get_code())
                 {

                     if(inventory[i].get_quantity()>=temp2)
                     {
                         shopping_list[count2]=inventory[i];
                         shopping_list[count2].alter_quantity(temp2);
                         inventory[i].delete_item(temp2);
                         count2=count2+1;
                         cout<<" "<<endl;
                         cout<<"Added to the bill"<<endl;
                         cout<<" "<<endl;

                     }
                     else
                     {
                         cout<<" "<<endl;
                         cout<<" The item is out of stock "<<endl;
                         cout<<" "<<endl;
                     }
                      verify=true;
                 }

             }
             if(verify==false)
             {
                 cout<<" "<<endl;
                 cout<<"------- Invalid Item Code ---------"<<endl;
                 cout<<" "<<endl;
                 verify=false;

             }


             int x;

             cout<<" "<<endl;
             cout<<"           Do you want to continue purchase ? "<<endl;
             cout<<"Enter 3 to continue and any other number to display bill"<<endl;
             cin>>x;
             if(x==3)
             {
             option=3;
             }
             else{
                     cout<<"NAME"<<"\tCODE"<<"\tNUMBER"<<"\tPRICE"<<endl;
           cout<<"-------------------------------------------------"<<endl;
           for(int i=0;i<count1;i++)
           {
              inventory[i].display();
           }
           cout<<"  "<<endl;
            if(permission()=="no")
                {break;}
                }

        }break;}

         else if(option==4)
        {
             int temp1,temp2;
             cout<<"----------------- Adding to bill ----------------"<<endl;
             cout<<"Enter the item code       : ";
             cin>>temp1;
             cout<<"Enter the number of items : ";
             cin>>temp2;
             for(int i=0;i<count1;i++)
             {
                 if(temp1==shopping_list[i].get_code())
                 {
                     if(temp1==inventory[i].get_code())
                     {

                         if(inventory[i].get_quantity()>=temp2)
                         {
                             shopping_list[i].add_item(temp2);
                             inventory[i].delete_item(temp2);
                             cout<<" "<<endl;
                             cout<<"Number of items increased"<<endl;
                             cout<<" "<<endl;

                         }
                          else
                         {
                             cout<<" "<<endl;
                             cout<<" The item is out of stock "<<endl;
                             cout<<" "<<endl;
                         }
                         verify=true;
                     }
                 }
             }
             if(verify==false)
             {
                 cout<<" "<<endl;
                 cout<<"------- Invalid Item Code ---------"<<endl;
                 cout<<" "<<endl;
                 verify=false;
             }


             if(permission()=="no")
                {break;}

        }
        else if(option==5)
        {
            int temp1,temp2;
            cout<<"----------------- Removing from bill----------------"<<endl;
            cout<<"Enter the item code       : ";
            cin>>temp1;
            cout<<"Enter the number of items : ";
            cin>>temp2;
            for(int i=0;i<count1;i++)
             {
                 if(temp1==shopping_list[i].get_code())
                 {
                     if(temp1==inventory[i].get_code())
                     {

                         if(inventory[i].get_quantity()>=temp2)
                         {
                             shopping_list[i].delete_item(temp2);
                             inventory[i].add_item(temp2);
                             cout<<" "<<endl;
                             cout<<"Number of items increased"<<endl;
                             cout<<" "<<endl;

                         }
                          else
                         {
                             cout<<" "<<endl;
                             cout<<" The item is out of stock "<<endl;
                             cout<<" "<<endl;
                         }
                         verify=true;
                     }
                 }
             }
            if(verify==false)
            {
                 cout<<" "<<endl;
                 cout<<"------- Invalid Item Code ---------"<<endl;
                 cout<<" "<<endl;
                  verify=false;

            }


            if(permission()=="no")
               {break;}

        }
         else if(option==6)
        {
            int temp1,temp2;
            cout<<"----------------- Removing from stock----------------"<<endl;
            cout<<"Enter the item code       : ";
            cin>>temp1;
            cout<<"Enter the number of items : ";
            cin>>temp2;
            for(int i=0;i<count1;i++)
            {

                if(temp1==inventory[i].get_code())
                {
                    if(inventory[i].get_quantity()>=temp2)
                    {
                        inventory[i].delete_item(temp2);

                    }
                    else
                    {
                     cout<<" "<<endl;
                     cout<<" The item is out of stock "<<endl;
                     cout<<" "<<endl;
                    }
                    verify=true;

                }
             }
            if(verify==false)
            {
                 cout<<" "<<endl;
                 cout<<"------- Invalid Item Code ---------"<<endl;
                 cout<<" "<<endl;
                 verify=false;

            }


            if(permission()=="no")
               {break;}

        }
         else if(option==7)
        {
            int temp;
            cout<<"----------------- Removing from inventory----------------"<<endl;
            cout<<"Enter the item code       : ";
            cin>>temp;
            for(int i=0;i<count1;i++)
            {
                if(temp==inventory[i].get_code())
                {

                        for(int j=i;j<count1;j++)
                        {
                         inventory[j]=inventory[j+1];
                        }
                        verify=true;
                        count1=count1-1;
                }
             }
            if(verify==false)
            {
                 cout<<" "<<endl;
                 cout<<"------- Invalid Item Code ---------"<<endl;
                 cout<<" "<<endl;
                 verify=false;

            }


            if(permission()=="no")
               {break;}

        }
         else if(option==8)
        {
            int temp;
            cout<<"----------------- Returning a product----------------"<<endl;
            cout<<"Enter the item code       : ";
            cin>>temp;
            for(int i=0;i<count2;i++)
            {
                if(temp==shopping_list[i].get_code())
                {

                        for(int j=i;j<count2;j++)
                        {
                         shopping_list[j]=shopping_list[j+1];
                        }
                        verify=true;
                        count2=count2-1;
                }
             }
            if(verify==false)
            {
                 cout<<" "<<endl;
                 cout<<"------- Invalid Item Code ---------"<<endl;
                 cout<<" "<<endl;
                 verify=false;

            }


            if(permission()=="no")
               {break;}

        }
        else if(option==9)
        {
           int sum=0;
           cout<<"----------------- Bill ----------------"<<endl;
           for(int i=0;i<count2;i++)
           {
              sum=sum+shopping_list[i].get_cost();
           }
           cout<<"NAME"<<"\tCODE"<<"\tNUMBER"<<"\tPRICE"<<endl;
           cout<<"-------------------------------------------------"<<endl;
           for(int i=0;i<count2;i++)
           {
              shopping_list[i].display();
           }
           cout<<"  "<<endl;
           cout<<"\t\t\tThe total bill = "<<sum<<endl;
           if(permission()=="no")
              {break;}
        }
        else if(option==10)
        {
           int sum=0;
           cout<<"----------------- list of items ----------------"<<endl;
           for(int i=0;i<count1;i++)
           {
              sum=sum+inventory[i].get_cost();
           }
           cout<<"NAME"<<"\tCODE"<<"\tNUMBER"<<"\tPRICE"<<endl;
           cout<<"-------------------------------------------------"<<endl;
           for(int i=0;i<count1;i++)
           {
              inventory[i].display();
           }
           cout<<"  "<<endl;
           cout<<"\t\t\tThe total cost = "<<sum<<endl;
           if(permission()=="no")
              {break;}
        }
        else if(option==11)
        {
            break;
        }
        else
        {
            cout<<"  "<<endl;
            cout<<"-------------- Invalid Entry -------------"<<endl;
            cout<<"  "<<endl;
        }


}cout<<"-------------- Thank You -------------"<<endl;
return 0;}
