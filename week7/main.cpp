#include "../std_lib_facilities.h"


template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2){

    Iter1 current = f1;
    while (current != e1)
    {
        *f2++ = *current++;
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

    int newint;

    for(int i = 0; i < myArray2.size();i++){
        myArray2[i] += 2;
    }
    for(int i = 0; i < myVector2.size();i++){
        myVector2[i] += 3;
    }
    for (auto i = myList2.begin(); i != myList2.end(); i++)
    {
        *i+=5;
    }


    cout<<"Tomb"<< endl;
    for(int i = 0; i < myArray.size();i++){
        cout << myArray[i] << "   "<< myArray2[i]<< endl;
    }
    cout<<"Vektor"<< endl;
    for(int i = 0; i < myVector.size();i++){
        cout << myVector[i] << "   "<< myVector2[i]<<endl;
    }
    cout<<"Lista"<< endl;
 
    auto i1 = myList.begin();
    auto i2 = myList2.begin();
    while(i1 != myList.end()){
        cout << *i1 << "   " << *i2 << endl;
        i1++;
        i2++;
    }
    //--- másolások
    my_copy(myArray2.begin(),myArray2.end(),myVector2.begin());
    my_copy(myList2.begin(),myList2.end(),myArray.begin());
    cout<<endl<<"----------After copy-----------"<<endl;
    cout<<"Tomb"<< endl;
    for(int i = 0; i < myArray.size();i++){
        cout << myArray[i] << "   "<< myArray2[i]<< endl;
    }
    cout<<"Vektor"<< endl;
    for(int i = 0; i < myVector.size();i++){
        cout << myVector[i] << "   "<< myVector2[i]<<endl;
    }
    cout<<"Lista"<< endl;
 
    i1 = myList.begin();
    i2 = myList2.begin();
    while(i1 != myList.end()){
        cout << *i1 << "   " << *i2 << endl;
        i1++;
        i2++;
    }

    cout<<endl<<"----------Find results-----------"<<endl;
    auto it = find (myVector.begin(), myVector.end(), 3);
    if (it == myVector.end())
    {
        cout << "Nope" << endl;
    }else{
        cout << it-myVector.begin() << endl;
    }

    list<int>::iterator itL = find (myList.begin(), myList.end(), 4);
    if (itL == myList.end())
    {
        cout << "Nope" << endl;
    }else{
        //cout << itL-myList.begin() << endl; Hát ilyet nem lehet ... :(
        int index = 0;
        while (itL != myList.begin())
        {
            index++;
            itL--;
        }
        
        cout << index << endl;
    }
}