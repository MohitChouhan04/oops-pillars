#include<iostream>
using namespace std;
class Animal{
    public:


};
class Dog : public Animal{

};

class parent{
    public:
    virtual Animal* getAnimal(){
        cout<<"parent: returning animal instance "<<endl;
        return new Animal();
    }
};
class child : public parent{
    public:
    Animal* getAnimal() override{
        cout<<"child : return dog instance"<<endl;
        return new Dog();
    }
};

class Client{
    private:
    parent* p;
    public:
    Client(parent* p){
        this->p = p;

    }
    void takeAnimal(){
        p->getAnimal();
    }

};
int main(){
    parent* Parent = new parent();
    child* Child = new child();
    Client* client = new Client(Child);
    client->takeAnimal();
    return 0;





}