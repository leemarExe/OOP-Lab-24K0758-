#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int a, b, c, d;

public:
    Matrix2x2(int w = 0, int x = 0, int y = 0, int z = 0) : a(w), b(x), c(y), d(z) {}

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2(a + other.a, b + other.b, c + other.c, d + other.d);
    }

    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(a - other.a, b - other.b, c - other.c, d - other.d);
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2(
            a * other.a + b * other.c,
            a * other.b + b * other.d,
            c * other.a + d * other.c,
            c * other.b + d * other.d
        );
    }

    friend int determinant(const Matrix2x2& m);
    friend class MatrixHelper;
    friend ostream& operator<<(ostream& os, const Matrix2x2& m);
};

class MatrixHelper {
public:
    void updateElement(Matrix2x2& m, int row, int col, int value) {
        if (row == 0 && col == 0) m.a = value;
        else if (row == 0 && col == 1) m.b = value;
        else if (row == 1 && col == 0) m.c = value;
        else if (row == 1 && col == 1) m.d = value;
    }
};

int determinant(const Matrix2x2& m) {
    return m.a * m.d - m.b * m.c;
}

ostream& operator<<(ostream& os, const Matrix2x2& m) {
    os << "[" << m.a << " " << m.b << "]\n";
    os << "[" << m.c << " " << m.d << "]";
    return os;
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:\n" << m1 << "\n\n";
    cout << "Matrix 2:\n" << m2 << "\n\n";

    Matrix2x2 sum = m1 + m2;
    cout << "Sum:\n" << sum << "\n\n";

    Matrix2x2 diff = m1 - m2;
    cout << "Difference:\n" << diff << "\n\n";

    Matrix2x2 product = m1 * m2;
    cout << "Product:\n" << product << "\n\n";

    cout << "Determinant of m1: " << determinant(m1) << "\n\n";

    MatrixHelper helper;
    helper.updateElement(m1, 0, 1, 10);
    cout << "Updated m1:\n" << m1 << "\n";

    return 0;
}