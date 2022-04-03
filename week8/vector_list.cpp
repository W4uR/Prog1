#include "../std_lib_facilities.h"


struct Item{
    string name;
    int iid;
    double value;
    Item(){}
    Item(string _name, int _iid, double _value){
        name =_name;
        iid = _iid;
        value = _value;
    }
};

struct Cmp_by_name{
    bool operator()(const Item& a, const Item& b){
        return (a.name < b.name);
    }
};

struct Cmp_by_iid {
bool operator()(const Item& a, const Item& b) const
    { return a.iid < b.iid; }
};

struct Cmp_by_value {
bool operator()(const Item& a, const Item& b) const
    { return a.value > b.value; }
};

istream& operator>>(istream& is, Item &_item)
{
    string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    _item = {name,iid,value};
    return is;
}


ostream& operator<<(ostream& os, const vector<Item>& itemVec)
{
    for(int i = 0; i < itemVec.size(); ++i)
    os << itemVec[i].name<< " - " << itemVec[i].iid << " - " << itemVec[i].value << endl;
    return os;
}

ostream& operator<<(ostream& os, const list<Item>& itemList)
{
    for(auto i = itemList.begin(); i != itemList.end(); ++i)
    os << (*i).name<< " - " << (*i).iid << " - " << (*i).value << endl;
    return os;
}


int main(){
    
    //vector<Item> vi; cout << "Vektor\n";
    list<Item> vi;    cout << "Lista\n";

    ifstream readFile("input.txt");
    
    Item tmpItem;
    while(readFile >> tmpItem){
        vi.push_back(tmpItem);
    }    
    readFile.close();
    cout << vi << endl << endl;


#pragma region Lista

    cout << "Sort by name" << endl;
    vi.sort(Cmp_by_name());
    cout << vi << endl << endl;

    cout << "Sort by iid" << endl;
    vi.sort([](const Item& a, const Item& b){
        return a.iid < b.iid;
    });
    cout << vi << endl << endl;

    cout << "Sort by value" << endl;
    vi.sort(Cmp_by_value());
    cout << vi << endl << endl;

    auto iterator = vi.begin();
    iterator++;

    vi.insert(iterator,Item("horse shoe",99,12.34));
    vi.insert(iterator,Item("Canon S400",9988,499.95));
    cout << vi << endl << endl;
    //Remove by name
    vi.erase(find_if(vi.begin(),vi.end(),
    [](const Item&a){
        return a.name == "Alma";
    }));
    vi.erase(find_if(vi.begin(),vi.end(),
    [](const Item&a){
        return a.name == "Barack";
    }));
    cout << vi << endl << endl;
    //Remove by iid
    vi.erase(find_if(vi.begin(),vi.end(),
    [](const Item&a){
        return a.iid == 99;
    }));
    vi.erase(find_if(vi.begin(),vi.end(),
    [](const Item&a){
        return a.iid == 9988;
    }));
    cout << vi << endl << endl;
#pragma endregion Lista
/*
#pragma region Vektor

    cout << "Sort by name" << endl;
    sort(vi.begin(), vi.end(), Cmp_by_name());
    cout << vi << endl << endl;

    cout << "Sort by iid" << endl;
    sort(vi.begin(), vi.end(), Cmp_by_iid());
    cout << vi << endl << endl;

    cout << "Sort by value" << endl;
    //With lambda
    sort(vi.begin(), vi.end(),
        [](const Item& a, const Item& b){
            return a.value > b.value;
        });
    cout << vi << endl << endl;

    
    vi.insert(vi.begin(),Item("horse shoe",99,12.34));
    vi.insert(vi.begin()+2,Item("Canon S400",9988,499.95));

    //Remove by name
    vi.erase(find_if(vi.begin(),vi.end(),
    [](const Item&a){
        return a.name == "Alma";
    }));
    vi.erase(find_if(vi.begin(),vi.end(),
    [](const Item&a){
        return a.name == "Barack";
    }));
    cout << vi << endl << endl;
    //Remove by iid

    vi.erase(find_if(vi.begin(),vi.end(),
    [](const Item&a){
        return a.iid == 99;
    }));
    vi.erase(find_if(vi.begin(),vi.end(),
    [](const Item&a){
        return a.iid == 9988;
    }));

    cout << vi << endl << endl;

#pragma endregion Vektor
*/
    return 0;
}