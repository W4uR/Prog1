#include "../std_lib_facilities.h"

istream& operator>>(istream& is, vector<double>& vec)
{
    double d;
    is >> d;
    vec.push_back(d);
    return is;
}

ostream& operator<<(ostream& os, const vector<double>& vec)
{
    for(int i = 0; i < vec.size(); ++i)
    os << vec[i] << endl;
    return os;
}

template<typename T1, typename T2>
void output_vector_pairs(const vector<T1>& v1,const vector<T2>& v2){
    
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " - " << v2[i] <<endl;
    }
}

int main(){

    vector<double> vd;


    ifstream readFile("input2.txt");
    while(!readFile.eof()){
        readFile >> vd;
    }
    readFile.close();
    cout << vd;

    vector<int> vi(vd.size());
    copy(vd.begin(),vd.end(),vi.begin());
    output_vector_pairs(vd,vi);

    int vi_sum = accumulate(vi.begin(),vi.end(),0);
    double vd_sum = accumulate(vd.begin(),vd.end(),0);

    cout << vd_sum << endl;
    //cout << vi_sum << endl;
    cout << vd_sum - (double)vi_sum << endl; // not gud

    return 0;
}