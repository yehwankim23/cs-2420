// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 19, 2024

#pragma once

#include "Matrix.h"

#include <vector>
#include <stdexcept>

// setter
void Matrix::setMatrix(std::vector<std::vector<int>> matrix) {
    mat = matrix;
}

// getter
std::vector<std::vector<int>> Matrix::getMatrix() {
    return mat;
}

// operator +
Matrix Matrix::operator+(const Matrix& other) {
    const std::vector<std::vector<int>>& left = this->mat;
    const int left_rows = left.size();
    const int left_columns = left[0].size();

    const std::vector<std::vector<int>>& right = other.mat;
    const int right_rows = right.size();
    const int right_columns = right[0].size();

    if (left_rows != right_rows || left_columns != right_columns) {
        throw std::invalid_argument("matrix different sizes");
    }

    std::vector<std::vector<int>> result(left_rows, std::vector<int>(left_columns, 0));

    for (int row = 0; row < left_rows; row++) {
        const std::vector<int>& left_row = left[row];
        const std::vector<int>& right_row = right[row];
        std::vector<int>& result_row = result[row];

        for (int column = 0; column < left_columns; column++) {
            result_row[column] = left_row[column] + right_row[column];
        }
    }

    Matrix matrix;
    matrix.mat = result;
    return matrix;
}

// operator -
Matrix Matrix::operator-(const Matrix& other) {
    const std::vector<std::vector<int>>& left = this->mat;
    const int left_rows = left.size();
    const int left_columns = left[0].size();

    const std::vector<std::vector<int>>& right = other.mat;
    const int right_rows = right.size();
    const int right_columns = right[0].size();

    if (left_rows != right_rows || left_columns != right_columns) {
        throw std::invalid_argument("matrix different sizes");
    }

    std::vector<std::vector<int>> result(left_rows, std::vector<int>(left_columns, 0));

    for (int row = 0; row < left_rows; row++) {
        const std::vector<int>& left_row = left[row];
        const std::vector<int>& right_row = right[row];
        std::vector<int>& result_row = result[row];

        for (int column = 0; column < left_columns; column++) {
            result_row[column] = left_row[column] - right_row[column];
        }
    }

    Matrix matrix;
    matrix.mat = result;
    return matrix;
}

// operator *
Matrix Matrix::operator*(const Matrix& other) {
    const std::vector<std::vector<int>>& left = this->mat;
    const int left_rows = left.size();
    const int left_columns = left[0].size();

    const std::vector<std::vector<int>>& right = other.mat;
    const int right_rows = right.size();
    const int right_columns = right[0].size();

    if (left_columns != right_rows) {
        throw std::invalid_argument("matrix different sizes");
    }

    std::vector<std::vector<int>> result(left_rows, std::vector<int>(right_columns, 0));

    for (int row = 0; row < left_rows; row++) {
        const std::vector<int>& left_row = left[row];
        std::vector<int>& result_row = result[row];

        for (int column = 0; column < right_columns; column++) {
            for (int index = 0; index < left_columns; index++) {
                result_row[column] += left_row[index] * right[index][column];
            }
        }
    }

    Matrix matrix;
    matrix.mat = result;
    return matrix;
}

// operator ==
bool Matrix::operator==(const Matrix& other) {
    if (mat.size() != other.mat.size() && mat[0].size() != other.mat[0].size()) {
        return false;
    }

    for (int row = 0; row < mat.size(); row++) {
        for (int column = 0; column < mat[0].size(); column++) {
            if (mat[row][column] != other.mat[row][column]) {
                return false;
            }
        }
    }

    return true;
}

// returns diagonal sum of square matrix
float Matrix::digonalSum() {
    const int rows = mat.size();
    const int columns = mat[0].size();

    if (rows != columns) {
        throw std::invalid_argument("not square matrix");
    }

    int sum = 0;

    for (int index = 0; index < rows; index++) {
        sum += mat[index][index];
    }

    return sum;
}
