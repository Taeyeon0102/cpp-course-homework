#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character{
    protected:
    string name;
    int energy;
    public:
    //생성자
    Character(){}
    Character(string name){
        this->name = name;
        this->energy = 100;
    }
    //소멸자
    virtual ~ Character(){}
    //멤버 함수
    string getName(){
        return name;
    }
    int getEnergy(){
        return energy;
    }
    void virtual attack(){
        cout << name << " attacks." << endl;
        energy -= 20;
    }
    void virtual eat(){
        cout << name << " eats." << endl;
        energy += 30;
    }
    void virtual rest(){
        cout << name << " rests." << endl;
        energy += 15;
    }

};


class Warrior : public Character{
    public:
    Warrior(string name): Character(name){}
    void attack(){
        cout << getName() << " Cuts with a sword!!!" << endl;
        energy -= 20;
    }
};

class Wizard : public Character{
    public:
    Wizard(string name): Character(name){}
    void attack(){
        cout << getName() << " Throws a fireball!!!" << endl;
        energy -= 20;
    }
    
};

class Archer : public Character{
    public:
    Archer(string name): Character(name){}
    void attack(){
        cout << getName() << " Shoots an arrow!!!" << endl;
        energy -= 20;
    }
};

class RPG_Simulation{
    private:
    vector<Character*> characters;
    public:
    //생성자
    RPG_Simulation(){}
    //소멸자
    ~RPG_Simulation(){
        for(Character* c: characters){
            delete c;
        }
    }
    //멤버 함수
    void addCharacter(Character* c){
        characters.push_back(c);
    }
    void runDay(){
        cout << "===== Starting a new Day!!! =====" << endl;
        
        // (1)
        cout << " - " << characters[0]->getName() << " Action -" << endl;
        characters[0]->attack();

        // (2)
        cout << " - " << characters[1]->getName() << " Action -" << endl;
        characters[1]->eat();

        // (3)
        cout << " - " << characters[2]->getName() << " Action -" << endl;
        characters[2]->rest();

        cout << "====================" << endl;
    }
    void showSummary(){
        cout << "===== Summary of Day =====" << endl;
        double totalE = 0.0;
        for(int i=0; i<characters.size(); i++){
            cout << characters[i]->getName() << " remaining energy: " << characters[i]->getEnergy() << endl;
            totalE += characters[i]->getEnergy();
        }
        cout << "average of energy : " << totalE/characters.size() << endl;
    }


};

int main(){
    
    RPG_Simulation sim;

    sim.addCharacter(new Warrior("Taeyeon"));
    sim.addCharacter(new Wizard("galinda"));
    sim.addCharacter(new Archer("robin"));

    sim.runDay();
    sim.showSummary();



    return 0;
}