#include <iostream>
#include <string>
using namespace std;

template<typename T> T getMax(T x, T y){
    if(x >= y ) return x;
    else return y;
}

int main(){
    int n;
    cout << "how many kind of type do you want to run?" << endl;
    cin >> n;

    while(n--){

    string a, b;
    cin >> a >> b;


        
    if(isdigit(a[0]) && a.find('.') == string::npos){
        cout << getMax(stoi(a), stoi(b)) << endl;
    } else if (a.find('.') != string::npos){
        cout << getMax(stoi(a), stoi(b)) << endl;
    } else {
        cout << getMax(a, b) << endl;
    }
    }
    

}