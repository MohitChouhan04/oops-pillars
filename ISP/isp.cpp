#include<iostream>
using namespace std;

//abstract class 
class TwoDimensionalshape{
    public:
    virtual double area() =0; //pure virtual function
};
class Threedimensionalshape{
    public:
    virtual double area() =0;
    virtual double volume() =0;

};
class square : public TwoDimensionalshape{
    private:
    double side;

    public:
    square(double s):side(s){}
    double area() override{
        return side* side;
    }
};
class rectangle: public TwoDimensionalshape{
    public:
    double length,width;
    public:
    rectangle(double l , double w ) : length(l),width(w){}
    double area() override{
        return length*width;
    }
};
class cube : public Threedimensionalshape{
    private:
    double side;
    public:
    cube(double s):side(s){}
    double area() override{
        return 6 * side * side;
    }
    double volume() override{
        return side * side * side;
    }
};

int main(){
    TwoDimensionalshape* Square = new square(5);
    TwoDimensionalshape* Rectangle = new rectangle(4, 6);
    Threedimensionalshape* Cube = new cube(3);

    cout<<"square area: " << Square->area() << endl;
    cout<<"Rectangle area: " << Rectangle->area() << endl;
    cout<<"cube area: " << Cube->area() << endl;
    cout<<"cube volume: " << Cube->volume() << endl;


}