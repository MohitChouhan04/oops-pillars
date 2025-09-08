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
class basicwheatburger : public burger{
    public:
    void prepare() override{
        cout<<"preparing basic wheat burger with bun, patty, and ketchup"<<endl;
    }
};
class standardwheatburger : public burger{
    public:
    void prepare() override {
         cout<<"preparing standard wheat burger with bun, patty,cheese and lettuce!"<<endl;
    }
};
class premiumwheatburger : public burger{
    public:
    void prepare()  override{
        cout<<"preparing premium burger with gourmet bun,premium patty, cheese, lettuce, and secret sauce!"<<endl;

    }
};

class burgerfactory{
    public:
    virtual burger* createburger(string& type) = 0;

};
class singhburger : public burgerfactory{
    public:
     burger* createburger(string& type) override{
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
class kingburger : public burgerfactory{
    public:
     burger* createburger(string& type) override{
        if(type == "basic"){
            return new basicwheatburger();
        }
        else if(type == "standard"){
            return new standardwheatburger();
        }
        else if(type == "premium"){
            return new premiumwheatburger();
        }
        else{
            cout<<"invalid burger type!" <<endl;
            return nullptr;
        }
    }
};
int main(){
    string type = "standard";
    burgerfactory* myfactory = new kingburger();

    burger* Burger = myfactory->createburger(type);
    Burger->prepare();

}