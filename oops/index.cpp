#include<iostream>
#include<string>
using namespace std;
class car{
    public:
    //characterstic ya functionality
    virtual void startengine()=0;
    virtual void shiftgear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brakes() = 0;
    virtual void stopengine() = 0;
    virtual ~car() {};

  

};

class sportscar : public car{
    public:
    string brand;
    string model;
    bool isengineon;
    int currentspeed;
    int currentgear;

    sportscar(string b , string m){
        this->brand = b;
        this->model = m;
        isengineon = false;
        currentspeed = 0;
        currentgear = 0;

    }

    void startengine(){
        isengineon = true;
        cout<<brand<<" " << model <<":"<<"Engine is start with a roar"<<endl;

    }
    void shiftgear(int gear){
        if(!isengineon){
            cout<<brand<<" "<<model<<": Engine is not start! cannot switch the gear"<<endl;
            return ;
        }
        currentgear = gear;
        cout<<brand<<" "<<model<<": shifted to gear"<<" " <<currentgear<< endl;
        
    }
    void accelerate(){
        if(!isengineon){
            cout<<brand<<" "<<model<<": Engine is not start! cannot switch the gear" << endl;
            return ;
        }
        currentspeed += 20;
        cout<<brand<<" "<<model<<": Accelerate to"<<" "<<currentspeed<<"km/h"<< endl;


    }
    void brakes(){
        currentspeed -= 20;
        if(currentspeed<0){
            currentspeed = 0;
        }
        cout<<brand<<" "<<model<<": Breaking! currentspeed now"<<" "<<currentspeed<<"km/h" << endl;
    }
    void stopengine(){
        isengineon = false;
        currentgear=0;
        currentspeed = 0;
        cout<<brand<<" "<<model<<": engine turned off"<< endl;

    }


};
int main(){
    car* myCar = new sportscar("TATA" , "PUNCH");
    myCar->startengine();
    myCar->shiftgear(1);
    myCar->accelerate();
    myCar->shiftgear(2);
    myCar->accelerate();
    myCar->brakes();
    myCar->stopengine();


}