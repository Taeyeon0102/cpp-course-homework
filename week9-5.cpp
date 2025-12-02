#include <iostream>
#include <string>
using namespace std;

class Animal(){
    private:
        string name;
        int energy;
    public:
    //생성자
        Animal(string n, int e): name(n), energy(50) {}
    //행동 메서드
        void eat(){
            cout << name << " is eating." << endl;
            energy += 10;
        }
        void makeSound(){
            cout << name << " makes a sound." << endl;
            energy -= 5;
        }
        void sleep(){
            cout << name << " is sleeping." << endl;
            energy += 5;
        }
        //소멸자
        ~Animal(){
            cout << name << " is being destroyed." << endl;
        }

    
};

class ZooSimulation(){
    private:
        Animal* animals[100];
        int animalCount;
    public:
        ZooSimulation(): animalCount(0) {}
        void addAnimal(Animal* a){
            if(animalCount < 100){
                animals[animalCount++] = a;
            }
        }

        void runSimulation(){
            for(int i = 0; i < animalCount; i++){
                animals[i]->eat();
                animals[i]->makeSound();
                animals[i]->sleep();
            }
        }
        void runday(){
            cout << "하루가 시작됩니다" << endl;
            int action =0;
            for(auto a : animals){
                cout << a->getName() << "의 행동" << endl;
                if(action %3 == 0){
                    a->eat();
                }
                else if(action %3 == 1){
                    a->makeSound();
                }
                else{
                    a->sleep();
                }

                cout << a->getName() << "의 현재 에너지: " << a->getEnergy() << endl;
                action++;
        }

        void showsum(){
            cout << "하루가 끝났습니다." << endl;
            int total =0;
            for(auto a : animals){
                total += a->getEnergy(); 
                cout << a->getName() << "의 최종 에너지: " << a->getEnergy() << endl;
               
            }
            cout << "평균 에너지: " << total/animals.size() << endl;
    };
}

int main(){
    string name;
    int energy;
    ZooSimulation zooSim;
    for(int i=0; i<3; i++){
        cout << "Enter Animal Name : ";
        cin >> name;
        Animal* a = new Animal(name);
        zooSim.addAnimal(a);
    }
    zooSim.runday();
    zooSim.showsum();
    return 0;
}