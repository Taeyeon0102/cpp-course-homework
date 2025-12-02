#include <iostream>
#include <cmath>

using namespace std;

class Point{
    private:
    double x, y;
    friend double distance(const Point& p1, const Point& p2);
    public:
    Point(): x(0.0), y(0.0) {};
    Point(double x, double y){ this->x = x; this->y = y; }
    ~ Point(){}
    double getx() const {
        return x;
    }
    double gety()const {
        return y;
    }
    Point operator+(const Point& p2)const{
        double a = this->getx()+p2.getx();
        double b = this->gety()+p2.gety();
        return Point(a, b);
    }

    bool operator==(const Point& p2)const {
        return this->getx()==p2.getx() && this->gety()==p2.gety();
    }

    void print() const{
        cout << "( " << getx() << ", " << gety() << " )" << endl;
    }

    friend istream& operator>> (istream& in, Point& p){
        in >> p.x >> p.y;
        return in;
    }

    
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main(){
    Point p1, p2;
    cout << "Enter two vectors (x1, y1, x2, y2): " << endl;
    cin >> p1;
    cin >> p2;

    Point sum = p1 + p2;
    bool equal = (p1 == p2);
    double dist = distance(p1, p2);

    cout << "P1 = ";
    p1.print();

    cout << "P2 = ";
    p2.print();

    cout << "SUM = ";
    sum.print();

    cout << "Equal = ";
    if (equal == 1){
        cout << "TRUE" << endl;
    } else {
        cout << "False" << endl;
    }
    

    cout << "Distance = ";
    cout << dist;

}