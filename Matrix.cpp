#include <iostream>
#include "Matrix.h"
#include "string.h"

using namespace std;

void Matrix::Minus(Matrix anotherMatrix)
{

}

void Matrix::Plus(Matrix* anotherMatrix)
{
    for (size_t i = 0; i < numberOfRows; i++)
    {
        for (size_t j = 0; j < numberOfColumns; j++)
        {
            float valueFirstMatrix = elements[i][j]; 
            float valueSecondMatrix = anotherMatrix->elements[i][j];
         
            elements[i][j] = valueFirstMatrix + valueSecondMatrix;
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
    for (size_t i = 0; i < numberOfRows; i++)
    {
        for (size_t j = 0; j < numberOfColumns; j++)
        {
            cout << "Element"<<"[" << i << "]" << "[" << j << "]" << "-> " << elements[i][j] << endl; 
        }        
    }
}

void Matrix::GenerateMatrix()
{
    for (size_t i = 0; i < numberOfRows; i++)
    {
        elements[i] = new float[numberOfColumns];

        for (size_t j = 0; j < numberOfColumns; j++)
        {
            float element;
            cout << "Insert element "<<"[" << i + 1 << "]" << "[" << j + 1  << "]" << endl;
            cin >> element;
            elements[i][j] = element;
        } 
    }
}