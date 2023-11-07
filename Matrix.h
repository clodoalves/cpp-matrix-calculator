const size_t MAXIMUM_DIMENSION = 20;

class Matrix {

public:
    float** elements = new float* [MAXIMUM_DIMENSION];
    size_t numberOfRows;
    size_t numberOfColumns;
    void Plus(Matrix* secondMatrix);
    void Minus(Matrix* secondMatrix);
    void Times(float scalarElement);
    Matrix* Times(Matrix* secondMatrix);
    void DividedBy(float scalarElement);
    int IsIdentityMatrix();
    Matrix GetInverseMatrix();
    Matrix GetTransposeMatrix();
    void Print();
    void GenerateMatrix();
    void AddColumnValues(float column [], size_t indexColumn);
};