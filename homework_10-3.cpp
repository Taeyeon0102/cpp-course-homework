#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
    string name;
    public:
    //생성자
    Person(): name(""){ cout << getName() << "Person 생성자 호출" << endl; }
    Person(string name){
        this->name = name;
        cout << getName() << " Person 생성자 호출" << endl;
    }
    //소멸자
    ~ Person(){ cout << getName() << "Person 소멸자 호출" << endl; }
    //getter, setter
    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }
    //멤버 함수
    void Introduce_Person(){
        cout << "name: " << name << endl;
    }

};

class Student : public Person{
    private:
    int studentID;
    public:
    //생성자
    Student(): studentID(0){ cout << getName() << "Student 생성자 호출" << endl; }
    Student(int ID){
        this->studentID = ID;
        cout << getName() << "Student 생성자 호출" << endl;
    }
    //소멸자
    ~ Student(){ cout << getName() << "Student 소멸자 호출" << endl; }
    //getter, setter
    int getStudentID(){
        return studentID;
    }
    void setStudentID(int studentID){
        this->studentID = studentID;
    }
    //멤버 함수
    void Introduce_Student(){
        Introduce_Person();
        cout << getName() << "Student ID: " << studentID << endl;
    }

};

class UndergradStudent : public Student {
    private:
    string major;
    public:
    //생성자
    UndergradStudent(): major(""){ cout << getName() << "UndergradStudent 생성자 호출" << endl; }
    UndergradStudent(string major){
        this->major = major;
        cout << getName() <<"UndergradStudent 생성자 호출" << endl;
    }
    //소멸자
    ~ UndergradStudent(){ cout << getName() << "UndergradStudent 소멸자 호출" << endl; }
    //getter, setter
    string getMajor(){
        return major;
    }
    void setMajor(string major){
        this->major = major;
    }
    //멤버 함수
    void Introduce_UndergradStudent(){
        Introduce_Student();
        cout << "major: " << major << endl;
    }

};

class GradStudent : public UndergradStudent {
    private:
    string researchTopic;
    public:
    //생성자
    GradStudent(): researchTopic(""){ cout << getName() << "GradStudent 생성자 호출" << endl; }
    GradStudent(string researchTopic){
        this->researchTopic = researchTopic;
        cout << getName() << "GradStudent 생성자 호출" << endl;
    }
    //소멸자
    ~ GradStudent(){ cout << getName() << "GradStudent 소멸자 호출" << endl; }
    //getter, setter
    string getResearchTopic(){
        return researchTopic;
    }
    void setResearchTopic(string topic){
        this->researchTopic = topic;
    }
    //멤버 함수
    void Introduce_GradStudent(){
        Introduce_UndergradStudent();
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main(){
    // (1) 값 기반
    vector<Student> students_1;
    cout << "===== vector<Student> =====" << endl;
    
    //객체 만들기
    /*GradStudent obj1;
    obj1.setName("김태연");
    obj1.setStudentID(202500937);
    obj1.setMajor("Computer_Engineering");
    obj1.setResearchTopic("AI"); */
    UndergradStudent obj2;
    obj2.setName("홍길동");
    obj2.setStudentID(202500123);
    obj2.setMajor("Philosophy");

    //vector(Student)에 넣기
    students_1.push_back(obj1);
    students_1.push_back(obj2);

    //출력(Student에 넣었기 때문에 Introduce_Student로)
    cout << "----- 출력 -----" << endl;
    students_1[0].Introduce_Student();
    cout << "---------------" << endl;
    students_1[1].Introduce_Student();
    cout << "---------------" << endl;
    cout << "\n\n";

    // (2) 포인터 기반
    vector<Student*> students_2;
    cout << "===== vector<Student*> =====" << endl;

    //객체 만들기
    GradStudent* ptr1 = new GradStudent;
    ptr1->setName("김태연");
    ptr1->setStudentID(202500937);
    ptr1->setMajor("Computer_Engineering");
    ptr1->setResearchTopic("AI");
    UndergradStudent* ptr2 = new UndergradStudent;
    ptr2->setName("홍길동");
    ptr2->setStudentID(20250123);
    ptr2->setMajor("Philosophy");

    //vector에 넣기
    students_2.push_back(ptr1);
    students_2.push_back(ptr2);

    //출력
    cout << "----- 출력 -----" << endl;
    students_2[0]->Introduce_Student();
    cout << "---------------" << endl;
    students_2[1]->Introduce_Student();
    cout << "---------------" << endl;

    //포인터 객체 수동 삭제
    cout << "===== 포인터 객체 수동 삭제 =====" << endl;
    for(Student* ptr: students_2){
        delete ptr;
    }
    cout << "---------------" << endl;

    return 0;
}