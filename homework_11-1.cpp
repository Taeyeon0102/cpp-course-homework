#include <iostream>
#include <vector>
using namespace std;

class Animal{
    public:
    Animal(){}
    //소멸자가 여러번 호출되면 에러가 생기므로 꼭 virtual을 써준다
    virtual ~ Animal(){}
    void virtual speak() = 0;   //순수가상함수
};
//꼭 호출되어야 하는 함수는 override 키워드를 써준다.
class Cat : public Animal{
    public:
    Cat(){}
    ~ Cat(){}
    void speak() override {
        cout << "야옹~" << endl;
    }
};

class Dog : public Animal{
    public:
    Dog(){}
    ~ Dog(){}
    void speak() override {
        cout << "멍멍!!" << endl;
    }
};

class Cow : public Animal{
    public:
    Cow(){}
    ~ Cow(){}
    void speak() override {
        cout << "음메~" << endl;
    }
};

int main(){
    vector<Animal*> animals;

    animals.push_back(new Cat());
    animals.push_back(new Dog());
    animals.push_back(new Cow());

    for(int i=0; i<animals.size(); i++){
        animals[i]->speak();
        delete animals[i];
    }

    return 0;
}