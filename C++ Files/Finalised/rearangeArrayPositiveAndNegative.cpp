//Given an array of positive and negative numbers, arrange them such that all negative integers appear before all the positive integers in the array without using any additional data structure like hash table, arrays, etc. The order of appearance should be maintained.

//Examples:

//Input:  [12 11 -13 -5 6 -7 5 -3 -6]
//Output: [-13 -5 -7 -3 -6 12 11 6 5]

#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

int main() {
    
    int a[] = {1,-9,8,-6,87,5,1,-10};
    int size =sizeof(a)/sizeof(a[0]);
    // reverse(a, size);
    int j=-1;
    for(int i=0; i<size; i++){
        
        
        if(a[i]<0){
            j++;
            swap(a[i],a[j]);
        }else{
            continue;
        }
    }
    
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";   
     }
    return 0;
}

