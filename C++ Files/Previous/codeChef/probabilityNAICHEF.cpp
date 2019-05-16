#include <iostream>
#include <cmath>
#include<iomanip>
#include<math.h>
using namespace std;

double probability(int x[], int size, int a, int b){
    int countA = 0, countB = 0;
    for(int i = 0; i<size; i++){
        if(x[i] == a){
            countA++;
        }
        if(x[i] == b){
            countB++;
        }
    }

    double res = (double)(countA)*(countB)/pow(size,2);
    return res;
}

int main() {
    int T;
    int n,a,b,k;
    cin>>T;

    while(T--){
        cin>>n>>a>>b;
        int x[n]; 
        for(int i = 0; i<n; i++){
                cin>>x[i];
        }
        double result = probability(x, n, a, b);
        result = (floor(result*1000000))/1000000;
        cout <<fixed<<setprecision(10)<<result<< endl;

    }
}
