/*
Given a Queue consisting of first n natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are:
1. Push and pop elements from the stack
2. Pop (Or enqueue) from the given Queue.
3. Push (Or Dequeue) in the another Queue.
*/
#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<long long int> q){
	cout<<endl;
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

int canBeSorted(queue<long long int> q){
	queue<long long int> q2;
	stack<long long int> s;
	if(q.empty()){
		return 0;
	}
	long long int a = 1;
	while(q.front()!=1){
		s.push(q.front());
		q.pop();
	}
	if(q.front()==1){
		q2.push(q.front());
		// return q.front();
		q.pop();
	}
	else{
		return 0;
	}
	while(!q.empty()){
		if(q.front() == a + 1){
			q2.push(q.front());
			a++;
		}
		else{
			s.push(q.front());
		}
		q.pop();
	}

	while(!s.empty()){
		if(s.top() == a+1){
			q2.push(s.top());
			s.pop();
			a++;
		}
		else{
			return 0;
		}
	}

	if(s.empty()){
		return 1;
	}

}

int main(){
	queue<long long int> q;
	 q.push(5);
    q.push(1);
    q.push(3);
    q.push(6);
    q.push(3);
    q.push(4);

	cout<<canBeSorted(q);
	printQueue(q);
}