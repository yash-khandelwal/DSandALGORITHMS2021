#include<iostream>
using namespace std;


class Paint{
    int cost;
public:
    /// constructor
    Paint(int cost = 50){
        cout<<"Paint constructor called..\n";
        this -> cost = cost;
    }
    /// destructor
    ~Paint(){
        cout<<"Paint destructor is called..\n";
    }
    int getCost(int area){
        return cost*area;
    }
};

/// Base class
class Shape{
protected:
    int width;
    int height;
public:
    Shape(){
        cout<<"Shape constructor is called..\n";
    }
    ~Shape(){
        cout<<"Shape destructor is called..\n";
    }
    void setHeight(int h){
        height = h;
    }
    void setWidth(int w){
        width = w;
    }
};

/// Derived class single inheritance
class Rectangle: public Shape {
public:
    /// constructor
    Rectangle(int h = 0, int w = 0){
        cout<<"Rectangle constructor called..\n";
        width = w;
        height = h;
    }
    /// copy constructor
    Rectangle(const Rectangle &r){
        cout<<"Rectangle copy constructor called..\n";
        width = r.width;
        height = r.height;
    }
    /// destructor
    ~Rectangle(){
        cout<<"Rectangle destructor is called..\n";
    }
    int getArea(){
        return width*height;
    }
};
class Square: public Paint, public Rectangle{
public:
    Square(int side = 10){
        cout<<"Square constructor called..\n";
        this -> setHeight(side);
        this -> setWidth(side);
    }
    ~Square(){
        cout<<"Square destructor called..\n";
    }
//    int getArea(){
//        return width*height;
//    }
};

int main(){
    Rectangle r1; /// constructor is called
    r1.setHeight(10);
    r1.setWidth(5);
    cout<<r1.getArea()<<"\n";
    Rectangle r2 = r1; /// in this type of initialization only copy constructor is called not constructor
    cout<<r2.getArea()<<"\n";
    Square s1 = Square(10);
    cout<<s1.getArea()<<"\n";
    return 0;
}
