#include "matrix.h"

Matrix::Matrix() : _rows(3), _cols(3) {
    _data = new double*[_rows];
    for (size_t i = 0; i < _rows; ++i) {
        _data[i] = new double[_cols];
    }

    int n = 0;
    for (size_t i = 0; i < _rows; ++i) {
        for (size_t j = 0; j < _cols; ++j) {
            _data[i][j] = n++;
        }
    }
}

Matrix::Matrix(size_t rows, size_t cols) : _rows(rows), _cols(cols) {
    _data = new double*[_rows];
    for (size_t i = 0; i < _rows; ++i) {
        _data[i] = new double[_cols];
    }

    std::cout << "Enter the elements: " << std::endl;
    for (size_t i = 0; i < _rows; ++i) {
        for (size_t j = 0; j < _cols; ++j) {
            std::cin >> _data[i][j];
        }
    }
}

Matrix::Matrix(Matrix& other) : _rows{other._rows}, _cols{other._rows}{
    std::cout << "cp ctor" << std::endl;
    _data = new double*[_rows];
    for (size_t i = 0; i < _rows; ++i) {
        _data[i] = new double[_cols];
    }
}



Matrix::~Matrix() {
    for (size_t i = 0; i < _rows; ++i) {
        delete[] _data[i];
    }
    delete[] _data;
}

size_t Matrix::getRows() const {
    return _rows;
}

size_t Matrix::getCols() const {
    return _cols;
}

double Matrix::get(size_t row, size_t col) const {
    return _data[row][col];
}

void Matrix::set(size_t row, size_t col, double value) {
    _data[row][col] = value;
}

void Matrix::print() const {
    for (size_t i = 0; i < _rows; ++i) {
        for (size_t j = 0; j < _cols; ++j) {
            std::cout << _data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
