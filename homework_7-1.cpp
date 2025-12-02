#include <iostream>
using namespace std;

class DynamicArray{
    private:
    int *arr;
    int size;
    
    public:
    //생성자
    DynamicArray(int size){
        this->size = size;
        arr = new int[size]();
    }
    DynamicArray():arr(nullptr), size(0){}
    //소멸자
    ~DynamicArray(){
        delete[] arr;
    }
    //배열 길이 반환
    int length(){
        return size;
    }
    //배열의 마지막 원소 제거
    void pop(){
        if(size <= 0){
            cout << "Array is empty, cannot pop." << endl;
            return;
        }
        cout << "Pop : " << arr[size-1] << endl;
        int *newArr = new int[size-1]();
        for(int i=0; i<(size-1); i++){
            newArr[i] = arr[i];
        }
        delete [] arr;
        arr = newArr;
        size -= 1;
    }
    //배열의 마지막에 원소 추가
    void push(int value){
        cout << "Push : " << value << endl;
        int *newArr = new int[size+1]();
        for(int i=0; i<size; i++){
            newArr[i] = arr[i];
        }
        newArr[size] = value;
        delete [] arr;
        
        arr = newArr;
        size += 1;
    }
};

int main() {
    DynamicArray arr;
    arr.push(10);
    arr.push(20);
    arr.push(30);
    arr.push(40);
    arr.push(50);

    cout << "Current Length: " << arr.length() << endl;

    arr.pop();
    arr.pop();
    cout << "Current Length: " << arr.length() << endl;

    return 0;
}
