/*Given an array of n distinct elements and a number x, arrange array elements according to the absolute difference with x, i. e., element having minimum difference comes first and so on.
Note : If two or more elements are at equal distance arrange them in same sequence as in the given array.


Examples :

Input : arr[] : x = 7, arr[] = {10, 5, 3, 9, 2}
Output : arr[] = {5, 9, 10, 3, 2}
Explanation:
7 - 10 = 3(abs)
7 - 5 = 2
7 - 3 = 4 
7 - 9 = 2(abs)
7 - 2 = 5
So according to the difference with X, 
elements are arranged as 5, 9, 10, 3, 2.

Input : x = 6, arr[] = {1, 2, 3, 4, 5}   
Output :  arr[] = {5, 4, 3, 2, 1}

Input : x = 5, arr[] = {2, 6, 8, 3}   
Output :  arr[] = {6, 3, 2, 8}

*/


#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

void sort(int a[], int size, int x){
    for(int i=1; i<size; i++){
        int s = a[i-1]-x, t = a[i]-x;
        if(s<0){
            s = s-2*s;
        } else if(t<0){
            t = t - 2*t;
        } else{
            continue;
        }
        
        if(s>t){
            swap(a[i],a[i-1]);
        }else{
            continue;
        }
    }
    
     for(int i=0; i<size; i++){
        cout<<a[i]<<" ";   
     }
}

int main() {
    int x = 15;
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int size =sizeof(a)/sizeof(a[0]);
    sort(a, size, x);
    return 0;
}

