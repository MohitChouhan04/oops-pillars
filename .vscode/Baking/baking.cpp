#include<iostream>
#include<vector>
using namespace std;
class depositonlyaccount{
    public:
    // abstract class
    virtual void deposit(double amount) =0; //pure virtual function
};
class withdrawableaccount : public depositonlyaccount{
    public:
    // abstract class
    virtual void withdraw(double amount) = 0; //pure virtual function
};
class savingaccount : public withdrawableaccount{
    private:
    double balance;

    public: 
    //constructor
    savingaccount(){
        balance =0;
    }
    void deposit (double amount) override{
        balance += amount;
        cout<<"Deposited: " << amount <<"in saving account. new balance: "<< balance <<endl;

    }
    void withdraw(double amount) override{
        if(balance >= amount){
            balance -= amount;
            cout<<"withdrawn: " << amount <<"form saving account. new balance"<<balance<<endl;

        }
        else{
            cout<<"insufficient funds in saving account \n";
        }
    }


};
class currentaccount : public withdrawableaccount{
    private:
    double balance;
    public:
    currentaccount(){
        balance = 0;

    }
    void deposit(double amount) override{
        balance += amount;
        cout<<"Deposited: "<<amount<<" in current account.new balance: "<<balance<<endl;

    }
    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout<<"withdrawn: " << amount << "from current account. new balance: "<<balance<<endl;

        }
        else{
            cout<<"insufficent funds in current account!\n";
        }
    }

};
class fixedtermaccount : public depositonlyaccount{
    private:
    double balance;
    public:
    fixedtermaccount(){
        balance=0;
    }
    void deposit(double amount) override {
        balance += amount;
        cout<<"Deposite: " << amount <<"in fixed term account. new balance: "<<balance<<endl;

    }
};
class bankclient{
    private:
    vector<withdrawableaccount*>withdrawableaccounts;
    vector<depositonlyaccount*>depositonlyaccounts;
    public:
    bankclient(vector<withdrawableaccount*> withdrawableaccounts,vector<depositonlyaccount*>depositonlyaccounts){
        this->withdrawableaccounts = withdrawableaccounts;
        this->depositonlyaccounts = depositonlyaccounts;


    }
    void processtransaction(){
        for(withdrawableaccount* acc : withdrawableaccounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for(depositonlyaccount* acc : depositonlyaccounts){
            acc->deposit(5000);
        }
     
    }
};

int main(){
    vector<withdrawableaccount*>withdrawableaccounts;
    withdrawableaccounts.push_back(new savingaccount());
    withdrawableaccounts.push_back(new currentaccount());
    vector<depositonlyaccount*>depositonlyaccounts;
    depositonlyaccounts.push_back(new fixedtermaccount());

    bankclient* client = new bankclient (withdrawableaccounts , depositonlyaccounts);
    client->processtransaction();
    return 0;

}
