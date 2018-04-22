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
void reverseQueue(queue<int>& q){
	if(q.empty()){
		return;
	}

	int a = q.front();
	q.pop();
	reverseQueue(q);
	q.push(a);
	return;
}

int main(){
	queue<int> q;
	q.push(25);
	q.push(26);
	q.push(27);
	q.push(28);
	reverseQueue(q);
	printQueue(q);
}