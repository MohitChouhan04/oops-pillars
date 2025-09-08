// #include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

class shopping{
    private:
    int pcode;
    float price;
    float discount;
    string productName;

    public:
    void menu();
    void administration();
    void buyer();
    void add();
    void edit();
    void remove();
    void list();
    void  recepit();
};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t__________________________\n";
    cout<<"\t\t\t\t                          \n";
    cout<<"\t\t\t\t  supermarket Main Menu   \n";
    cout<<"\t\t\t\t                          \n";
    cout<<"\t\t\t\t__________________________\n";
    cout<<"\t\t\t\t                          \n";
    cout<<"\t\t\t\t|   1) Administrator |\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t|   2) Buyer         |\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t|   3) Exit          |\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\n\t\t\t Please select";
    cin>>choice;
    switch(choice)
    {
        case 1:
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Email  \n";
        cin>>email;
        cout<<"\t\t\t Enter Passoword  \n";
        cin>>password;
        if(email=="m3301040@gmail.com" && password=="mohit@123"){
            administration();
    
        }
        else{
            cout<<"invalid username and password";
        }
        break;

        case 2:
        {
            buyer();

        }

        case 3:
        {
            exit(0);  // sucessfully termination of program
        }
        default:
        {
            cout<<"please select from the given options";
        }
    }
goto m;
}

void shopping :: administration()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administator menu";
    cout<<"\n\t\t\t|_____1) Add the Product______|";
    cout<<"\n\t\t\t|                             |";
    cout<<"\n\t\t\t|_____2) Modify the Product___|";
    cout<<"\n\t\t\t|                             |";
    cout<<"\n\t\t\t|_____3) Delete the Product___|";
    cout<<"\n\t\t\t|                             |";
    cout<<"\n\t\t\t|_____4) Back to main menu____|";
    cout<<"\n\n\t Please Enter your choice";
    cin>>choice;

    switch(choice){
        
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            remove();
        }
        case 4:
        {
            menu();
        }
        default:{
            cout<<"invalid choice";
        }
    }
    goto m;
}