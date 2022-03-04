#include "std_lib_facilities.h"

string invalid_chars = ";:\"\'[]*&^%$#@!";

struct Person{
	
	Person(){}
	Person(string in_first_name,string in_second_name,int in_age){

		//Hibaeellenorzes
		if(in_age < 0 || in_age > 150){
			//Hiba invalid age;
			error("Invalid age");
		}
		for(int c = 0; c < invalid_chars.size(); c++){
			if(in_first_name.find(invalid_chars[c]) != std::string::npos
			 	|| in_second_name.find(invalid_chars[c]) != std::string::npos){
				error("Invalid char in name!");
			}
		}

		_f_name = in_first_name;
		_s_name = in_second_name;
		_age = in_age;
	};

	string name() const{
		return _f_name + " " + _s_name;
	}
	int age() const{
		return _age;
	}
	private:
		string _f_name;
		string _s_name;
		int _age;
};

ostream& operator<<(ostream& out, Person& p){
	out << p.name() << " " << p.age() << endl;
	return out;
}

istream& operator>>(istream& in, Person& p){
	string f_name;
	string s_name;
	int age;
	in >> f_name >> s_name >> age;
	if(!in) return in;
	p = Person(f_name,s_name,age);

	return in;
}

int main(){
	Person person("Goofy","Mouse",63);
	cout << person;
	vector<Person> people;

	while(cin >> person){ //Há' kilép ha életkornak azt adod meg hogy ikszdé
		
		people.push_back(person);
	}
	for(int c = 0; c < people.size(); c++){
		cout << people[c];
	}

	return 0;
}
