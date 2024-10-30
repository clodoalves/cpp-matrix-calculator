#include "iostream"
#include "Matrix.h"

int main()
{
    try
    {
        Matrix *firstMatrix = new Matrix();
        firstMatrix->SetMatrixDimensions();    

        Matrix *secondMatrix = new Matrix();
        secondMatrix->SetMatrixDimensions();

        firstMatrix->Plus(secondMatrix);          

        firstMatrix->DisplayMatrix();
    }
    catch(ArithmeticException ex)
    {
       std::cerr << ex.what() << endl;
    }
    catch (exception ex)
    {
        std::cerr << ex.what() << endl;
    }
    
    system("pause");

    return 0;
}