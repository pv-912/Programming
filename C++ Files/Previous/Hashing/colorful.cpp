/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
*/

#include <iostream>
#include<unordered_set>
#include <vector>

using namespace std;

int colorful(int a) {
    int temp = a;
    vector<int> s;
    unordered_set<int> u,v;
    while(temp>0){
        s.push_back(temp%10);
        temp /= 10;
    }
    int size = s.size();
    for (int i=1; i<= size ; i++){
        int j = 0;
            while(j+i-1<size){
                int k = i, p = j,product = 1;
                while(k--){
                    product *=  s[p];
                    p++;
                }
                if(v.find(product)!=v.end()){
                    return 0;
                }
                else{
                    v.insert(product);
                }
                j++;
            }
        }
    return 1;
}

int main(){
    cout<<colorful(2134);
}
