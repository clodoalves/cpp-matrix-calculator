
#ifndef CPP_MATRIX_CALCULATOR_MATRIX_H
#define CPP_MATRIX_CALCULATOR_MATRIX_H

class Matrix {
private:
    float elements[100];

public:
    int numberOfRows;
    int numberOfColumns;
    Matrix ();
    Matrix (char* input);
    void Plus(Matrix anotherMatrix);
    void Minus(Matrix anotherMatrix);
    void Times(float scalarElement);
    void Times(Matrix anotherMatrix);
    void DividedBy(float scalarElement);
    int isIdentityMatrix();
    Matrix GetInverseMatrix();
    Matrix GetTransposeMatrix();
    void Print();
    void AddElement(char * element, int index);
    void GenerateMatrix();
};

#endif //CPP_MATRIX_CALCULATOR_MATRIX_H
