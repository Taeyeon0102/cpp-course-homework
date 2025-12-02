#include <iostream>
using namespace std;

class Currency{
    private:
    int krw;

    public:
    Currency(int w=0): krw(w){};
    explicit Currency(double usd){
        krw = (int)(usd*1300.0);
    }
    Currency operator+(const Currency& c) const {
        return Currency(krw + c.krw);
    }
    operator int() const{
        return krw;
    }
    friend ostream& operator << (ostream& out, const Currency& c){
        cout << c.krw << "KRW";
        return out;
    }
};

int main(){
    
}