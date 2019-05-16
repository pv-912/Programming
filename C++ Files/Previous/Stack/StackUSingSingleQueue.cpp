#include <bits/stdc++.h>
using namespace std;

class Stack{
	queue<int> q,q2;
	int current_size;

	public:
		Stack(){
			current_size = 0;
		}
		void push(int data){
			int size = q.size();
			q.push(data);
			for(int i=0; i<size; i++){
				q.push(q.front());
				q.pop();
			}
			current_size++;
		}

		// void push(int data);

		void pop(){
			if(q.empty()){
				cout<<"Queue is empty"<<endl;
				return;
			}
			current_size--;
			q.pop();
			return;
		}

		int top(){
			if(q.empty()){
				return -2;
			}
			return q.front();
		}
		int size(){
			return current_size;
		}

};

// void Stack::push(int data){
// 	if(!q.empty()){
// 		current_size++;
// 		q.push(data);
// 		return;
// 	}
// 	int x;
// 	x = q.front();
// 	q.pop();
// 	cout<<q.front()<<" ";
// 	this->push(data);
// 	q.push(q.front());
// 	return;
// }

int main(){
	Stack s;
	s.push(40);
	s.push(43);
	s.push(44);
	s.push(54);
	s.push(74);
	s.push(48);
	s.push(45);
	cout<<endl;
	cout<<s.size()<<endl;
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();	
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
}