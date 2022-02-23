
#include "../std_lib_facilities.h"

class B1{
    public:
        void vf(){
            cout << "B1 :: vf()" << endl;
        }
        void f(){
            cout << "B1 :: f()" << endl;
        }
};

class D1 : public B1{
    public:
        void vf(){
            cout << "D1 :: vf()" << endl;
        }
};

int main(){

    B1 obj;

    obj.vf();
    obj.f();

    D1 obj2;

    obj2.vf();
    obj2.f();

    B1& obj3 = obj2;

    obj3.vf();
    obj.f();


    return 0;
}

