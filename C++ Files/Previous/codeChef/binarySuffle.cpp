#include <iostream>
using namespace std;

long long int countSetBits(long long int n){
    if (n == 0)
        return 0;
    else
        return 1 + countSetBits(n & (n - 1));
}

long long int binarySuffleUtil(long long int a, long long int b){
    if(a==b)
        return 0;
    if(a < 0 || b <= 0)
        return  -1;
    if(a>0 && b == 1)
        return -1;

    long long int countA = countSetBits(a);
    long long int countB = countSetBits(b - 1);
    if(countB == countA ){
        return 1;
    }
    else if(countA > countB){
        return 2;
    }
    else if(countA < countB){
        return (countB - countA + 1);
    }
}

int main() {
    int T;
    long long int a,b;
    cin>>T;
    while(T--){
        cin>>a>>b;
        long long int x =  binarySuffleUtil(a,b);
        cout<<x<<endl;
    }
}
