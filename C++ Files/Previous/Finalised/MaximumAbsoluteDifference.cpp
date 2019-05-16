/*  You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5. 
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int difference(vector<int> &a){
    int size =(int) a.size();
    int max = 0, temp = 0, e=0, f=0 ;
    
    for(int i=0; i<size; i++){
        int j=0;
        while(j<size){
            e = a[i] - a[j];
            f = i-j;
            temp = sqrt(pow(e,2)) + sqrt(pow(f,2));
             j++;
            if(max<temp ){
                max = temp;
            }
        }
    }
    return max;
}

int main() {
    vector<int> a;
    a = { -70, -64, -6, -56, 64, 61, -57, 16, 48, -98 };
    int ans = difference(a);
	cout<<ans;
	return 0;
}
