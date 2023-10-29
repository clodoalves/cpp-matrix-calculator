const size_t N = 20;

class Matrix {

public:
    float** elements = new float* [N];
    size_t numberOfRows;
    size_t numberOfColumns;
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