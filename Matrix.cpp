#include "Matrix.h"

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

void Matrix::Minus(Matrix *secondMatrix)
{
    ValidateSubtraction(secondMatrix);

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

Matrix *Matrix::Times(Matrix *secondMatrix)
{
    ValidateMultiplication(secondMatrix);

    Matrix *newMatrix = nullptr;

    newMatrix = new Matrix();
    newMatrix->numberOfRows = numberOfRows;
    newMatrix->numberOfColumns = secondMatrix->numberOfColumns;

    for (size_t indexRowFirstMatrix = 0; indexRowFirstMatrix < numberOfRows; indexRowFirstMatrix++)
    {
        std::vector<float> newLine;
        size_t indexRowSecondMatrix = 0;

        for (size_t indexColumnFirstMatrix = 0; indexColumnFirstMatrix < numberOfColumns; indexColumnFirstMatrix++)
        {
            float elementFirstMatrix = elements[indexRowFirstMatrix][indexColumnFirstMatrix];

            for (size_t indexColumnSecondMatrix = 0; indexColumnSecondMatrix < secondMatrix->numberOfColumns; indexColumnSecondMatrix++)
            {
                float elementSecondMatrix = secondMatrix->elements[indexColumnFirstMatrix][indexColumnSecondMatrix];

                float multiplication = elementFirstMatrix * elementSecondMatrix;

                if (indexColumnSecondMatrix < newLine.size())
                {
                    newLine.at(indexColumnSecondMatrix) += multiplication;
                }
                else
                {
                    newLine.push_back(multiplication);
                }
            }
        }

        newMatrix->AddNewRow(newLine, indexRowFirstMatrix);
    }

    return newMatrix;
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

int Matrix::IsIdentityMatrix()
{
    return 0;
}

void Matrix::AddNewRow(std::vector<float> column, size_t indexLine)
{
    elements[indexLine] = new float[numberOfColumns];

    for (size_t i = 0; i < numberOfColumns; i++)
    {
        elements[indexLine][i] = column[i];
    }
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
                 << "[" << i + 1 << "]"
                 << "[" << j + 1 << "]"
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
    if (!HasSameDimensionOf(secondMatrix))
    {
        throw ArithmeticException("To sum two matrices, their dimensions must be the same");
    }
}

void Matrix::ValidateSubtraction(Matrix *secondMatrix)
{
    if (!HasSameDimensionOf(secondMatrix))
    {
        throw ArithmeticException("To subtract two matrices, their dimensions must be the same");
    }
}

bool Matrix::HasSameDimensionOf(Matrix *secondMatrix)
{
    return (numberOfColumns == secondMatrix->numberOfColumns) &&
           (numberOfRows == secondMatrix->numberOfRows);
}

void Matrix::ValidateMultiplication(Matrix *secondMatrix)
{
    if (numberOfColumns != secondMatrix->numberOfRows)
    {
        throw ArithmeticException("Invalid for matrix multiplication");
    }
}