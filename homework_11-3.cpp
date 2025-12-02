#include <iostream>
#include <vector>
using namespace std;

class Robot{
    public:
    Robot(){}   //생성자
    virtual ~Robot(){}      //소멸자
    void virtual work() = 0;   //순수가상함수
};

class CleaningRobot : public Robot {
    public:
    CleaningRobot(){}
    ~ CleaningRobot(){}
    void work() override {  //오버라이딩
        cout << "Cleaning....." << endl;
    }
};

class DeliveryRobot : public Robot{
    public:
    DeliveryRobot(){}
    ~ DeliveryRobot(){}
    void work() override {  //오버라이딩
        cout << "Delivering....." << endl;
    }
};

class GuardRobot : public Robot{
    public:
    GuardRobot(){}
    ~ GuardRobot(){}
    void work() override {  //오버라이딩
        cout << "protecting....." << endl;
    }
};

int main(){
    vector<Robot*> robots;  //로봇 생성
    robots.push_back(new CleaningRobot());
    robots.push_back(new DeliveryRobot());
    robots.push_back(new GuardRobot());

    cout << "===== working ======" << endl;
    for(Robot* r: robots){
        r->work();
    }

    for(Robot* r: robots){
        delete r;
    }

    return 0;
}