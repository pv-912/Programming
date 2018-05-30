#include <bits/stdc++.h>
using namespace std;

void printPrefix( vector<string> a, string query, int uptoLength){
	if(a.size() == 0)
		return;
	else if(a.size() == 1){
		cout<<a[0]<<endl;
		return;
	}

	string res = query;
	int max = 0;
	for (int i = 0; i < uptoLength; ++i){
		int count = 0;
		string s = "";
		s = accumulate(begin(a[i]), end(a[i]), s);
		int j = 0;
		bool done = 1;
		while(query[j] && done) {
			if(query[j] == s[j]){
		 		count++;
		 	}
		 	else{
		 		done = 0;
		 	}
		 	j++;
		}

		if(count>max){
			max = count;
			res = s;
		}
		else if(count == max && res.compare(s)>0){
			res = s;
		}
		s = "";
	}
	cout<<res<<endl;
}


int main() {
    int N, Q;
    cin>>N;
    string temp;
    vector<string> a;
    for (int i = 0; i < N; ++i){
    	cin>>temp;
    	a.emplace_back(temp);
    }
	cin>>Q;
	while(Q--){
		int length;
		cin>>length;
		string query;
		cin>>query;

		printPrefix(a, query, length); 
	}   	

}
