#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Monster;      //미리 선언 (player에 필요)

class Player{
    private:
        string name;
        int hp;
        int maxHp;
        int atk;
    public:
        //생성자
        Player(): name(""), hp(0), maxHp(100), atk(0){}
        Player(string name, int hp, int atk){
            this->name = name;
            this->hp = hp;
            this->maxHp = 100;
            this->atk = atk;
        }
        //소멸자
        ~ Player(){}
        //getter, setter
        string getName(){
            return name;
        }
        int getHp(){
            return hp;
        }
        int getAtk(){
            return atk;
        }
        void setName(const string& name){
            this->name = name;
        }
        void setAtk(const int& atk){
            this->atk = atk;
        }
        //멤버 함수
        void attacked(int dmg){
            hp = hp - dmg;
            if(hp == 0){ hp = 0; }
        }
        void heal(int amount){
            if((hp + amount) < maxHp){
                hp = hp + amount;
            }else{ hp = maxHp; }
            
        }
        bool isDead(){
            return (hp <= 0);
        }
        void printStatus() const {
            cout << "[ " << name << " ] HP: " << hp << endl;
        }
        void attack(Monster& m);

};

class Monster{
    private:
        string name;
        int hp;
        int atk;
    public:
        //생성자
        Monster(): name(""), atk(0), hp(0){}
        Monster(string name, int atk, int hp){
            this->name = name;
            this->atk = atk;
            this->hp = hp;
        }
        //소멸자
        ~Monster(){}
        //멤버 함수
        string getName() const {
            return name;
        }
        void attacked(int dmg){
             hp = hp - dmg;
            if(hp < 0) { hp = 0; }
        }
        void attack(Player& a){
            a.attacked(atk);
            cout << name << "  Attacks (-" << atk << " HP)"<< endl;
        }
        bool isDead() const {
            return (hp <= 0);
        }
        void printStatus() const {
            cout << "[ " << name << " ] HP: " << hp << endl;
        }
        

};

//player 클래스의 attack 정의
void Player::attack(Monster& m){
            m.attacked(atk);
            cout << name << " Attacks " << m.getName() << " (-" << atk << " HP)"<< endl;
        }

class Item{
    private:
        int healAmount;
    public:
        //생성자
        Item(): healAmount(0){}
        Item(int a){
            healAmount = a;
        }
        //소멸자
        ~ Item(){}
        //멤버함수
        void use(Player& a){
            a.heal(healAmount);
            cout << "Using item!! (+" << healAmount << ")"<< endl;
        }

};

//모든 몬스터가 죽었는지 확인하는 함수
bool allMonstersDead(const vector<Monster>& monsters){
        for(const Monster& m : monsters){
            if(!m.isDead()){
                return false;
            }
        }
    return true;
    }

    
void gameSimulator(Player& p, vector<Monster>& monsters, Item& potion){
    cout << "Battle Start!!!" << endl;
    cout << "====================" << endl;

    int count = 0;
    int potion_count = 5;

    while(!p.isDead() && !allMonstersDead(monsters)){
        //시작 전 상태 출력
        cout << "----- "<< count+1 << " turn -----" << endl;
        cout << "You : ";
        p.printStatus();  

        cout << "Monsters : "<<endl;
        for(int i=0; i<monsters.size(); i++){
            cout << i << " : ";
            monsters[i].printStatus();
        }              

        // (1) plyaer turn
        cout << "----- Player's Turn -----" << endl;
        //  몬스터 선택
        int target_idx = -1;
        while(true){
            cout << "Which Monster do you attack?" << endl;
            cin >> target_idx;
        
            if(target_idx < 0 || target_idx >= monsters.size()){
                cout << "Out of Index!!!" << endl;
            } else if(monsters[target_idx].isDead()){
                cout << "It is already die!!!" << endl;
            } else {
                break;}
        }
        //선택한 몬스터 공격
        p.attack(monsters[target_idx]);

        // (2) monster is.Dead?
        if(allMonstersDead(monsters)){ break; }

        // (3) monster turn
        cout << "----- Monster's Turn -----" << endl;
        for(Monster& m: monsters){
            if(!m.isDead()){
                m.attack(p);
            }
        }

        if(p.isDead()){
            break;
        }

        //(4) use item
        char choice;
        if(potion_count > 0){
            cout << "Do you want to use a Item?" << "(you have " << potion_count << " potions)" << endl;
            cout << " Y / N" << endl;
            cin >> choice;
            if(choice == 'Y'){
                potion.use(p);
                potion_count -= 1;
            }
        } else{
            cout << "You already used up the potions!!!" << endl;
        }
        
        cout << "...........Next Turn"<< endl;
        count ++;
       
        cout << "====================" << endl;
        cout << endl << endl;

        
    }
    cout << "Game Over..." << endl;
    cout << "=================="<<endl;
    if(!p.isDead()){
        cout << p.getName() << "Wins!" << endl;
        cout << "You win!!" << endl;
    }else{
        cout << "You Lose!!" << endl;
    }
}

int main(){

    Player hero("태연", 100, 25);
    vector<Monster> monsters;
    monsters.push_back(Monster("Dragon", 40, 100));
    monsters.push_back(Monster("Goblin1", 5, 30));
    monsters.push_back(Monster("Goblin2", 5, 30));

    Item potion(30);

    gameSimulator(hero, monsters, potion);

    return 0;
}