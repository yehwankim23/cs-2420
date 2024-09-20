// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 19, 2024

#pragma once

#include <vector>

class Matrix {
private:
    // instance variable
    std::vector<std::vector<int>> mat;

public:
    // setter
    void setMatrix(std::vector<std::vector<int>> matrix);

    // getter
    std::vector<std::vector<int>> getMatrix();

    // operator +
    Matrix operator+(const Matrix& other);

    // operator -
    Matrix operator-(const Matrix& other);

    // operator *
    Matrix operator*(const Matrix& other);

    // operator ==
    bool operator==(const Matrix& other);

    // returns diagonal sum of square matrix
    float digonalSum();
};
