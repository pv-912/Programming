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

void sortPush(stack<int>& s, int data){
	if(s.empty() || s.top()>data){
		s.push(data);
	}
	else{
		int x = s.top();
		s.pop();
		sortPush(s, data);
		s.push(x);		
	}
}
void sortStack(stack<int>& s){
	if(s.empty()){
		return;
	}

	int x;
	x = s.top();
	s.pop();
	sortStack(s);
	sortPush(s, x);
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
	sortStack(s);
	printStack(s);
}