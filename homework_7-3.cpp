#include <iostream>
#include <iomanip>  // For std::setprecision
using namespace std;

double my_pow(double base, int exp){    //간단한 거듭제곱 함수
    if(exp == 0) return 1.0;
    double result = 1.0;
    for(int i=0; i<exp; i++){
        result *= base;
    }
    return result;
}

class Polynomial {
    public:
    int degree;
    double* coeff;

    //생성자
    Polynomial(int deg){
        degree = deg;
        coeff = new double[deg+1];
    }
    Polynomial(const Polynomial& p){
        degree = p.degree;
        coeff = new double[degree+1];
        for(int i=0; i<=degree; i++){
            coeff[i] = p.coeff[i];
        }
    }
    Polynomial(): degree(0), coeff(new double[1]{0}){}

    //소멸자
    ~Polynomial(){
        delete[] coeff;
    }

    //멤버함수_입력, 출력, 미분, 적분, 변곡점
    void input(){
        cout << "Enter coefficients from highest degree to constant term: \n";
        for(int i=0; i<=degree; i++){
            cin >> coeff[i];
        }
    }
    void print(){
        cout << coeff[0] << "x^" << degree;
        for(int i=1; i<=degree; i++){
            cout << " + " << coeff[i] << "x^" << (degree - i);
        }
        cout << endl;
    }
    Polynomial derivative(){
        if(degree == 0){
            return Polynomial(0);
        }
        Polynomial deriv(degree - 1);
        for(int i=0; i<degree; i++){
            deriv.coeff[i] = coeff[i] * (degree - i);
        }
        return deriv;
    }
    Polynomial integral(){
        Polynomial integ(degree+1);
        for(int i=0; i<=degree; i++){
            integ.coeff[i] = coeff[i] / (degree - i + 1);
        }
        integ.coeff[degree+1] = 0; // constant of integration
        return integ;
    }
    void inflectionPoint(){
        if(degree <= 2){
            cout << "No inflection points (degree <= 2)" << endl;
            return;
        }
        Polynomial secondDeriv = this->derivative().derivative();
        cout << "Second Derivative: ";
        secondDeriv.print();
        
        double start = -100.0, end = 100.0, step = 0.01;
        cout << "Inflection points (approx.): ";

        for(double x = start; x < end; x += step){
            double f1 = 0.0, f2 = 0.0;
            for(int i=0; i<=secondDeriv.degree; i++){
                f1 += secondDeriv.coeff[i] * my_pow(x, secondDeriv.degree - i);
                f2 += secondDeriv.coeff[i] * my_pow(x + step, secondDeriv.degree - i);
            }
            if(f1 * f2 < 0){
                cout << "x ≈ " << x << endl;
            }
        }
    }
    
};


int main() {
    
    int deg;
    cout << "Enter the degree of the polynomial: ";
    cin >> deg;
    Polynomial p(deg);

    p.input();
    cout << "Polynomial: "; p.print();

    Polynomial d = p.derivative();
    cout << "Derivative: "; d.print();

    cout << fixed << setprecision(2);

    Polynomial i = p.integral();
    cout << "Integral: "; 
    cout << i.coeff[0] << "x^" << i.degree; 
    for (int k = 1; k <= i.degree; k++)
        cout << " + " << i.coeff[k] << "x^" << (i.degree - k);
    cout << " + C\n";

    p.inflectionPoint();

    return 0;
}