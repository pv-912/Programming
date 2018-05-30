#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string convertToBinary(long long int a){
    string s = "";
    while(a>1){
        if(a%2 == 0){
            s =  '0' + s;
        }
        else{
            s = '1' + s;
        }
        a/=2;
    }
    return '1' + s;
}

int binaryOperationRequired(int a, int b){
    
    string sa = convertToBinary(a);
    string sb = convertToBinary(b-1);
    // if(sa.length()>sb.length()){
    //         return -1;
    //     }
        long long int counta = 0, countb = 0;
        for (long long int i = 0; i < sa.length(); ++i)
        {
            if(sa[i] == '1'){
                counta++;
            }
        }
        for (long long int i = 0; i < sb.length(); ++i)
        {
            if(sb[i] == '1'){
                countb++;
            }
        }
        // cout<<countb<<" "<<sb.length()<<" ";
        if(counta ==  countb){
            return 1;
        }
        if(counta > countb || countb == sb.length()){
            return -1;
        }
        

        return countb - counta+1;
}

int main() {
    int T;
    long long int a,b;
    cin>>T;

    while(T--){
        cin>>a>>b;
        cout<<binaryOperationRequired(a,b);


        // cout << s<<endl;
        // cout << convertToNumber(s);

        // int x = 1, lengthRequired = -1;
        // while(b-1 >= x){
        //     lengthRequired++;
        //     x = pow(2,lengthRequired);
        // }

        // cout<<5;
        // while(s.length() != lengthRequired){
        //     s = '0' + s;
        // }
        // random_shuffle(s.begin(), s.end());
        


    }
}
