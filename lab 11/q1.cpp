#include <iostream>
#include <exception>
#include <sstream>

class DimensionMismatchException : public std::exception {
private:
    std::string message;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        std::ostringstream oss;
        oss << "DimensionMismatchException - Matrices must have same dimensions (" 
            << r1 << "x" << c1 << " vs " << r2 << "x" << c2 << ")!";
        message = oss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols]{};
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void setValue(int r, int c, T value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = value;
        }
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    try {
        Matrix<int> A(2, 2), B(3, 3);
        Matrix<int> C = A + B; 
    } catch (const DimensionMismatchException& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
