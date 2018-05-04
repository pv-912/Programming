#include <bits/stdc++.h>
using namespace std;

struct StackNode{
	int val;
	struct StackNode* next; 
	// StackNode(int x){val = x; next = NULL;}
};

struct StackNode* newNode(int data){
	StackNode* NewNode = new StackNode();
	NewNode->val = data;
	NewNode->next = NULL;
	return NewNode;
}

void push(StackNode** head_ref, int data){
	StackNode* temp = newNode(data);
	if(*head_ref == NULL){
		*head_ref = temp;
		return;
	}

	temp->next = *head_ref;
	*head_ref = temp;
	return;
}

int pop(StackNode** head_ref){
	if(*head_ref == NULL){
		cout<<"stack underflow"<<endl;
		return 0;
	}
	StackNode* temp = *head_ref;
	*head_ref = (*head_ref)->next;
	int popValue = temp->val;
	free(temp);
	return popValue;
}

int peek(StackNode* head_ref){
	if(*head_ref == NULL){
		return 0;
	}

	return (*head_ref)->val;
}

int main(){
	StackNode* a = NULL;

	push(&a,20);
	push(&a,21);
	push(&a,22);
	cout<<pop(&a);
	push(&a,22);
	push(&a,24);
	cout<<pop(&a);
	cout<<peek(&a);




}