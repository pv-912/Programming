#include <iostream>

using namespace std;
void swap(int& a, int& b){
    int temp = b;
    b = a;
    a = temp;
}

void reverse(int a[], int size){
    for(int i=0; i<size/2; i++){
        swap(a[i],a[size-i-1]);
    }  
     for(int i=0; i<size; i++){
        cout<<a[i]<<" ";   
     }
}

int main() {
    
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int size =sizeof(a)/sizeof(a[0]);
    reverse(a, size);
    return 0;
}

