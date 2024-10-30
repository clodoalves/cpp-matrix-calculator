#include <iostream>
#include "string.h"
#include "CustomException.cpp"
#include "vector" 
#include <iomanip>

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
    int IsIdentityMatrix();
    Matrix GetInverseMatrix();
    Matrix* GetTransposeMatrix();
    void Print();
    void SetMatrixDimensions();
    void DisplayMatrix();

private:
    void GenerateMatrix(bool defaultValue = false);
    void AddNewRow(std::vector<float> vec, size_t indexColumn);
    void ValidateSum(Matrix* secondMatrix);
    void ValidateSubtraction(Matrix* secondMatrix);
    void ValidateMultiplication(Matrix* secondMatrix);
    bool HasSameDimensionOf(Matrix* secondMatrix);
};