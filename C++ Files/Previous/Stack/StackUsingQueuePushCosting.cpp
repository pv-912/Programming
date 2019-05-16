#include <bits/stdc++.h>
using namespace std;

class Stack{
	queue<int> q1,q2;
	int current_size;
	public:
		Stack(){
			current_size = 0;
		};

	void push(int data){

		q2.push(data);
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		
		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;
		current_size++;
	}

	void pop(){
		if(q1.empty()){
			return ;
		}
		current_size--;
		q1.pop();
	}

	int top(){
		if(q1.empty()){
			return -1;
		}
		return q1.front();
	}

	int size(){
		return current_size;
	}
};

int main(){

	Stack s;
	s.push(40);
	s.push(43);
	s.push(44);
	s.push(45);
	cout<<s.size()<<endl;
	cout<<s.top()<<endl;
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
}