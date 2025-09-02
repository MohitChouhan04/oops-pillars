#include<iostream>
#include<string>
using namespace std;
class parent{
    public:
    virtual void print(string msg){
        cout<<"parent: " << msg<<endl;
    }
    virtual ~parent() {}
};
class Child : public parent{
    public:
    void print(string msg) override{
        cout<<"child: "<<msg <<endl;
    }

};
class client{
    private:
    parent* p;
    public:
    client(parent* p){
        this->p=p;

    }
    void printmsg(){
        p->print("hello");
    }
};
int main(){
    parent* p1 = new parent();
    parent* p2 = new Child();

    client* c1 = new client(p2);
    c1->printmsg();



}