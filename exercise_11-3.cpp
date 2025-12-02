#include <iostream>

using namespace std;

class Robot{
    public:
    Robot(){}
    virtual ~Robot(){}
    void virtual work(){}
};

class CleaningRobot : public Robot {
    public:
    CleaningRobot(){}
    ~ CleaningRobot(){}
    void work() override {
        cout << "Cleaning....." << endl;
    }
};

class DeliveryRobot : public Robot{
    public:
    DeliveryRobot(){}
    ~ DeliveryRobot(){}
    void work() override {
        cout << "Delivering....." << endl;
    }
};

int main(){
    vector<Robot*> robots;
    robots.push_back(new CleaningRobot());
    robots.push_back(new DeliveryRobot());

    robots[0]->work();
    robots[1]->work();

    delete robots[0];
    delete robots[1];

    return 0;
}