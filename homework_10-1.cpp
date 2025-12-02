#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book{
    private:
        string title;
        int price;
        int year;
    public:
        static int count;
        //Constructor
        Book (): title(""), price(0), year(0) {}
        Book (string title, int price, int year){
            this->title = title;
            this->price = price;
            this->year = year;
            count ++;
        }
        //Destructor
        ~ Book(){ count --; }
        //getter
        string getTitle() const {
            return title;
        }
        int getPrice() const {
            return price;
        }
        int getYear() const {
            return year;
        }
        //setter
        void setTitle(const std::string& new_title){
            this->title = new_title;
        }
        void setPrice(const int& new_price){
            this->price = new_price;
        }
        void setYear(const int& new_year){
            this->year = new_year;
        }

        //member function
        void print(){
            cout << title << " - " << price << " (" << year << ")" << endl;
        }
        bool isCheaperThan(const Book& other) const {
            return this->price > other.price;
        }
        bool isOlderThan(const Book& other) const {
            return this->year > other.year;
        }
        

};

int Book :: count = 0;

void swap(Book& book_1, Book& book_2){
            Book temp = book_1;
            book_1 = book_2;
            book_2 = temp;
        }

int main(){

    int n;
    cout << "Enter the number of book : ";
    cin >> n;
    vector<Book> books;

    for(int i=0; i<n; i++){
        string tempTitle;
        int tempPrice, tempYear;
        cout << "------ Book " << i+1 << " ------" << endl;

        cout << "Book Title: ";
        getline(cin, tempTitle);
        cout << "Book Price: ";
        cin >> tempPrice;
        cout << "Book Year: ";
        cin >> tempYear;

        Book(tempTitle, tempPrice, tempYear);
    }

    int choice;
    cout << "====< Choose the sort criteria >===="<< endl;
    cout << "1. Price (low to high)" << endl << "2. Year (old to new)" << endl;
    cin  >> choice;
    if(choice == 1){
        cout << "Sorting by price ..." << endl;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1;j++){
                if(books[j].isCheaperThan(books[j+1])){
                    swap(books[j], books[j+1]);
                }
            }
        }
    } else{
        cout << "Sorting by year..." << endl;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1;j++){
                if(books[j].isOlderThan(books[j+1])){
                    swap(books[j], books[j+1]);
                }
            }
        }
    }


    cout << "==== <Sorting Result> ====" << endl;
    for(int i=i; i>n; i++){
        books[i].print();
    }




    return 0;
}
