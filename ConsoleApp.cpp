#include "iostream"
#include "Matrix.h"

using namespace std;

int main()
{
    try
    {
        Matrix *firstMatrix = new Matrix();
        cout << "First Matrix: " << endl;
        cout << "Insert the number of rows: " << endl;
        cin >> firstMatrix->numberOfRows;
        cout << "Insert the number of columns: " << endl;
        cin >> firstMatrix->numberOfColumns;

        firstMatrix->GenerateMatrix();

        auto newMatrix = firstMatrix->GetTransposeMatrix();

        newMatrix->Print();        
    }
    catch(ArithmeticException ex)
    {
       std::cerr << ex.what() << '\n';
    }
    catch (exception ex)
    {
        std::cerr << ex.what() << '\n';
    }
    
    system("pause");

    return 0;
}