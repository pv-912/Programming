#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

struct Queue{
	int top,last;
	public:
		int queue[MAX];
		Queue(){top = -1;last = -1;}
		bool newQueue(int data);
		int pop();
		bool isEmpty();
};

bool Queue::newQueue(int data){
	if(top>=MAX){
		cout<<"stack overflow"<<endl;
		return false;
	}
	else{
		queue[++top] = data;
		return true;
	}
}

int Queue::pop(){
	if(top<0){
		return 0;
	}
	else{
		int x = queue[++last];
		return x;
	}
}

bool Queue::isEmpty(){
	return (top<0);
}

int main(){
	Queue a;
	a.newQueue(1);
	a.newQueue(10);
	a.newQueue(12);
	cout<<a.pop()<<endl;
	cout<<a.pop()<<endl;
	cout<<a.pop()<<endl;
}