# include "../std_lib_facilities.h"

template<typename T>struct S{
    private:
        T val;
    public:
        S():val(T()){}; //default constructor
        S(T d):val(d){};//initialize with given value
        T& get();
        const T& get() const;
        //void set(T newVal);
        void operator=(const T&);

};

template<typename T> T& S<T>::get()
{
    return val;
}
template<typename T> const T& S<T>::get()const
{
    return val;
}
/*
template<typename T> void S<T>::set(T newVal)
{
    val = newVal;
}
*/

template<typename T> void S<T>::operator=(const T& d)
{
    val=d;
    //return val;
}

template<typename T> void readval(T& v)
{
    cin>>v;
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& vect)
{
    os << "{ ";
    for (int i = 0; i<vect.size(); ++i) 
    {
        os << vect[i];
        if (i<vect.size()-1)
        {
            os << ',';
        } 
        os << ' ';
    }
    os << "}";
    return os;
}

template<class T> istream& operator>>(istream& is, vector<T>& d)
{
    char ch1;
    char ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if (!is)
    {
        return is;
    }
    if (ch1!='{') //Ha nem ezzel a karakterrel nyitunk, akkor az fail
    {
        is.clear(ios_base::failbit);
        return is;
    }

    while (cin>>temp>>ch2 && ch2==',') //Olvasunk elemet és vesszőt várunk utána
    {
        v_temp.push_back(temp);
    }

    if (ch2!='}') //Ha nem ezzel a karakterrel zárunk, akkor az fail
    {
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp); //A legutolsó elem nem került be a ciklusnál, mert nem volt utánna vssző
    d = v_temp;
}

int main(){
    S<int> s_int(2);
    S<char> s_char('c');
    S<double> s_double(3.14);
    S<string> s_string("sztring");
    S<vector<int>> s_vect_int({0,1,2,3,4});

    cout<<"s_int: "<<s_int.get()<<endl;
    cout<<"s_double: "<<s_double.get()<<endl;
    cout<<"s_string: "<<s_string.get()<<endl;
    cout<<"s_char: "<<s_char.get()<<endl;
    cout<<"s_vect_int: "<<s_vect_int.get()<<endl;

    //s_int.set(4);
    s_int = 4;
    cout<<"s_int: "<<s_int.get()<<endl;

    return 0;
}