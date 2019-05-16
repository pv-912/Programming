#include <bits/stdc++.h>
using namespace std;

struct StackNode{
	int val;
	StackNode* next;
};

void push(StackNode** a, int x);
int pop(StackNode** a);
struct Queue{
	StackNode* stack1;
	StackNode* stack2;
};


void enQueue(Queue* a, int data){
	push(&a->stack1, data);
}

int dequeue(Queue* a){
	// int as = a->stack1->val;
	// cout<<as;
	if(a->stack1 == NULL && a->stack2 == NULL){
		cout<<"Queue is empty"<<endl;
		getchar();
		exit(0);
	}

	int x;

	if(&a->stack2 == NULL){
		while(a->stack1!=NULL){
			x = pop(&a->stack1);
			push(&a->stack2, x);
		}
	}

	x = pop(&a->stack2);
	return x;

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
	a->stack1 = NULL;
	a->stack2 = NULL;
	enQueue(a, 5);
	enQueue(a, 7);
	enQueue(a, 8);

	cout<<dequeue(a);

}