#include <iostream>
using namespace std;

struct location{
    double x;
    double y;
};

class Robot{

    double static totalDistance;
    private:
        string ID;
        location pos;
        double distance;
    public:
        Robot(string id, double x=0.0, double y=0.0): ID(id), distance(0.0) {
            pos.x = x;
            pos.y = y;
        }
        void move(double new_x, double new_y){
            double dx = new_x - pos.x;
            double dy = new_y - pos.y;
            distance += sqrt(dx*dx + dy*dy);
            pos.x = new_x;
            pos.y = new_y;
        }
};

class Simulation(){
    private:
        Robot* robots[100];
        int robotCount;
    public:
        Simulation(): robotCount(0) {}
        void addRobot(Robot* r){
            if(robotCount < 100){
                robots[robotCount++] = r;
            }
        }

        void runSimulation(){
            for(int i = 0; i < robotCount; i++){
                // Example movement pattern
                robots[i]->move(robots[i]->getX() + 1.0, robots[i]->getY() + 1.0);
            }
        }
};

int main(){
    double x, y;
    string id;
    Simulation sim;
    for(int i=0; i<3; i++){
        cout << "Enter Robot ID and initial position (x, y) : ";
        cin >> id >> x >> y;
        Robot*
    }
}