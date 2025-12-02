#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {

    ifstream in("input.txt");
    ofstream out("result.txt");

    if (!in) {
        cout << "파일오픈 실패";
        return 0;
    }
    string line, word;
    int count = 0;

    while (getline(in, line)) {
        stringstream ss(line);
        while (ss >> word) {
            count++;
        }
    }

    out << "Word Count: " << count;

    in.close();
    out.close();

}
