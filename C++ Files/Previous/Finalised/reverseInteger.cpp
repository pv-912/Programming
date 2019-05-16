#include <bits/stdc++.h>
using namespace std;
void reverse(int A){
    bool isNeg = false;
    if(A<0) {
        isNeg = true;
        A = A*(-1);
    }
    
    int rev = 0;
    
    while(A>0){
        
        int dig = A%10;
        // cout<<INT_MAX-dig<<endl;
        int maxVal = (INT_MAX-dig)/10;
        if(rev>maxVal){
            // cout<<0<<endl;
        }
        cout <<rev<<endl;
        // cout<<maxVal<<endl;
        rev = (rev*10 + dig);
        
        A/=10;
    }
    
    if(isNeg){
        cout<<(-1)*rev<<endl;
    }
    
   cout<<rev<<endl;
}

int main(){
	
	// vector<int> c = isPalindrome(1551);
	// for(int i=0; i<c.size(); i++){
	// 	cout<<c[i]<<" ";
	// }
	reverse(110000010);
}