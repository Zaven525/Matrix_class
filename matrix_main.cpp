#include "matrix.h"

int main() {
    Matrix matrix_1;
    // matrix_1.print();
    
    // std::cout << "Number of Rows: " << matrix_1.getRows() << std::endl;
    // std::cout << "Number of Cols: " << matrix_1.getCols() << std::endl;
    // std::cout << "The center element is: " << matrix_1.get(1, 1) << std::endl;

    // matrix_1.set(1, 1, 0);
    // matrix_1.print();

    Matrix matrix_2;
    // Matrix matrix_3; 
    matrix_1 += matrix_2;
    matrix_1.print();
    matrix_2.print();
    // matrix_3.print();

    
    return 0;
}