#include<iostream>
using namespace std;
class parent {
    public:
    virtual void getvalue() noexcept(false){
        throw logic_error("parent error");
    }
};
class Child : public parent{
    public:
    void getvalue() noexcept(false) override{
        throw out_of_range("child error");
    }
};
class Client {
    private:
    parent* p;
    public:
    Client(parent* p){
        this->p =p;
    }
    void takevalue(){
        try{
            p->getvalue();
        }
        catch(const logic_error& e){
            cout<<"logic error exception occured: "<<e.what() <<endl;
        }
    }
};
int main(){
    parent* Parent = new parent();
    Child* child = new Child();

    Client* client = new Client(Parent);
    client->takevalue();
}