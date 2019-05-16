#include <iostream>
using namespace std;
void fizzBuzz(int A) {
    for(int i=1; i<=A; i++){
        if(i%5 == 0 && i%3 == 0){
            cout<<"FizzBuzz";
        }else if(i%3 == 0){
            cout<<"Fizz";
        }else if(i%5 == 0){
            cout<<"Buzz";
        }else{
            cout<<i;
        }
    }
}

int main(){
    int A=20;
    fizzBuzz(A);
}


