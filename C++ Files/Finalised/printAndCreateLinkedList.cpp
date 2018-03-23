#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void pushHead(struct node** headRef, int newData){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = (*headRef);
	(*headRef) = newNode;
} 

void pushBetween(struct node* prevNode, int newData){
	if(prevNode == NULL){
		cout<<"Given node is empty;"<<endl;
		return;
	}
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void pushLast(struct node** headRef, int newData){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	struct node *last = *headRef;
	newNode->data = newData;
	newNode->next = NULL;
	if(*headRef == NULL){
		*headRef == newNode;
		return;
	}

	while(last->next!=NULL){
		last = last->next;
	}
	last->next = newNode;
	return;
}

void printList(node *a){
    while(a != NULL){
        cout<<a->data<<" ";
        a = a -> next;
    }
}

int main() {
	struct node* first = NULL;
	struct node* second =NULL;
	struct node* third = NULL;
	
	first = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	
	first->data = 1;
	first->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next  = NULL;
	
	pushHead(&first, 5);
	pushBetween(first->next, 6);
	pushLast(&first,9);

	printList(first);
	return 0;
	
}
