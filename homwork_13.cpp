#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#define MAX_C 100       //용량을 100으로 고정함.
using namespace std;

//Student
class Student{
    public:
    string id;
    string name;
    int score;

    //생성자
    Student(string i = "", string n = "", int s = 0): id(i), name(n), score(s){}
    //소멸자
    ~ Student(){}
};

//Stack
template<typename T>
class MyStack{
    private:
    T* arr;
    int capacity;
    int top;
    public:
    //생성자
    MyStack() : capacity(MAX_C), top(-1) {
        arr = new T [capacity];
    }
    //소멸자
    ~MyStack(){
        delete[] arr;
    }
    //멤버 함수
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

//Queue
//먼저 들어간 것이 먼저 나오는 구조로 줄서기랑 비슷함
template<typename T>
class MyQueue{
    private:
    T* arr;
    int capacity;
    int size;

    public:
    //생성자
    MyQueue() : capacity(MAX_C), size(0) {
        arr = new T [capacity];
    }
    //소멸자
    ~MyQueue(){
        delete[] arr;
    }
    //멤버 함수
    int getsize(){
        return size;
    }
    void enqueue(T data){
        if(size + 1 < capacity){
            arr[size++] = data;
        }
    }
    T dequeue(){
         if(size > 0){
            T result =  arr[0];
            for(int i=0; i<size-1; i++){
                arr[i] = arr[i+1];
            }
            size--;
            return result;
        }
        throw runtime_error("Queue is empty");
    }

    T pick(){
        if(size >= 0){
            return arr[0];
        }
    }

    bool isEmpty(){
        return size==0;
    }

};

//Map : key와 value가 필요하므로 구조체를 만들어서 쌍을 이룬다.
template<typename K, typename V>
class MyMap{
    private:
    struct Pair{
        K key;
        V value;
    };
    Pair* arr;
    int size;
    int capacity;
    
    public:
    //생성자
    MyMap() : size(0), capacity(MAX_C) {
        arr = new Pair [capacity];
    }
    //멤버 함수
    void insert(K key, V value){
        arr[size].key = key;
        arr[size].value = value;
        size++;
    }
    V find(K key){
        for(int i=0; i<size; i++){
            if(key == arr[i].key){
                return arr[i].value;
            }
        }
        throw "no exist...";
    }
};

//점수 기준 내림차순 정렬 함수
void score_sort(vector<Student>& temp){
    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<temp.size(); j++){
            if(temp[i].score < temp[j].score){
                Student t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
}



int main(){

    // 1. 데이터 읽기
    ifstream in("/Users/taeyeonkim/Desktop/coding/C++_Workspace/exercises/week13/input.txt");
    if (!in) {
        cout << "파일오픈 실패";
        return 0;
    }

    //객체 생성
    MyStack<Student> studentStack; 
    string line;
    
    while (getline(in, line)) {
        //한 줄 읽어오기
        stringstream ss(line);
        
        string tempID, tempName;
        int tempScore;

        //공백 기준으로 쪼개서 저장
        if (ss >> tempID >> tempName >> tempScore) {
            
            //읽은 정보로 Student 객체 생성
            Student newStudent(tempID, tempName, tempScore);

            //스택에 저장 (Push)
            studentStack.push(newStudent);
        }
    }

    in.close();
    cout << "데이터 읽기 완료!" << endl;

    // 2. 정렬
    // 임시 객체 생성(스택에서 꺼내서 넣기)
    vector<Student> temp;
    while(!studentStack.isEmpty()){
        temp.push_back(studentStack.pop());
    }
    // 정렬(점수기준 내림차순)
    score_sort(temp);

    // 3. 큐로 이동
    //하나씩 꺼내서 큐에 넣기
    MyQueue<Student> studentQueue;
    for(int i=0; i<temp.size(); i++){
        studentQueue.enqueue(temp[i]);
    }

    // 4. 맵으로 이동
    //하나씩 꺼내서 맵으로 이동, key를 student.id로, value를 student로 넣기
    MyMap<string, Student> studentMap;
    while(studentQueue.getsize() > 0){
        Student t = studentQueue.dequeue();
        studentMap.insert(t.id, t);
    }
    
    // 5. 검색
    //학번 검색시 -> 정보 출력
    string target;
    cout << "Enter the ID of the student who you want to find: ";
    cin >> target;

    //프로그램 폭파 방지
    try {
        // 1) 찾기 시도
        Student foundStudent = studentMap.find(target);
        
        // 2) 찾았다면 출력
        cout << "===== result =====" << endl;
        cout << "name : " << foundStudent.name << ", ";
        cout << "score : " << foundStudent.score << endl;

    } catch (const char* msg) {
        // throw가 발생 시 catch로 넘어옴! 그리고 프로그램 수습
        cout << "Error: " << msg << endl;
        cout << "해당하는 학번의 학생을 찾을 수 없습니다." << endl;
    }

    return 0;

}