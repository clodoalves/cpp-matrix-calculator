#include "Matrix.h"

void Matrix::Minus(Matrix *secondMatrix)
{
    ValidSubtraction(secondMatrix);

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

void Matrix::Plus(Matrix *secondMatrix)
{
    ValidateSum(secondMatrix);

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

Matrix *Matrix::Times(Matrix* secondMatrix)
{
    ValidateMultiplication(secondMatrix);

    Matrix *newMatrix = nullptr;

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

void Matrix::AddColumnValues(float column[], size_t indexLine)
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

void Matrix::ValidateSum(Matrix *secondMatrix)
{
    if (HasSameDimensionOf(secondMatrix))
    {
        throw ArithmeticException("To sum two matrices, their dimensions must be the same");
    }
}

void Matrix::ValidSubtraction(Matrix *secondMatrix)
{
    if (HasSameDimensionOf(secondMatrix))
    {
        throw ArithmeticException("To subtract two matrices, their dimensions must be the same");
    }
}

bool Matrix::HasSameDimensionOf(Matrix *secondMatrix)
{
    return (numberOfColumns != secondMatrix->numberOfColumns) ||
           (numberOfRows != secondMatrix->numberOfRows);
}

void Matrix::ValidateMultiplication(Matrix *secondMatrix)
{
    if (numberOfRows != secondMatrix->numberOfColumns)
    {
        throw ArithmeticException("Invalid for matrix multiplication");
    }
}