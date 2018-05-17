
#include <bits/stdc++.h>
using namespace std;
int isPalindrome(int a) {
	if(a<0){
		return 0;
	}
   int x = a;
   int p = 1;
   vector<int> v;
   while(x>0){
   		v.push_back(x%10);
   		x = x/10;
   }
   for(int i=0; i<v.size()/2; i++){
   		if(v[i] != v[v.size() - i -1]){
   			p = 0;
   		}
   }
   return p;
}

void largestPalindromeNumberOfMultiplicationOf2NDigitNumber(long long int a){
	cout<<a<<endl;
	for(long long int i = a*a; i>0; i--){
		int x = i;
		int p = 1;
		vector<int> v;
	    while(x>0){
	   		v.push_back(x%10);
	   		x = x/10;
	    }
	    for(int j=0; j<v.size()/2; j++){
	   		if(v[j] != v[v.size() - j -1]){
	   			p = 0;
	   		}
	    }
	    if(p==1){
	    	cout<<i<<endl;
	    	break;
	    }
	}
}
int main(){
	
	cout<<isPalindrome(1523663251)<<endl;
	long long int a = 999;   // largest 3 digit number
	largestPalindromeNumberOfMultiplicationOf2NDigitNumber(a);
}