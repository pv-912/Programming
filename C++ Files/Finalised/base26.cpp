 //     A -> 1
    
 //    B -> 2
    
 //    C -> 3
    
 //    ...
    
 //    Z -> 26
    
 //    AA -> 27
    
 //    AB -> 28 

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// int main()
// {
//  char c;
//  cout << "Enter a character: ";
//  cin >> c;
//  cout << "ASCII Value of " << c << " is " << int(c);
//  return 0;
// }


int titleToNumber(string A) {
    int x=0,y=0;
    int size = A.length();
    for(int i=0; i<size; i++){
        if(i!=(size-1)){

            y = int(A[i])-64;
            x += y*pow(26,i);

        } else{

            y = int(A[i])-65;
            x += y+pow(26,i);
        }
    }
    return x;
}

int main(){

    string A = "AB";
    int a = titleToNumber(A);
    cout<<a;
}
