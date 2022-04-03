#include "../std_lib_facilities.h"

template<typename key, typename value>
ostream& operator<<(ostream& os, const map<key,value>& my_map)
{
    for(auto& i : my_map){
        cout << i.first << " - " << i.second << endl;
    }
    return os;
}
template<typename key, typename value>
istream& operator>>(istream& is, map<key,value>& my_map){
    key f;
    value s;
    is >> f >> s;
    my_map[f] = s;
    return is;
}

void readValues(map<string,int>& my_map, int numberOfValues){

    for(int i = 0; i<numberOfValues;i++){
        cin >> my_map;
    }
}

template<typename key, typename value>
void invert_map(map<key,value>& original_map, map<value,key>& inverted_map){
    for(auto& i : original_map){
        inverted_map[i.second] = i.first;
    }
}

int main(){

    map<string,int> msi = {
        {"egy",1},{"ketto",2},{"harom",3},{"negy",4},{"ot",5},{"hat",6},{"het",7},{"nyolc",8},{"kilenc",9}
    };
    msi["tiz"] = 10;

    cout << msi;
    msi.erase(msi.begin(),msi.end());
    readValues(msi,3);
    cout << msi;

    int sum = 0;
    for(auto& i : msi){
        sum += i.second;
    }
    cout << sum << endl;

    map<int,string> mis;
    invert_map(msi,mis);
    cout << mis;

    
    return 0;
}