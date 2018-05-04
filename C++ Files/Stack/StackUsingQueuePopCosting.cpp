#include <bits/stdc++.h>
using namespace std;

class Stack{
	queue<int> q1,q2;
	int current_size;

	public:
		Stack(){
			current_size = 0;
		}

		void push(int data){
			q1.push(data);
			current_size++;
		}

		void pop(){
			if(q1.empty()){
				return;
			}
			while(q1.size()!=1){
				q2.push(q1.front());
				q1.pop();
			}

			queue<int> temp = q1;
			q1 = q2;
			q2 = temp;
			current_size--;
		}

		int top(){
			if(q1.empty()){
				return -1;
			}

			while(q1.size()!=1){
				q2.push(q1.front());
				q1.pop();
			}

			int a = q1.front();
			q2.push(a);
			queue<int> temp = q1;
			q1 = q2;
			q2 = temp;

			return a;
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
	s.pop();
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
}