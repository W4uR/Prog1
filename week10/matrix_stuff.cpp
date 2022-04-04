#include "../std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"

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

    string cell = to_string(m.dim2()*m.dim1()*10);

    for(int i = 0; i < m.dim1();i++){

        cout << "| ";
        for(int j = 0; j < m.dim2();j++){
            
            cout << setw(cell.size()) << m(i,j);
        }
        cout << " |"<< endl;
    }

}

int main(){
/*
    Matrix<double> mat(10);

    read_values_to_matrix(mat);
    cout << mat << endl;
*/
    int n,m;
    cout << "\nEnter n: "; cin >> n;
    cout << "\nEnter m: "; cin >> m;

    Matrix<int,2> table(n,m); 
    matrix_into_multiplication_table(table);
    nice_output(table);
    

    return 0;
}
