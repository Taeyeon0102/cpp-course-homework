#include <iostream>
#include <vector>
using namespace std;

class Shape{
    public:
    virtual double area() = 0;
    virtual ~Shape(){}
};

class Circle : public Shape {
    public:
    double r;
    Circle(double r){ this->r = r; }
    double area() override {
        return 3.14*r*r;
    }
};

class Rectangle : public Shape {
    public:
    double w;
    double h;
    Rectangle(double w, double h){ this->w = w; this->h = h; }
    double area() override{
        return w*h;
    }
};

int main(){
    vector<Shape*> shapes;
    shapes.push_back(new Circle(3));
    shapes.push_back(new Rectangle(2, 4));

    shapes[0]->area();
    shapes[1]->area();

    for(int i=0; i<2; i++){
        delete shapes[i];
    }
    
}