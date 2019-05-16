#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;
#define MAX 1000


struct MinStack{
	int top_position;

	public:
		int stack[MAX];
		MinStack();
		void push(int x);
		void pop();
		int top();
		int getMin();	
};

MinStack::MinStack(){
	top_position = MAX;
}

void MinStack::push(int x) {
	if(top_position<0){
		return;
	}
	else{
		stack[--top_position] = x;
		// cout<<x<<" "<<stack[top_position]<<" "<<top_position<<endl;
	}
}

void MinStack::pop() {
	if(top_position >= MAX){
		return;
	}
	else{
		top_position++;
	}
}

int MinStack::top() {
	if(top_position>=MAX){
		return -1;
	}
	// cout<<top_position<<endl;
	return stack[top_position];
}

int MinStack::getMin() {
	int a = INT_MAX;
	int z = MAX;
	while(stack[z]){
		if(stack[z]<a){
			a = stack[z];
		}
		z--;
	}
	return a;
}

int main(){
	MinStack a;
	a.push(5);
	a.push(55);
	a.push(15);
	cout<<a.top()<<endl;
	a.pop();
	cout<<a.top()<<endl;
	cout<<a.getMin()<<endl;



}