#include "exception"

using namespace std;

class ArithmeticException : public std::exception
{

private:
char* message;

public:
    ArithmeticException(char* msg) : message(msg){}
    char* what()
    {
        return message;
    }
};