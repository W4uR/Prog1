
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
            cout << "D2 :: pvf()" << endl;
        }
};


class B2{
    public:
        virtual void pvf(){
            cout << "B2 :: pvf()"<<endl;
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
        void pvf() override{
            cout << number << endl;
        }
};

void f(B2& obj){
    obj.pvf();
}

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
    
    D2 obj4;
    
    obj4.f();
    obj4.vf();
    obj4.pvf();
    
    D21 obj5;
    D22 obj6;

    obj5.text = "D1";
    obj6.number = 22;


    // tecccenek a nevek nagyon <3
    f(obj5);
    f(obj6);
    return 0;
}

