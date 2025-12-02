#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book{
    private:
        string title;
        int price;
    public:
    // Constructor
        Book(): title(""), price(0) {}
        Book(string t, int p): title(t), price(p) {}
    // Getters
        string getTitle() const { return title; }
        int getPrice() const { return price; }
    // Setters
        void setTitle(const string& t) { title = t; }
        void setPrice(int p) { price = p; }
    // Destructor
    ~Book() {}

    // Overload < operator for sorting by price
    bool operator<(const Book& other) const {
        return price < other.price;
    }
    // Print book details
    void printDetails() const {
        cout << "Title: " << title << ", Price: " << price << endl;
    }


    
};

int main(){
    int n;
    cin >> n;
    vector<book> books(n);

    cout << "Enter book title and price: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Book name: ";
        getline(cin >> ws, books[i].title);
        cout << "Book price: ";
        cin >> books[i].price;  


        
    }

    sortByPrice(books);

    cout << "Books sorted by price: " << endl;
    for(const auto& book : books){
        book.printDetails();
    }

}