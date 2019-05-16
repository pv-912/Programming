#include <iostream>

using namespace std;

void rotate(int a[],int size, int rotateBy){
    int temp[size-rotateBy];
    for(int i=0; i<rotateBy; i++){
        temp[i] = a[i]; 
    }
    
    for(int i=0; i<size; i++){
        if((i+rotateBy)<size){
            a[i] = a[i+rotateBy];
        } else{
            a[i]=temp[i-(size-rotateBy)];
        }
    }
    
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
}

int main() {
    int size = 7;
    int a[size] = {1,2,3,4,5,6,7};
    int rotateBy = 4;

    rotate(a,size,rotateBy);
    return 0;
}