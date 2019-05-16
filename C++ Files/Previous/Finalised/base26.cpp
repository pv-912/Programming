 //     A -> 1
    
 //    B -> 2
    
 //    C -> 3
    
 //    ...
    
 //    Z -> 26
    
 //    AA -> 27
    
 //    AB -> 28 

#include <iostream>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

// int main()
// {
//  char c;
//  cout << "Enter a character: ";
//  cin >> c;
//  cout << "ASCII Value of " << c << " is " << int(c);
//  return 0;
// }


int titleToNumber(string s) {
    int result = 0;
   for (int i = 0; i < s.size(); i++) {
        result  = result * 26 + (s[i] - 'A' + 1);
   }
   return result;
}

string convertToNumber(int a) {
    string result;
    string t;
    int x;
    while(a!=0){
        int x = a%26;
        if(x == 0){
            t  = a%26 + 25  + 'A';
            x = 1;
        }
        else
            t  = a%26 -1 + 'A';
        result = result + t;
        a = (a-x)/26;
    }
    reverse(result.begin(), result.end());
   return result;
}

int main(){

    int a;
    cin>>a;
    // string a = "BCD";
    // cout<<titleToNumber(a);
    string b = convertToNumber(a);

    cout<<b;
}
