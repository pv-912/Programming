#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> s){
	cout<<endl;
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}

void pushSatck(stack<int>& s, int data){
	if(s.empty()){
		s.push(data);
		return;
	}

	int x = s.top();
	s.pop();
	pushSatck(s, data);
	s.push(x);
}

void reverseStack(stack<int>& s){
	if(s.empty()){
		return;
	}

	int x;
	x  = s.top();
	s.pop();
	reverseStack(s);
	pushSatck(s,x);
}


int main(){
	stack<int> s;
	s.push(-5);
    s.push(1);
    s.push(3);
    s.push(6);
    s.push(2);
    s.push(4);
	printStack(s);
	reverseStack(s);
	printStack(s);
}
