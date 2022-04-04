#include "../std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

//Based on MatrixIO.h
template<class T>
ostream& operator<<(ostream& os, const Matrix<T,3>& m)
{
    os << "{\n";

    for (Index i = 0; i<m.dim2(); ++i)
        os << m[i] << '\n';

    os << '}';
    return os;
}

int main(){

    cout << "the size of char is: " << sizeof(char) << endl;
    cout << "the size of short is: " << sizeof(short) << endl;
    cout << "the size of int is: " <<  sizeof(int) << endl;
    cout << "the size of long is: " <<  sizeof(long) << endl;
    cout << "the size of float is: " <<  sizeof(float) << endl;
    cout << "the size of double is: " <<  sizeof(double) << endl;
    cout << "the size of int* is: " <<  sizeof(int*) << endl;
    cout << "the size of double* is: " <<  sizeof(double*) << endl;

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    cout << "the size of Matrix 'a' is: " << sizeof(a) << endl;
    cout << "the size of Matrix 'b' is: " << sizeof(b) << endl;
    cout << "the size of Matrix 'c' is: " << sizeof(c) << endl;
    cout << "the size of Matrix 'd' is: " << sizeof(d) << endl;
    cout << "the size of Matrix 'e' is: " << sizeof(e) << endl;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;


    return 0;
}