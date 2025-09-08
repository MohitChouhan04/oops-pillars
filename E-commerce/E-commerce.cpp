#include<iostream>
#include<string>
#include<vector>
using namespace std;
class product{
    public:
    string name;
    double price;

    product(string name , double price){
        this->name = name;
        this->price = price;
    }

};
class shoppingcart{
    private:
    vector<product*> products;
    public:
    void addproduct(product* p){
        products.push_back(p);
    }
    const vector<product*>&getproduct(){
        return products;
    }
    double calculateTotal(){
        double total =0;
        for(auto p:products){
            total += p->price;
        }
        return total;
    }

};
class shoppingcartprinter{
    private:
    shoppingcart* cart;
    public:
    shoppingcartprinter(shoppingcart* cart){
        this->cart = cart;
    }
    void printinvoice(){
        cout<<"shopping cart invoice\n";
        for(auto p : cart->getproduct()){
            cout<<p->name<<"-Rs"<<p->price<<endl;
        }
        cout<<"total Rs"<<cart->calculateTotal()<<endl;

    }
};
class shoppingcartstorage{
    private:
    shoppingcart* cart;
    public:
    shoppingcartstorage(shoppingcart* cart){
        this->cart = cart;
    }
    void savetodatabase(){
        cout<<"saving shopping cart to database"<<endl;
    }
};

// Abstract Class
class persistence{
    private:
    shoppingcart* cart;
    public:
    virtual void save(shoppingcart* cart) = 0;
};
class sqlpersistance : public persistence{
    public:
    void save(shoppingcart* cart) override{
        cout<<"saving shopping cart to sql db..."<<endl;
    }
};
class mongopersistance : public persistence{
    public:
    void save(shoppingcart* cart) override{
        cout<<"saving shopping cart to sql db..."<<endl;
    }
};
class filepersistance : public persistence{
    public:
    void save(shoppingcart* cart) override{
        cout<<"saving shopping cart to a file..."<<endl;
    }
};
int main(){
    shoppingcart* cart = new shoppingcart();
    cart->addproduct(new product("laptop",50000));
    cart->addproduct(new product("mouse" , 2000));

    shoppingcartprinter* printer = new shoppingcartprinter(cart);
    printer->printinvoice();

    persistence* db = new sqlpersistance();
    persistence* mongo = new mongopersistance();
    persistence* file = new filepersistance();

    db->save(cart);
    mongo->save(cart);
    file->save(cart);
    
    return 0;

}