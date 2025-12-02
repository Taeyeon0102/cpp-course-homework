#include <iostream>
#include <vector>
using namespace std;

class Shape{
    public:
    //소멸자가 여러번 호출되면 에러가 생기므로 꼭 virtual을 써준다
    virtual ~ Shape(){}
    virtual double area() =  0;     //순수가상함수
};

//꼭 호출되어야 하는 함수는 override 키워드를 써준다.
class Circle: public Shape {
    private:
    double r;
    public:
    Circle(double r){ this->r = r; }
    ~ Circle(){}
    double area() override {
        return 3.14159*r*r;
    }
};

class Rectangle: public Shape {
    private:
    double w, h;
    public:
    Rectangle(double w, double h){ 
        this->w = w; 
        this->h = h; }
    ~ Rectangle(){}
    double area () override {
        return w*h;
    }
};

class Triangle: public Shape {
    private:
    double w, h;
    public:
    Triangle(double w, double h){ 
        this->w = w;
        this->h = h;
    }
    ~ Triangle(){}
    double area() override {
        return w*h*0.5;
    }
};

int main(){
    vector<Shape*> shapes;

    double r, w1, h1, w2, h2;
    cout << "원의 반지름을 입력하시오. " << endl;
    cin >> r;
    cout << "직사각형의 밑변과 높이를 쓰시오. " << endl;
    cin >> w1 >> h1;
    cout << "삼각형의 밑변과 높이를 쓰시오. " << endl;
    cin >> w2 >> h2;

    shapes.push_back(new Circle(r));
    shapes.push_back(new Rectangle(w1, w2));
    shapes.push_back(new Triangle(w2, h2));

    double total;
    for(int i=0; i<shapes.size(); i++){
        total += shapes[i]->area();
        delete shapes[i];
    }
    cout << "모든 도형의 넓이의 합: " << total << endl;

    return 0;
}