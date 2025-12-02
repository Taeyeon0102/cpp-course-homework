#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal{
    public:
    Animal(){}
    void virtual speak()=0;
};

class Cat : public Animal{
    public:
    Cat(){}
    ~ Cat(){}

    void speak () override{
        cout << "야옹~ 야옹~" << endl;
    }
};

class Dog : public Animal{
    public:
    Dog(){}
    ~ Dog(){}

    void speak() override {
        cout << "멍멍!!!!" << endl;
    }
};

int main(){
    vector<Animal*> animals {new Cat(), new Dog()};

    for(vector<Animal> a: animals){
        a.speak();
    }

    delete [];

    return 0;

}