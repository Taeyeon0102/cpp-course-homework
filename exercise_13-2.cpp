#include <iostream>
#include <string>
using namespace std;

template<typename T1,typename T2>
class Pair{

    T1 first;
    T2 second;

    public:
    Pair(){}
    void set(T1 a, T2 b){
        first = a;
        second = b;
    }
    T1 getfirst(){return first;}
    T2 getsecond(){return second;}

};

int main(){
    Pair<int, string> p[3];

    cout << "Enter the three pairs: int string" << endl;
    for(int i=0; i<3; i++){
        int n; string s;
        cin >> n >> s;
        p[i].set(n, s);
    }
    cout << "===== pair container ======" << endl;
    for(int i=0; i<3; i++){
        cout << "(" << p[i].getfirst() << ", " << p[i].getsecond() << ")" << endl;
    }
}