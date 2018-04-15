#include <bits/stdc++.h>
using namespace std;
// #define ONLINE_JUDGE  freopen("input","r",stdin); freopen("output","w",stdout);

int isPalindrome(string a) {

	// ONLINE_JUDGE
	for(int i = 0; i < a.size(); ++i)
    {
        if (!((a[i] >= 'a' && a[i]<='z') || (a[i] >= 'A' && a[i]<='Z')))
        {
            a[i] = '\0';
        }
    }
    // std::transform(a.begin(), a.end(), a.begin(), ::tolower);
	
	vector<char> v(a.begin(),a.end());
	int p = 1;

	for(int i = 0; i < v.size(); i++)
    {
        for(int j = i+1; j < v.size(); j++)
        {
            if (v.at(j) == 0)
            {
				vector<char>::iterator itr = v.begin();
                itr+=j;
                v.erase(itr);
            }
        }
    }
 //    cout<<v.size();
 //    for (int i=0; i<v.size(); i++){
 //      // cout << v[i]<<" "<<i<<" "<<endl; 
 //      cout << v[i]; 
	// }
	// cout<<endl;
    for(int i =0; i<v.size();i++){
    	if(int(v[i])<96){
    		v[i] = int(v[i]) + 32;
    	}
	}
    for(int i =0; i<v.size();i++){
    	if(int(v[i]) != int(v[v.size()-i-1])){
    		// cout<<int(v[i])-int(v.size()-i-1)<<" "<<int(v[i])<<" "<<int(v[v.size()-i-1])<<" ";
    		// cout<<i<<" "<<v[i]<<" "<<v[v.size()-i-1]<<endl;
    		p = 0;
    	}
    }

    return p;
}

int main(){
	string a= "A man, a plan, a canal: Panama";
	cout<<endl<<isPalindrome(a);
	// cout<<a;
	// vector<char> b;
	// int size = sizeof(a)/sizeof(a[0]);
	// for(int i = 0; i<size; i++){
	// 	b.push_back(a[i]);
	// }

	// for(int i=0; i<b.size(); i++){
	// 	cout<<b[i]<<" "<<endl;
	// }
	// cout<<a;
	return 0;
}