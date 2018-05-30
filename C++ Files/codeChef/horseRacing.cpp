
/* not completed yet  */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

void quicksort(int arr[], int low, int high) {
 int i = low;
 int j = high;
 int y = 0;
 /* compare value */
 int z = arr[(low + high) / 2];
 
 /* partition */
 do {
  /* find member above ... */
  while(arr[i] < z) i++;
 
  /* find element below ... */
  while(arr[j] > z) j--;
 
  if(i <= j) {
   /* swap two elements */
   y = arr[i];
   arr[i] = arr[j]; 
   arr[j] = y;
   i++; 
   j--;
  }
 } while(i <= j);
 
 /* recurse */
 if(low < j) 
  quicksort(arr, low, j);
 
 if(i < high) 
  quicksort(arr, i, high); 
}
 
int main() {
    int T;
    long long n;
    cin>>T;
    if(T>=10 || T<0){
        return 0;
    }
    while(T--){
        cin>>n;
        if( n<1 || n>=5000){
            return 0;
        }
        int a[n] ;
        for(int i = 0; i < n; ++i){
            cin>>a[i];
        }
        quicksort(a,0,n-1);
        // sort(a,a+n);
        int diff =abs(a[1] - a[0]);
        for(int i = 2; i < n; ++i){
            if(abs(a[i] - a[i-1]) < diff){
                diff = abs(a[i] - a[i-1]);
                // cout<<diff<<endl;
            }
        }
        cout<<diff;
        // for(int i = 0; i < n; ++i){
        //     cout<<a[i];
        // }
    }
}