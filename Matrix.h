
class Matrix {
// private:
//     float *elements[50];

public:
    float *elements[50];
    int numberOfRows;
    int numberOfColumns;
    // Matrix ();
    void Plus(Matrix *anotherMatrix);
    void Minus(Matrix anotherMatrix);
    void Times(float scalarElement);
    void Times(Matrix anotherMatrix);
    void DividedBy(float scalarElement);
    int isIdentityMatrix();
    Matrix GetInverseMatrix();
    Matrix GetTransposeMatrix();
    void Print();
    void GenerateMatrix();
};