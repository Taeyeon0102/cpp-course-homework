#include <iostream>
#include <cstring>
using namespace std;

class StringList{
    private:
    char** list;
    int size;
    int capacity;
    friend string findlong();
    friend StringList intersect(const StringList& s1, const StringList& s2);

    public:
    //생성자
    StringList(int n) : size(0), capacity(n){
        list = new char* [capacity];
        for(int i=0; i<capacity; i++) list[i] = nullptr;
    }
    //소멸자
    ~StringList(){
        for(int i=0; i<capacity; i++) delete[] list[i];
        delete[] list;
    }
    int getsize(){
        return size;
    }
    //깊은 복사(연산자 오버로딩=)
    StringList& operator= (const StringList& s1){
        if(this == &s1) return *this;
        //기존 list 삭제
        if(list != nullptr){
            for(int i=0; i<size; i++){
                delete[] list[i];
            } delete[] list;
        }
        //s1과 같은 크기로 현재 객체 수정
        this->size = s1.size;
        this->capacity = s1.capacity;
        this->list = new char* [capacity];
        //초기화
        for(int i=0; i<capacity; i++) list[i] = nullptr;
        //값 복사
        for(int i=0; i<size; i++){
            if(s1.list[i] != nullptr){
                this->list[i] = new char[strlen(s1.list[i])+1];
                strcpy(this->list[i], s1.list[i]);
            }
        }
        return *this;
    }
    //문자열 추가
    void add(const char* s){
        list[size] = new char[strlen(s) + 1];
        strcpy(list[size], s);
        size++;
    }
    //문자열 삭제
    void remove(int index){
        if(list[index] != nullptr){
            this->list[index] = nullptr;
            delete[] list[index];
        }
        for(int i=index; i<size-1; i++){
            list[i] = list[i+1];
        }
        size--;
    }
    //인덱스 값 반환
    char *& operator[](int index){
        return list[index];
    }
    //연산자 오버로딩 << 
    friend ostream& operator << (ostream& os, const StringList& ss){
        for(int i=0; i<ss.size; i++){
            os << ss.list[i] << endl;
        }
        return os;
    }
    //연산자 오버로딩 +
    StringList operator+ (const StringList& s1){
        StringList result(this->capacity + s1.capacity);
        result.size = this->size + s1.size;

        for(int i= 0; i<this->size; i++){
            result.add(this->list[i]);
        }
        for(int i=0; i<s1.size; i++){
            result.add(s1.list[i]);
        }
        return result;
    }
    //가장 긴 string 찾기
    string findlong(){
        string longest = "";
        if(this->size == 0) return longest;
        longest = list[0];
        for(int i=0; i<size; i++){
            if(strlen(list[i]) > longest.length()) longest = list[i];
        }
        return longest;
    }
    //stringlist 출력
    void print(){
        for(int i=0; i<size; i++){
            if (list[i] != nullptr)
            cout << list[i] << endl;
        }
    }
};
    //겹치는 string 출력
StringList intersect(const StringList& s1, const StringList& s2) {
        StringList result(s1.size);
        for(int i=0; i<s1.size; i++){
            for(int j=0; j<s2.size; j++)
            if(strcmp(s1.list[i], s2.list[j]) == 0) result.add(s1.list[i]);
            break;
        }
        return result;
    }

int main(){

    int n;
    cout << "Enter the string list size and each string." << endl;
    cin >> n;
    StringList s1(5);
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        s1.add(s.c_str());
    }

    cout << "Enter the string list size and each string." << endl;
    cin >> n;
    StringList s2(5);

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        s2.add(s.c_str());
    }
    
    cout << "Remove the second string in s1 List" << endl;
    s1.remove(1);
    s1.print();

    cout << "----- A+B -----" << endl;
    StringList Add = s1+s2;
    Add.print();

    cout<<"----- Intersection -----" << endl;
    StringList inter = intersect(s1, s2);
    inter.print();

    cout<<"----- Longest in s1 -----" << endl;
    string longest = s1.findlong();
    cout << longest << endl;
    
}