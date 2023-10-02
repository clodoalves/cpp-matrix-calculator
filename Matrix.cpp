
#include <iostream>
#include "Matrix.h"
#include "string.h"

using namespace std;

void Matrix::Minus(Matrix anotherMatrix)
{

}

void Matrix::Plus(Matrix* anotherMatrix)
{
	auto foo = elements;

	for (size_t i = 0; i < numberOfRows; i++)
	{
		for (size_t j = 0; j < numberOfColumns; j++)
		{
			float value = *(elements[i] + j);
			float value2 = *(anotherMatrix->elements[i] + j);
			*(elements[i] + j) = value + value2;
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
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			/*     float *line = elements[i];
				 line = new float();*/

			elements[i] = new float();
			float value;
			cout << "Insert element [" << i + 1 << "," << j + 1 << "] :" << endl;
			cin >> value;
			*(elements[i] + j) = value;

			//*(elements + j) = &value;
		}
	}
}

// Matrix::Matrix(){}
