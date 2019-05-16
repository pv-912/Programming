#include <iostream>
#include <unordered_set>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	unordered_set<char> temp;
	temp.insert('f');
	temp.insert('r');
	temp.insert('e');
	temp.insert('z');
	temp.insert('a');
	temp.insert('i');

	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		string res;
		int countA=0,countB=0;
		for (int i = 0; s[i]; ++i){
			if(temp.find(s[i])!=temp.end()){
				countA++;
				
				if(countA==1 && countB!=0){
					res += to_string(countB);
				}
				countB = 0;
			}
			else{
				countB++;
				if(countB==1 && countA!=0){
					res += to_string(countA);
				}
				countA = 0;
			}
		}
		if(countA!=0)res += to_string(countA);
		if(countB!=0)res += to_string(countB);
		
		cout<<res<<endl;
	}
}