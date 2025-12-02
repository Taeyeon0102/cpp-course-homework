#include <iostream>
#include <vector>
using namespace std;

//사진 참고!!!!!

template<typename T>
class Stack{
    T* arr;
    int capacity;
    int top;
    public:
    //생성자
    Stack() : capacity(100), top(-1) {
        arr = new T [capacity];
    }
    //소멸자
    ~Stack(){
        delete[] arr;
    }
    void push(T x){
        if(top + 1 < capacity){
            arr[++top] = x;
        }
        
    }
    T pop(){
        if(top >= 0){
            return arr[top--];
        }
        throw runtime_error("Stack is empty");
    }
    bool isEmpty(){
        return top==-1;
    }
};

int main(){
    Stack<int> st;
    string command;

    while(true){
        cin >> command;
        if(command == "push"){
            int value;
            cin >> value;
            st.push(value);
        } else if(command == "pop"){
            if(!st.isEmpty()){
                cout << st.pop() << endl;
            }
        } else if(command == "end") break;
    }

    return 0;
}