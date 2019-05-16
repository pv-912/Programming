
/* not completed yet  */

#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <cmath>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

void as(int N, int C){
    int a[N];
        for(int i = 0; i<N; i++){
            a[i] = 0;
        }
        while(C--){
            int a,b,c,d,e,f;
            cin>>a;
            if(a==0){
                cin>>b>>c>>d;

                for(int i = b; i<=c; i++){
                    d += a[i];
                    a[i] = x;
                }
            }
            else if(a == 1){
                cin>>e>>f;
                int count = 0;
                for(int i = e; i<=f; i++){
                    count += a[i];
                }
                cout<<count<<endl;
            }
        }
}

int main() {
    int T;
    int C;
    cin>>T;
    
    while(T--){
        int N;
        cin>>N>>C;
        if(C<=100000 || N<=1000000){
            return 0;
        }
        as(N,C);
    }
}