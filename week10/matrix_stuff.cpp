#include "../std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>

using namespace Numeric_lib;


void read_values_to_matrix(Matrix<double>& m){


    for(int i = 0; i<m.dim1();++i){
        cin >> m(i);
    }

}


void matrix_into_multiplication_table(Matrix<int,2>& m){

    cout << m.dim1() << " * " << m.dim2()<<endl;
    for(int i = 0; i < m.dim1();i++){

        for(int j = 0; j < m.dim2();j++){
            m(i,j) = i*j;

        }
    }
}

void nice_output(const Matrix<int,2>& m){

    string cell = to_string(m.dim2()*m.dim1()*10); // *10 for padding

    for(int i = 0; i < m.dim1();i++){

        cout << "| ";
        for(int j = 0; j < m.dim2();j++){
            
            cout << setw(cell.size()) << m(i,j);
        }
        cout << " |"<< endl;
    }

}

complex<double> complex_sum(const Matrix<complex<double>> &mat){
    complex<double> sum = 0;
    for(int i = 0; i<mat.dim1();++i){
        sum+=mat(i);

    }
    return sum;
}


int main(){
/*
    Matrix<double> mat(10);

    read_values_to_matrix(mat);
    cout << mat << endl;
*/
    // 6)
    int n,m;
    cout << "\nEnter n: "; cin >> n;
    cout << "\nEnter m: "; cin >> m;

    Matrix<int,2> table(n,m);
    matrix_into_multiplication_table(table);
    nice_output(table);


    //7
    cout << "Complex format is: (x,i) where 'x' is the real and 'i' is the imaginary component."<< endl;
    cout << "Or just write x ..." << endl;
    cout << "Enter 10 complex numbers to get their sum: " << endl;
    Matrix<complex<double>> m_c (3);

    for(int i = 0;i<m_c.size();++i){

        cin >> m_c[i];
    }
    cout << "Sum of values: " << complex_sum(m_c) << endl;
    
    //8
    cout << endl;
    cout << "Enter six values: " << endl;
    Matrix<int,2> ms(2,3);
    for(int i = 0;i< ms.dim1();++i){
        for(int j = 0;j<ms.dim2();++j){
            cin >> ms[i][j];
        }
    }
    cout << endl;
    cout << ms << endl;

    return 0;
}
