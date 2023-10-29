const size_t MAXIMUM_DIMENSION = 20;

class Matrix {

public:
    float** elements = new float* [MAXIMUM_DIMENSION];
    size_t numberOfRows;
    size_t numberOfColumns;
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