#include <iostream>

class Matrix{

public:
    Matrix();
    Matrix(size_t, size_t);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix(Matrix&& other);
    Matrix& operator=(Matrix&& other) noexcept;
    friend Matrix operator+(const Matrix&, const Matrix&);
    friend Matrix operator-(const Matrix&, const Matrix&);
    friend Matrix operator*(const Matrix&, const Matrix&);
    friend Matrix operator*(const Matrix&, double);
    friend Matrix operator*(double, const Matrix&);

    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(double);

    
    
    ~Matrix();
    size_t getRows() const; //Returns the number of rows.
    size_t getCols() const; //Returns the number of columns.
    double get(size_t, size_t) const; //Gets the value at a specific position with bounds checking.
    void set(size_t row, size_t col, double value); //Sets the value at a specific position.
    void print() const; //Prints the matrix to the console.

private:
    size_t _rows; // Number of rows in the matrix.
    size_t _cols; // Number of columns in the matrix.
    double** _data; // Pointer to a dynamically allocated 2D array to store 
};