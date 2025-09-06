#include<iostream>
using namespace std;
class burger{
    public:
    virtual void prepare() = 0;
    ~burger() {}
};
class basicburger : public burger{
    public:
    void prepare() override{
        cout<<"preparing basic burger with bun, patty and ketchup"<<endl;

    }
};
class standardburger : public burger{
    public:
    void prepare() override{
        cout<<"preparing standard burger with bun, patty , cheese and lettuce!"<<endl;

    }
};
class premiumburger : public burger{
    public:
    void prepare() override{
        cout<<"preparing premium bruger with gourmet bun, premium patty,cheese, lettuce , and sauce!"<<endl;

    }
};

class burgerfactory{
    public:
    burger* createburger(string& type){
        if(type == "basic"){
            return new basicburger();
        }
        else if(type == "standard"){
            return new standardburger();
        }
        else if(type == "premium"){
            return new premiumburger();
        }
        else{
            cout<<"invalid burger type!" <<endl;
            return nullptr;
        }
    }
};
int main(){
    string type = "standard";
    burgerfactory* myburgerfactory = new burgerfactory();

    burger* Burger = myburgerfactory->createburger(type);
    Burger->prepare();

}