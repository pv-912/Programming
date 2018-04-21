#include <bits/stdc++.h>
using namespace std;

struct StackNode{
	int val;
	StackNode* next;
};

void push(StackNode** a, int x);
int pop(StackNode** a);
struct Queue{
	StackNode* stack;
};


void enQueue(Queue* a, int data){
	push(&a->stack, data);
}

int dequeue(Queue* a){
	if(a->stack==NULL){
		cout<<" Queue is empty"<<endl;
		return -1;
	}

	int res,x;

	if(a->stack->next==NULL){
		res = pop(&a->stack);
		return res;
	}

		x = pop(&a->stack);
		res = dequeue(a);
	push(&a->stack, x);
	return res;

}

void push(StackNode** head_ref, int data){
	
	StackNode* newNode = new StackNode();
	if(newNode == NULL){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	newNode->val = data;
	newNode->next = *head_ref;
	*head_ref = newNode;
	// int as = (*head_ref)->val;
	// 	cout<<as<<endl;

}

int pop(StackNode** head_ref){
	int popValue ;
	StackNode* temp ;
	if(*head_ref==NULL){
		cout<<" Queue is empty1."<<endl;
		
	}
	else{
		temp = *head_ref;
		*head_ref = temp->next;
		popValue = temp->val;
		free(temp);
		return popValue;
	}
}


int main(){

	Queue* a = new Queue();
	a->stack = NULL;
	enQueue(a, 5);
	enQueue(a, 7);
	enQueue(a, 8);

	cout<<dequeue(a);
	enQueue(a, 8);
	cout<<dequeue(a);
	
}