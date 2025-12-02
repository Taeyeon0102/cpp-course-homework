#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
    public:
    // Constructor
        Person(): name("") { cout << "Person default constructor called." << endl; }
        Person(string n): name(n) { cout << "Person constructor called." << endl; }
    // Getter
        string getName() const { return name; }
    // Setter
        void setName(const string& n) { name = n; }
    // Destructor
    ~Person() {cout << "Person destructor called." << endl; }

    void introduce() const {
        cout << "Hello, my name is " << name << "." << endl;
    }
};

class Student : public Person{
    private:
        string studentID;
    public:
    // Constructor
        Student(): studentID("") {cout << "Student default constructor called." << endl; }
        Student(string n, string id): Person(n), studentID(id) {cout << "Student constructor called." << endl; }
    // Getter
        string getStudentID() const { return studentID; }
    // Setter
        void setStudentID(const string& id) { studentID = id; }
    // Destructor
    ~Student() {cout << "Student destructor called." << endl; }
};

class GradStudent : public Student{
    private:
        string researchTopic;
    public:
    // Constructor
        GradStudent(): researchTopic("") {}
        GradStudent(string n, string id, string topic): Student(n, id), researchTopic(topic) {cout << "GradStudent constructor called." << endl; }
    // Getter
        string getResearchTopic() const { return researchTopic; }
    // Setter
        void setResearchTopic(const string& topic) { researchTopic = topic; }
    // Destructor
    ~GradStudent() {cout << "GradStudent destructor called." << endl; }
};

int main(){
    
    GradStudent gradStudent("Taeyeon", "GS12345", "Artificial Intelligence");
    gradStudent.introduce();
    return 0;
}