#include <iostream>
using namespace std;

int catalan(int n){
    int arr[n+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 1; i<n; i++){
        int k = 0;
        for(int j = 0; j<=i; j++){
            k += arr[j]*arr[i-j] ;
            // cout<<k<<" ";
        }
        // cout<<i+1<<endl;
        arr[i+1] = k;
    }
    return arr[n];
}

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<catalan(n)<<endl;
    return 0; 
}