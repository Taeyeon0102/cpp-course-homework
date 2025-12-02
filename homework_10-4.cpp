#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct location{
    double x;
    double y;
};

class Robot{
    private:
    int id;
    location point;
    double moved;

    public:
    static int idCounter;
    static double totalDistance;

    //생성자
    Robot(){
        id = idCounter;
        point.x = 0.0;
        point.y = 0.0;
        moved = 0;
        idCounter++;
        cout << "Robot #" << id << "  is generated, Starting point: (0,0)" << endl;
    }
    //소멸자
    ~ Robot(){}
    //멤버 함수
    int getId(){
        return id;
    }
    void move(int dx, int dy){
        point.x += dx;
        point.y += dy;
        moved += sqrt(dx*dx + dy*dy);
        totalDistance += sqrt(dx*dx + dy*dy);
        cout << "Robot #" << id << "  move (" << point.x << ", " << point.y << ")  ->  ";
        }
    void printStatus(){
        cout <<"Robot #" << id <<  "  current location: (" << point.x << ", " << point.y << "), 누적거리: " << moved << endl;
    }
    static void showTotal(){
        cout << "===== Total =====" << endl;
        cout << "Total number of robots: " << idCounter << endl;
        cout << "Total Distance: " << totalDistance << endl;
    }

};

int Robot::idCounter = 0;
double Robot::totalDistance = 0.0;

class Simulation{
    private:
    vector<Robot> robots;
    public:
    //생성자
    Simulation(){}
    //소멸자
    ~ Simulation(){}
    //멤버 함수
    void runScenario(){
        // (1) 요청한 로봇 수 만큼 로봇 생성 후 벡터에 넣기
        int n;
        cout << "How many Robots do you want? ";
        cin >> n;

        for(int i=0; i<n; i++){
            robots.push_back(Robot());
        }
      

        // (2) 로봇 시나리오 실행!
        cout << "\n\n";
        cout << "===== Robot Scenario Start!! =====" << endl;
        char choice;
        while(1){
            cout << "\n\n";
            cout << "Do you want to move the robots?" << endl;
            cout << ">  Y / N" << endl;
            cin >> choice;

            if(choice == 'N') break;
            else if(choice == 'Y'){
                for(int i=0; i<n; i++){
                int dx, dy;
                cout << "Robot #" << robots[i].getId() << "  Enter the moving distance(x, y):  ";
                cin >> dx >> dy;

                robots[i].move(dx, dy);
                robots[i].printStatus();
                }
             } else {
                cout << "Error!!!" << endl;
            }
        
        }
        cout << "===== End of Robot Scenario =====" << endl;
        cout << "\n\n";

    }
    void showAllStatus(){
        // (3) 최종 로봇 상태 출력
        cout << "===== Final Robots Status =====" << endl;
        for(Robot& r: robots){
            r.printStatus();
        }
        Robot::showTotal();
    }
};

int main(){

    Simulation sim1;
    sim1.runScenario();
    sim1.showAllStatus();

    return 0;

}