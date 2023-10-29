#include <iostream>
#include "Matrix.h"
#include "string.h"

using namespace std;

void Matrix::Minus(Matrix anotherMatrix)
{

}

void Matrix::Plus(Matrix *anotherMatrix)
{
    // for (size_t i = 0; i < numberOfRows; i++)
    // {
    //     for (size_t j = 0; j < numberOfColumns; j++)
    //     {
    //         float value = *(*anotherMatrix->elements + j);

    //         //*(elements + j) = 1 + value;
    //     }        
    // } 
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
    for (size_t i = 0; i < numberOfRows; i++)
    {
        elements[i] = new float[numberOfColumns];

        for (size_t j = 0; j < numberOfColumns; i++)
        {
            float element;
            cout << "Insert "<<"[" << i << "]" << "[" << j  << "]" << "element: ";
            cin >> element;
            elements[i][j] = element;
        } 
    }
}

// Matrix::Matrix()
// {
//     for (size_t i = 0; i < N; i++)
//     {
//         elements[i] = new float[N];
//     }
// }