#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix* firstMatrix = new Matrix();
    Matrix* secondMatrix = new Matrix();

    //char * input = new char();
    cout << "First Matrix: " << endl;
    cout << "Insert the number of rows: " << endl;
    cin >> firstMatrix->numberOfRows;
    cin >> firstMatrix->numberOfRows;
    cout << "Insert the number of columns: " << endl;
    cin >> firstMatrix->numberOfColumns;

    firstMatrix->GenerateMatrix();

    //cout << "Second Matrix: " << endl;
    //cout << "Insert the number of rows: " << endl;
    //cin >> secondMatrix->numberOfRows;
    //cout << "Insert the number of columns: " << endl;
    //cin >> secondMatrix->numberOfColumns;

    //cin >> input;

    //Matrix * matrix = new Matrix(input);

    delete firstMatrix;
    delete secondMatrix;

    return 0;
}