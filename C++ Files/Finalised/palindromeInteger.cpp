/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False
*/
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


int main(){
	
	// vector<int> c = isPalindrome(1551);
	// for(int i=0; i<c.size(); i++){
	// 	cout<<c[i]<<" ";
	// }
	cout<<isPalindrome(1523663251);
}