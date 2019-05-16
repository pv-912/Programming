#include <bits/stdc++.h>
using namespace std;

int setBitCount(int a){                         
    cout << __builtin_popcount (a) << endl;             // iostream library
}

void computeXORfrom1toN(int n){
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}


// direct binary string

#include <bitset>
 
void directBinaryVsString(){
    std::string bit_string = "110010";
    std::bitset<8> b(bit_string);          // [0, 0, 1, 1, 0, 0, 1, 0]
    std::cout << b.to_ulong() << '\n'; 
} 


string convertToBinary(int a){
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

int convertToNumberFromBinary(string a){
    int x = 0, res = 0, i = 0;
    x = stoi(a);
    while(x>0){
        if(x%10 == 1){
            res = res + pow(2,i);
        }
        i++;
        x = x/10;
    }
    return res;
}


int main(){
    convertToBinary(110);
}
