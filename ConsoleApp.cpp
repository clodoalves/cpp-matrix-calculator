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

    // Matrix *secondMatrix = new Matrix();
    // cout << "Second Matrix: " << endl;
    // cout << "Insert the number of rows: " << endl;
    // cin >> secondMatrix->numberOfRows;
    // cout << "Insert the number of columns: " << endl;
    // cin >> secondMatrix->numberOfColumns;
    
    // secondMatrix->GenerateMatrix();

    // firstMatrix->Minus(secondMatrix);
    
    firstMatrix->DividedBy(10);

    firstMatrix->Print();

    system("pause");

    return 0;
}