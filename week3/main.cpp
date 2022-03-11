
#include "../std_lib_facilities.h"

class B1{
    public:
        void vf(){
            cout << "B1 :: vf()" << endl;
        }
        void f(){
            cout << "B1 :: f()" << endl;
        }
         virtual void pvf(){
            cout << "B1 :: pvf()" << endl;
        }
};

class D1 : public B1{
    public:
        void vf(){
            cout << "D1 :: vf()" << endl;
        }
};

class D2 : public D1{
    public:
        void pvf(){
            cout << "D2:pvf()" << endl;
        }
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
        void pvf(){
            cout << number << endl;
        }
        void f(B2& in){
            in.pvf();
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
    
    D2 obj3;
    
    obj3.f();
    obj3.vf();
    obj3.pvf();
    
    D21 obj4;
    D22 obj5;
    B2 obj6;
    // tecccenek a nevek nagyon <3
    obj4.f();
    obj5.f(obj6);
    return 0;
}

