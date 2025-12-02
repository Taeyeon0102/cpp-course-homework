#include <iostream>
using namespace std;

class Matrix {
    private: 
        int row, col;
        int **data;
    public:
    //생성자
    Matrix(int r, int c): row(r), col(c){
        data = new int*[row];
        for(int i=0; i<row; i++){
            data[i] = new int[col];
        }
    }
    Matrix(): row(0), col(0), data(nullptr){}
    //소멸자
    ~Matrix(){
        for (int i=0; i<row; i++){
            delete [] data[i];
        }
    }
    //멤버 함수_입력, 덧셈, 뺄셈, 전치, 출력
    void input(){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin >> data[i][j];
            }
        }
    }
    Matrix add(const Matrix &B){
        Matrix result(row, col);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                result.data[i][j] = data[i][j] + B.data[i][j];
            }
        }
        return result;
    }
    Matrix subtract(const Matrix &B){
        Matrix result(row, col);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                result.data[i][j] = data[i][j] - B.data[i][j];
            }
        }
        return result;
    }
    Matrix transpose(){
        Matrix result(col, row);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
    
    void print(){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int r = 0, c = 0;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    Matrix A(r, c), B(r, c);

    cout << endl;

    cout << "Enter elements of A:" << endl;
    A.input();

    cout << "Enter elements of B:" << endl;
    B.input();

    cout << "\nMatrix A:\n"; A.print();
    cout << "Matrix B:\n"; B.print();

    cout << "A + B:\n"; A.add(B).print();
    cout << "A - B:\n"; A.subtract(B).print();
    cout << "Transpose of A:\n"; A.transpose().print();

    return 0;
}
