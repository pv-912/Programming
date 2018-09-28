#include <iostream>
using namespace std;

struct Linklist{
	int val;
	Linklist *next;
};

void push(Linklist** head, int value){
	Linklist* newNode = new Linklist();
	newNode->val = value;
	newNode->next = *head;
	*head = newNode;
}

void deleteNodeHead(Linklist** head){
	if(!head)
		return;
	Linklist* temp = *head;
	*head = (*head)->next;
	delete(temp);
}

void deleteNodeLast(Linklist** temp){
	Linklist* head = *temp;
	if(head->next==NULL){
		*temp = NULL;
		delete(head);
		return;
	}
	while(head->next->next!=NULL){
		head = head->next;
	}
	Linklist* temp2 = head->next;
	head->next = NULL;
	delete(temp2);
}

void deleteNodePosition(Linklist** head, int value){
	if(!head)
		return;
	Linklist* temp = *head;
	Linklist* prev;
	while(temp->val!=value && temp->next!=NULL){
		prev = temp;
		temp = temp->next;
	}
	if(temp->next==NULL){
		cout<<"Value Doesn't Exist"<<endl;
		return;
	}
	if(temp==NULL){
		cout<<"Value2 Doesn't Exist"<<endl;

		prev->next = NULL;
		delete(temp);
		return;
	}
	prev->next = temp->next;
	delete(temp);
}

void print(Linklist* head){
	if(head==NULL)
		cout<<"List is empty"<<endl;
	while(head){
		cout<<(head->val)<<" ";
		head = head->next;
	}
}

int main(){
	Linklist* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);
	push(&head, 7);
	push(&head, 8);
	deleteNodeHead(&head);
	deleteNodeLast(&head);
	deleteNodePosition(&head,7);
	print(head);
}