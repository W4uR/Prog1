#include "../std_lib_facilities.h"


template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (Iter1 p = f1; p != e1; p++){

        *f2++ = *p;
    }
    return f2;
}

int main(){

    array<int,10> myArray = {0,1,2,3,4,5,6,7,8,9};
    vector<int> myVector = {0,1,2,3,4,5,6,7,8,9};
    list<int> myList = {0,1,2,3,4,5,6,7,8,9};

    // Masolasok
    array<int,10> myArray2 = myArray;
    vector<int> myVector2 = myVector;
    list<int> myList2 = myList;

    
    for(int i = 0; i < myArray2.size();i++){
        myArray2[i] += 2;
    }
    for(int i = 0; i < myVector2.size();i++){
        myVector2[i] += 3;
    }
    for (list<int>::iterator i = myList2.begin(); i != myList2.end(); i++)
    {
        *i+=5;
    }
    //---


    cout<<"Tomb"<< endl;
    for(int i = 0; i < myArray.size();i++){
        cout << myArray[i] << "   "<< myArray2[i]<< endl;
    }
    cout<<"Vektor"<< endl;
    for(int i = 0; i < myVector.size();i++){
        cout << myVector[i] << "   "<< myVector2[i]<<endl;
    }
    cout<<"Lista"<< endl;
    /*
    for(auto const& i : myList){
        cout << i << endl;
    }
    */
    list<int>::iterator i1=myList.begin();
    list<int>::iterator i2=myList2.begin();
    while(i1 != myList.end()){
        cout << *i1 << "   " << *i2 << endl;
        i1++;
        i2++;
    }
    
}