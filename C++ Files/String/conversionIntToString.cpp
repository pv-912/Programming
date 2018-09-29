#include <iostream>
#include <string>
#include <sstream>
using namespace std; 

int main(){
	int x = 2016;
	ostringstream t;
	t<<x;
	string s = t.str();
	string d = "12545";
	int num;
	stringstream ge(d);
	ge>>num;
	cout<<s<<" "<<typeid(s).name()<<" "<<num<<typeid(num).name()<<endl;

}