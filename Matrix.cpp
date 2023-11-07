#include <iostream>
#include "Matrix.h"
#include "string.h"

using namespace std;

void Matrix::Minus(Matrix* secondMatrix)
{
    for (size_t i = 0; i < numberOfRows; i++)
    {
        for (size_t j = 0; j < numberOfColumns; j++)
        {
            float valueFirstMatrix = elements[i][j];
            float valueSecondMatrix = secondMatrix->elements[i][j];

            elements[i][j] = valueFirstMatrix - valueSecondMatrix;
        }
    }
}

void Matrix::Plus(Matrix* secondMatrix)
{
    for (size_t i = 0; i < numberOfRows; i++)
    {
        for (size_t j = 0; j < numberOfColumns; j++)
        {
            float valueFirstMatrix = elements[i][j];
            float valueSecondMatrix = secondMatrix->elements[i][j];

            elements[i][j] = valueFirstMatrix + valueSecondMatrix;
        }
    }
}

void Matrix::Times(float scalarElement)
{
    for (size_t i = 0; i < numberOfRows; i++)
    {
        for (size_t j = 0; j < numberOfColumns; j++)
        {
            elements[i][j] *= scalarElement;
        }
    }
}

void Matrix::DividedBy(float scalarElement)
{
    for (size_t i = 0; i < numberOfRows; i++)
    {
        for (size_t j = 0; j < numberOfColumns; j++)
        {
            elements[i][j] /= scalarElement;
        }
    }
}

Matrix* Matrix::Times(Matrix* secondMatrix)
{
    Matrix* newMatrix = nullptr;

    if (numberOfRows != secondMatrix->numberOfColumns)
    {
        cout << "Invalid for matrix multiplication" << endl;

        return newMatrix;
    }

    newMatrix = new Matrix();

    newMatrix->numberOfRows = numberOfRows;
    newMatrix->numberOfColumns = secondMatrix->numberOfColumns;

    size_t indexRowNewMatrix = 0;
    float newLine[newMatrix->numberOfRows];

    for (size_t indexRowFirstMatrix = 0; indexRowFirstMatrix < numberOfRows; indexRowFirstMatrix++)
    {
        float elementFirstMatrix = 0;
        float elementSecondMatrix = 0;
        float elementNewMatrix = 0;
        size_t indexRowSecondMatrix = 0; 

        for (size_t indexColumnFirstMatrix = 0; indexColumnFirstMatrix < numberOfColumns; indexColumnFirstMatrix++)
        {
            elementFirstMatrix = elements[indexRowFirstMatrix][indexColumnFirstMatrix];

            for (size_t indexColumnSecondMatrix = 0; indexColumnSecondMatrix < secondMatrix->numberOfColumns; indexColumnSecondMatrix++)
            {
                elementSecondMatrix = secondMatrix->elements[indexRowSecondMatrix][indexColumnSecondMatrix];
                float sum = elementFirstMatrix * elementSecondMatrix;
                newLine[indexColumnSecondMatrix] = newLine[indexColumnSecondMatrix] + sum;
            }

            indexRowSecondMatrix++;
        } 
        
        newMatrix->AddColumnValues(newLine, indexRowNewMatrix);
        std::fill(newLine, newLine + indexRowSecondMatrix, 0); 
       
        indexRowNewMatrix++;
    }

    return newMatrix;
}

void Matrix::AddColumnValues(float column [], size_t indexLine)
{
    elements[indexLine] = new float[numberOfColumns];
     
    for (size_t i = 0; i < numberOfColumns; i++)
    {
        elements[indexLine][i] = column[i];
    }
}

int Matrix::IsIdentityMatrix()
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
            cout << "Element"
                 << "[" << i << "]"
                 << "[" << j << "]"
                 << "-> " << elements[i][j] << endl;
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
            cout << "Insert element "
                 << "[" << i + 1 << "]"
                 << "[" << j + 1 << "]" << endl;
            cin >> element;
            elements[i][j] = element;
        }
    }
}