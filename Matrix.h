#include <iostream>
#include "string.h"
#include "CustomException.cpp"

using namespace std;

const size_t MAXIMUM_DIMENSION = 20;

class Matrix {

public:
    float** elements = new float* [MAXIMUM_DIMENSION];
    size_t numberOfRows;
    size_t numberOfColumns;
    void Plus(Matrix* secondMatrix);
    void Minus(Matrix* secondMatrix);
    void Times(float scalarElement);
    Matrix* Times(Matrix* secondMatrix);
    void DividedBy(float scalarElement);
    int IsIdentityMatrix();
    Matrix GetInverseMatrix();
    Matrix GetTransposeMatrix();
    void Print();
    void GenerateMatrix();

private:
    void AddColumnValues(float column [], size_t indexColumn);
    void ValidateSum(Matrix* secondMatrix);
    void ValidSubtraction(Matrix* secondMatrix);
    void ValidateMultiplication(Matrix* secondMatrix);
    bool HasSameDimensionOf(Matrix* secondMatrix);
};