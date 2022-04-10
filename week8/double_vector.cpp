#include "../std_lib_facilities.h"

ostream& operator<<(ostream& os, const vector<double>& vec)
{
    for(int i = 0; i < vec.size(); ++i)
    os << vec[i] << endl;
    return os;
}

template<typename T1, typename T2>
void output_vector_pairs(const vector<T1>& v1,const vector<T2>& v2){
    for(int i = 0; i < v1.size(); i++){
        cout <<i+1<<"\t" <<setw(6)<<v1[i] << "\t-" << setw(6)<<v2[i] <<endl;
    }
}

// az accumulate-el "nem mukodott" a vd. A decimal elveszett
template<typename T>
T my_sum(const vector<T>& _vector){
    T sum = T();

    for(auto & i : _vector){
        sum += i;
    }

    return sum;
}

int main(){

    vector<double> vd;

    ifstream readFile("input2.txt");
    double value;
    readFile >> value;
    while(!readFile.eof()){
        vd.push_back(value);
        readFile >> value;
    }
    readFile.close();
    cout << vd;

    vector<int> vi(vd.size());
    copy(vd.begin(),vd.end(),vi.begin());
    output_vector_pairs(vd,vi);

    int vi_sum = my_sum(vi);
    double vd_sum = my_sum(vd);

    cout << vd_sum << endl;
    cout << vi_sum << endl;
    cout << vd_sum - vi_sum << endl<<endl;

    reverse(vd.begin(),vd.end());
    cout << vd;
    double mean_val = vd_sum / vd.size();
    cout << "mean value of vd is: " << mean_val << endl;

    vector<double> vd2;
    copy_if(vd.begin(),vd.end(),back_inserter(vd2),
    [mean_val](double x){
        return x < mean_val;
    });
    sort(vd.begin(),vd.end());
    cout << vd;
    return 0;
}