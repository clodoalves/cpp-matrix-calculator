
#include <iostream>
#include "Matrix.h"
#include "string.h"

using namespace std;

void Matrix::Minus(Matrix anotherMatrix)
{

}

void Matrix::Plus(Matrix *anotherMatrix)
{
    for (size_t i = 0; i < numberOfRows; i++)
    {
        for (size_t j = 0; j < numberOfColumns; j++)
        {
            float value = *(*anotherMatrix->elements + j);

            //*(elements + j) = 1 + value;
        }        
    } 
}

void Matrix::Times(float scalarElement)
{

}

void Matrix::DividedBy(float scalarElement)
{

}

void Matrix::Times(Matrix anotherMatrix)
{

}

int Matrix::isIdentityMatrix()
{
    return 0;
}

Matrix Matrix::GetInverseMatrix()
{
    return Matrix();
}

Matrix Matrix::GetTransposeMatrix()
{
    return Matrix();
}

void Matrix::Print()
{

}

void Matrix::GenerateMatrix()
{
    int count = 0;

    for (int i = 1; i <= numberOfRows; i++)
    {
        for (int j = 1; j <= numberOfColumns; j++)
        {
            float value;

            cout << "Insert element [" << i <<","<< j << "] :" << endl;
            cin >> value;
            *(elements + count) = &value;
            count++;
        }
    }
}

// Matrix::Matrix(){}



