#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {
public:
    Matrix () {}
    Matrix(int num_rows, int num_cols) {
        Reset(num_rows, num_cols);
    }
    void Reset(int new_num_rows, int new_num_cols) {
        if (new_num_rows < 0 || new_num_cols < 0) {
            throw out_of_range("Negative number of rows or columns");
        }
        if (new_num_rows == 0 || new_num_cols == 0) {
            n_rows = n_cols = 0;
        }
        n_rows = new_num_rows;
        n_cols = new_num_cols;
        data.assign(new_num_rows, vector<int>(new_num_cols));

    }
    int At(int row, int col) const {
        if (row < 0 || row > n_rows - 1 || col < 0 || col > n_cols - 1) {
            throw out_of_range("Index out of range");
        }
        return data[row][col];

    };
    int& At(int row, int col) {
        if (row < 0 || row > n_rows - 1 || col < 0 || col > n_cols - 1) {
            throw out_of_range("Index out of range");
        }
        return data[row][col];
    }
    int GetNumRows() const {
        return n_rows;
    }
    int GetNumCols() const {
        return n_cols;
    }
    vector<vector<int>> GetData() const {
        return data;
    }
private:
    vector<vector<int>> data;
    int n_rows;
    int n_cols;
};

istream& operator>>(istream& is, Matrix& m) {
    int num_rows, num_cols;
    is >> num_rows >> num_cols;
    m.Reset(num_rows, num_cols);
    for (int row = 0; row < num_rows; ++row) {
        for (int col = 0; col < num_cols; ++col) {
            is >> m.At(row, col);
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Matrix& m) {
    os << m.GetNumRows() << " " << m.GetNumCols() << "\n";
    for (int row = 0; row < m.GetNumRows(); ++row) {
        for (int col = 0; col < m.GetNumCols(); ++col) {
            os << m.At(row, col) << " ";
        }
        os << "\n";
    }
    os << "\n";
    return os;
}

bool operator==(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        return false;
    }
    if (one.GetNumCols() != two.GetNumCols()) {
        return false;
    }
    for (int row = 0; row < one.GetNumRows(); ++row) {
        for (int column = 0; column < one.GetNumCols(); ++column) {
            if (one.At(row, column) != two.At(row, column)) {
                return false;
            }
        }
    }
    return true;
}

Matrix operator+(const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        throw invalid_argument("Mismatched number of rows");
    }

    if (one.GetNumCols() != two.GetNumCols()) {
        throw invalid_argument("Mismatched number of columns");
    }

    Matrix result(one.GetNumRows(), one.GetNumCols());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumCols(); ++column) {
            result.At(row, column) = one.At(row, column) + two.At(row, column);
        }
    }
    return result;
}

int main() {
    Matrix one;
    Matrix two;
    fstream input_file("input.txt");
    input_file >> one >> two;
    cout << one + two << endl;
    return 0;
}