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

class garlicbread{
    public:
    virtual void prepare() = 0;

};
class basicgarlicbread : public garlicbread{
    public:
    void prepare() override{
        cout<<"preparing basic garlic bread with butter and garlic \n";
    }
};
class chessgralicbread : public garlicbread{
    public:
    void prepare() override{
        cout<<"preparing chess garlic bread with extra cheese and butter \n";
    }
};
class chesswheatgarlicbread : public garlicbread {
    public:
    void prepare() override{
        cout<<"preparing cheese wheat garlic bread with extra cheese and butter!\n";
    }

};
class mealfactory{
    public:
    virtual burger* createburger(string& type) = 0;
    virtual garlicbread* creategarlicbread(string& type) = 0;
 };
class singhburger : public mealfactory{
    
}
int main(){
    string type = "standard";
    burgerfactory* myburgerfactory = new burgerfactory();

    burger* Burger = myburgerfactory->createburger(type);
    Burger->prepare();

}