
#include <iostream>
#include "Matrix.h"
#include "string.h"

using namespace std;

int getCharNumberOccurrence(char *input, char character)
{
    int numberOccurrence = 0;

    while(*input != '\0')
    {
        if (*input == character)
            numberOccurrence++;

        input++;
    }

    return numberOccurrence;
}

void Matrix::Minus(Matrix anotherMatrix)
{

}

void Matrix::Plus(Matrix anotherMatrix)
{

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
            elements[count] = value;
            count++;
        }
    }
}

Matrix::Matrix(){}

Matrix::Matrix(char *input)
{
    int splitCharNumberOccurrence = getCharNumberOccurrence(input, ';');

    int qtdRows = splitCharNumberOccurrence + 1;
    int qtdCols = (strlen(input) - splitCharNumberOccurrence)/qtdRows;

    std::cout << "Qtd rows: " << qtdRows << std::endl;
    std::cout << "Qtd columns: " << qtdCols << std::endl;

    for (int i = 0; i < qtdRows * qtdCols; ++i)
    {
        AddElement(&input[i], i);
    }
}

void Matrix::AddElement(char* element, int index)
{
    std::string fs(element);
    float f=std::stof(fs);
    elements[index] = f;
}