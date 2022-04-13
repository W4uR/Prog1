
#include "../std_lib_facilities.h"

class B1{
    public:
        virtual void vf(){
            cout << "B1 :: vf()" << endl;
        }
        void f(){
            cout << "B1 :: f()" << endl;
        }
        virtual void pvf() = 0;
};

class D1 : public B1{
    public:
        void vf() override{
            cout << "D1 :: vf()" << endl;
        }
        void pvf() override{
            cout << "D1 :: pvf()" << endl;
        }
};


class D2 : public D1{
    public:
    
        void pvf() override{
            cout << "D2 :: pvf()" << endl;
        }
     
};


class B2{
    public:
        virtual void pvf() = 0;
};

class D21 : public B2{
    public:
        string text;
        void pvf() override { 
            cout << text << endl;
        }
    
};
class D22 : public B2 {
    public:
        int number;
        void pvf() override{
            cout << number << endl;
        }
};

void f(B2& obj){
    obj.pvf();
}

int main(){

    /*
    B1 B1_base;

    B1_base.vf();
    B1_base.f();
    */

    D1 D1_from_B1;

    D1_from_B1.vf();
    D1_from_B1.f();
    D1_from_B1.pvf();
    cout << endl;

    B1& D1_in_B1 = D1_from_B1;

    D1_in_B1.vf();
    D1_in_B1.f();
    D1_in_B1.pvf();
    cout << endl;


    D2 asd;
    asd.vf();
    asd.f();
    asd.pvf();
    /*
    D2 D2_from_D1_which_is_from_B1;
    
    D2_from_D1_which_is_from_B1.f();
    D2_from_D1_which_is_from_B1.vf();
    //D2_from_D1_which_is_from_B1.pvf();
    
    D21 D21_from_B2;
    D22 D22_from_B2;

    D21_from_B2.text = "D1";
    D22_from_B2.number = 22;


    // tecccenek a nevek nagyon <3
    f(D21_from_B2);
    f(D22_from_B2);
    */
    return 0;
}

