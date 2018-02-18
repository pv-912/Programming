#include <iostream>
using namespace std;

void reverse(int b[],int rotateFrom, int rotateUpto){
    int y = rotateUpto - rotateFrom;
    int x = y/2,temp=0;
    for(int i=rotateFrom; i<(rotateFrom+x); i++){
        temp = b[i];
        b[i] = b[rotateUpto-i+rotateFrom-1];
        b[rotateUpto-i+rotateFrom-1] = temp;
    }
    // for(int i=0; i<12; i++){
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
}

void rotate(int a[], int size, int rotateBy){
    reverse(a,0,rotateBy);
    reverse(a,rotateBy,size);
    reverse(a,0,size);
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
}

int main() {
    int size = 12;
    int a[size] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int rotateBy = 5;
    // reverse(a,0,5);
    rotate(a,size,rotateBy);
    return 0;
}