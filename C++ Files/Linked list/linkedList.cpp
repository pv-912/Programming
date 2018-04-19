#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

void pushHead(struct Node** head_ref, int dataToInsert){
	struct Node *newNode = new Node();
	newNode->data = dataToInsert;
	newNode->next = *head_ref;
	*head_ref = newNode;
}

void pushLast(struct Node** head_ref, int dataToInsert){
	struct Node *newNode = new Node();
	newNode->data = dataToInsert;
	newNode->next = NULL;
	struct Node *last = *head_ref;

	if(*head_ref == NULL){
		*head_ref = newNode;
		return;
	}
	while(last->next!=NULL){
		last = last->next;
	}

	last->next = newNode;
	return;
}

void pushMiddle(struct Node** head_ref, int dataToInsert, int position){
	struct Node* newNode = new Node();
	newNode->data = dataToInsert;

	struct Node *position_ref = *head_ref;

	if(*head_ref == NULL){
		cout<<"list is empty";
		return;
	}

	for(int i=0; i<position; i++){
		position_ref = position_ref->next;
	}

	newNode->next = position_ref->next;
	position_ref->next = newNode;
}

void deleteNode(struct Node** head_ref, int dataToDelete){
	struct Node *position_ref = *head_ref, *prev;

	if(position_ref!=NULL && position_ref->data == dataToDelete ){
		*head_ref = position_ref->next;
		free(position_ref);
		return;
	}

	while(position_ref!=NULL && position_ref->data != dataToDelete ){
		prev = position_ref;
		position_ref = position_ref->next;
	}

	if(position_ref == NULL){
		cout<<"data not present";
		return;
	}

	prev->next = position_ref->next;
	free(position_ref);
}

void middleElement(struct Node** head_ref){
	struct Node* one = *head_ref;
	struct Node* two = *head_ref;

	while(two != NULL){
		one = one->next;
		two = two->next->next;
	}

	cout<<endl<<one->data<<endl;
}

int main(){
	struct Node* head = new Node();
	struct Node* second = new Node();
	struct Node* third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	pushHead(&head,0);
	pushMiddle(&head,10,2);
	pushLast(&head,4);
	deleteNode(&head,20);
	middleElement(&head);	
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	return 0;
}