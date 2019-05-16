/* 
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 
*/
#include <bits/stdc++.h>
using namespace std;

int isPower(int a) {
    if(a == 1)
        return 1;
    float x;
    for(int i = 2; i<=a; i++){
        x = pow(a,1.0/i);
        if (x-(int)x == 0){
            return 1;
        }
             
    }   
    return 0;
}

int main(){
    int a;
    cin>>a;
    cout<<isPower(a);
}
