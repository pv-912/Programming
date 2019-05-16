# include <bits/stdc++.h>

using namespace std;

void factorisation( long long int x){
	vector<long long int> b;
	for(long long int i = 2; i<sqrt(x); i++){
		while(x % i  == 0){
			b.push_back(i);
			x = x/i;
		}
	}
	if (x > 2){
       b.push_back(x);
	}

	for(long long int j = 0; j<b.size(); j++){
		cout<<" "<<b[j];
	}
	cout<<endl;
}

void primeFactors(long long int n){
	vector<long long int> b;
    
    while (n%2 == 0){
        b.push_back(2);
        n = n/2;
    }
 
    for (long long int i = 3; i <= sqrt(n); i = i+2){
        
        while (n%i == 0){
	        b.push_back(i);
            n = n/i;
        }
    }

    if (n > 2){
       b.push_back(n);
	}

	for(long long int j = 0; j<b.size(); j++){
		cout<<" "<<b[j];
	}
        
}

int main() {
	long long int a = 600851475143;
	factorisation(a);
    primeFactors(a);

}