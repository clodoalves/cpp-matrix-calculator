#include "iostream"
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix *firstMatrix = new Matrix();

    cout << "First Matrix: " << endl;
    cout << "Insert the number of rows: " << endl;
    cin >> firstMatrix->numberOfRows;
    cout << "Insert the number of columns: " << endl;
    cin >> firstMatrix->numberOfColumns;

    firstMatrix->GenerateMatrix();

    delete firstMatrix;

    system("pause");

    return 0;
}