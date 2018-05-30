#include <iostream>
#include <set>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int primeFactors(int n){
	set<int> temp;
    while (n%2 == 0){
        temp.insert(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
        temp.insert(i);
            n = n/i;
        }
    }
    if (n > 2)
        temp.insert(n);

    return temp.size();
}

int main(){
	
	int t,m,n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		set<int> temp;
		int count = 0;
		for (int i = m; i < n; ++i){
			count += primeFactors(i);
		}
		cout<<count<<endl;
	}
}