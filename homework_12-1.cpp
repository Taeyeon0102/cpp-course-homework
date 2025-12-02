#include <iostream>
#include <cmath>

using namespace std;

class Point{
    private:
    double x, y;
    friend double distance(const Point& p1, const Point& p2);

    public:
    //생성자와 소멸자
    Point(): x(0.0), y(0.0) {};
    Point(double x, double y){ this->x = x; this->y = y; }
    ~ Point(){}
    //getter
    double getx() const {
        return x;
    }
    double gety()const {
        return y;
    }
    //연산자 오버로딩
    Point operator+(const Point& p2) const {
        double a = this->getx()+p2.getx();
        double b = this->gety()+p2.gety();
        return Point(a, b);
    }

    Point operator*(double k) const {
        double a = this->getx()*k;
        double b = this->gety()*k;
        return Point(a, b);
    }

    bool operator==(const Point& p2)const {
        return this->getx()==p2.getx() && this->gety()==p2.gety();
    }

    friend istream& operator>> (istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }

    friend ostream& operator<< (ostream& os, const Point& p) {
        os << p.x << p.y;
        return os;
    }
    //출력 함수
    void print() const{
        cout << "( " << getx() << ", " << gety() << " )" << endl;
    }
};
//거리 계산 함수
double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
//삼각형의 넓이 함수(신발끈 공식)
double TriangleArea(const Point& p1, const Point& p2, const Point& p3){
    double area =  0.5*((p1.getx()*p2.gety() + p2.getx()*p3.gety() + p3.getx()*p1.gety())
    - (p1.gety()*p2.getx() + p2.gety()*p3.getx() + p3.gety()*p1.getx()));
    return abs(area);
}
//한 직선에 세 점이 있는지 확인(넓이가 0인가?)
bool Collinear(const Point& p1, const Point& p2, const Point& p3) {
    return(TriangleArea(p1, p2, p3) == 0);
}

int main(){
    Point p1, p2, p3;
    double scalar;
    cout << "Enter two vectors (x1, y1, x2, y2, x3, y3, k): " << endl;
    cin >> p1;
    cin >> p2;
    cin >> p3;
    cin >> scalar;


    cout << "P1 = ";
    p1.print();

    cout << "P2 = ";
    p2.print();

    cout << "P3 = ";
    p3.print();

    cout << "P1 * " << scalar << " = ";
    Point dot(p1*scalar); dot.print();
    cout << "Triangle Area : " << TriangleArea(p1,  p2, p3) << endl;
    cout << "Collinear : ";
    if(Collinear(p1, p2, p3) == 1){
        cout << "TRUE" << endl;
    } else {cout << "False"; }

    return 0;
}