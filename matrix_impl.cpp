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

Matrix::Matrix(const Matrix& other) : _rows(other._rows), _cols(other._cols) {
    std::cout << "copy ctor" << std::endl;
    _data = new double*[_rows];
    for (size_t i = 0; i < _rows; ++i) {
        _data[i] = new double[_cols];
        for (size_t j = 0; j < _cols; ++j) {
            _data[i][j] = other._data[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& other) : _rows(other._rows), _cols(other._cols), _data(other._data) {
    std::cout << "move ctor" << std::endl;
    other._rows = 0;
    other._cols = 0;
    other._data = nullptr;
}

Matrix& Matrix::operator=(const Matrix& other) {
    std::cout << "copy assignment" << std::endl;
    if (this != &other) {
        for (size_t i = 0; i < _rows; ++i)
            delete[] _data[i];
        delete[] _data;

        _rows = other._rows;
        _cols = other._cols;
        _data = new double*[_rows];
        for (size_t i = 0; i < _rows; ++i) {
            _data[i] = new double[_cols];
            for (size_t j = 0; j < _cols; ++j)
                _data[i][j] = other._data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    std::cout << "move assignment" << std::endl;
    if (this != &other) {

        for (size_t i = 0; i < _rows; ++i)
            delete[] _data[i];
        delete[] _data;

        _rows = other._rows;
        _cols = other._cols;
        _data = other._data;

        other._rows = 0;
        other._cols = 0;
        other._data = nullptr;
    }
    return *this;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs._rows != rhs._rows || lhs._cols != rhs._cols) {
        return lhs;
    }

    Matrix result(lhs._rows, lhs._cols);
    for (size_t i = 0; i < lhs._rows; ++i) {
        for (size_t j = 0; j < lhs._cols; ++j) {
            result._data[i][j] = lhs._data[i][j] + rhs._data[i][j];
        }
    }
    return result;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
    if (lhs._rows != rhs._rows || lhs._cols != rhs._cols) {
        return lhs;
    }

    Matrix result(lhs._rows, lhs._cols);
    for (size_t i = 0; i < lhs._rows; ++i) {
        for (size_t j = 0; j < lhs._cols; ++j) {
            result._data[i][j] = lhs._data[i][j] - rhs._data[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    if (lhs._rows != rhs._cols) {
        return lhs;
    }

    Matrix result(lhs._rows, rhs._cols);
    for (size_t i = 0; i < lhs._rows; ++i) {
        for (size_t j = 0; j < lhs._cols; ++j) {
            result._data[i][j] = 0;
            for (size_t h = 0; h < result._rows; h++) {
                result._data[i][j] += lhs._data[i][h] * rhs._data[h][j];
            }
        }
    }
    return result;
}

Matrix operator*(const Matrix& lhs, double num) {
    Matrix result = lhs;
    for (size_t i = 0; i < lhs._rows; i++) {
        for (size_t j = 0; j < lhs._cols; j++) {
            result._data[i][j] = lhs._data[i][j] * num;
        }
    }
    return result;
}

Matrix operator*(double num, const Matrix& rhs) {
    return rhs * num;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        return *this;
    }

    for (size_t i = 0; i < _rows; i++) {
        for (size_t j = 0; j < _cols; j++) {
            _data[i][j] += other._data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (_rows != other._rows || _cols != other._cols) {
        return *this;
    }

    for (size_t i = 0; i < _rows; i++) {
        for (size_t j = 0; j < _cols; j++) {
            _data[i][j] -= other._data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    for (size_t i = 0; i < _rows; i++) {
        for (size_t j = 0; j < _cols; j++) {
            _data[i][j] *= other._data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(double num) {
    for (size_t i = 0; i < _rows; i++) {
        for (size_t j = 0; j < _cols; j++) {
            _data[i][j] *= num;
        }
    }
    return *this;
}

Matrix::~Matrix() {
    for (size_t i = 0; i < _rows; ++i)
        delete[] _data[i];
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
