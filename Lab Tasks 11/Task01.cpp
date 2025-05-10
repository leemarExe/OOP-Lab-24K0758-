#include <iostream>
#include<string>
#include <stdexcept>
using namespace std;

class DimensionException : public exception {
    string msg;
public:
    DimensionException(int r1,int c1,int r2,int c2)  {
        msg = "Mismatch Dimension of matrix 1 " + to_string(r1) + "x" + to_string(c1)+" and matrix 2 " + to_string(r2) + "x" + to_string(c2);
    }
    string what(){
        return msg;
    }
};

template <typename T>
class Matrix {
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c, T d[][3]) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = d[i][j];
            }
        }
    }
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols]();
    }
    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols){
            throw DimensionException(rows,cols,other.rows,other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int Matrix1[2][3] = {{1, 2, 3},{4, 5, 6}};
    int Matrix2[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

    try {
        Matrix<int> A(2, 3, Matrix1);
        Matrix<int> B(3, 3, Matrix2); 
        Matrix<int> C = A + B;
        C.print();
    } catch (DimensionException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}