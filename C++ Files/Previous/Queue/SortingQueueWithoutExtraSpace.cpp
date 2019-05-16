#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<int> q){
	cout<<endl;
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

void sorted(queue<int>& q){
	if(q.empty()){
		return;
	}
	if(q.size()==1){
		return;
	}

	int size = q.size();
	int x;
	for(int i=0; i<size; i++){
		x = q.front();
		q.pop();
		for(int i=0; i<size-1; i++){
			if(x<=q.front()){
				q.push(x);
				x = q.front();
			}
			else{
				q.push(q.front());
			}
			q.pop();
		}
		q.push(x);
	}
}

int main(){
	queue<int> q;
	q.push(5);
    q.push(1);
    q.push(3);
    q.push(6);
    q.push(2);
    q.push(4);
	printQueue(q);
	sorted(q);
	printQueue(q);

}