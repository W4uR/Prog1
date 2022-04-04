#include "../std_lib_facilities.h"

int main(){


    int number;
    cout<< "x must be an integer"<<endl;
    while(cout << "x=" && cin >> number){
        if(cin.get()== '.') break;

        double sq_n = sqrt(number);
        if(!isnan(sq_n))
            cout << "sqrt(x)="<< sq_n << endl;
        else
            cout << "no square root" << endl;
    }
    cout<<"Invalid input"<<endl;

    return 0;
}