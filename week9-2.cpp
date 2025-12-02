#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player{
    private:
        string name;
        int HP;
    public:
    // Constructor
        Player(): name(""), HP(0) {}
        Player(string n, int h): name(n), HP(h) {}
    // Getters
        string getName() const { return name; }
        int getHP() const { return HP; }
    // Setters
        void setName(const string& n) { name = n; }
        void setHP(int h) { HP = h; }
    // Destructor
    ~Player() {}
};

class item{
    private:
        string itemName;
        int itemValue;
    public:
    // Constructor
        item(): itemName(""), itemValue(0) {}
        item(string in, int iv): itemName(in), itemValue(iv) {}
    // Getters
        string getItemName() const { return itemName; }
        int getItemValue() const { return itemValue; }
    // Setters
        void setItemName(const string& in) { itemName = in; }
        void setItemValue(int iv) { itemValue = iv; }
    // Destructor
    ~item() {}

    void useItem(Player& player){
        cout << "Using item(Potion/Elixir/MegaPotion): " << itemName << endl;
        player.setHP(player.getHP() + itemValue);
        cout << "Player " << player.getName() << " HP increased by " << itemValue << " to " << player.getHP() << endl;
    }
};

void main(){

    cout << "!Creating Player! " << endl;
    string playerName;
    cout << "Enter player name: ";
    getline(cin, playerName);
    Player player1(playerName, 100);



    item Potion("Potion", 10);
    item Elixir("Elixir", 20);
    item MegaPotion("MegaPotion", 30);

    cout << "Player Name: " << player1.getName() << endl;
}