#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

void printList(node *a){
    while(a != NULL){
        cout<<a->data<<" ";
        a = a -> next;
    }
    cout<<endl;
}

void pushHead(struct node** headRef, int nData){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data =nData;
	newNode->next = *headRef;
	newNode->prev = NULL;
	*headRef = newNode;
}

void pushMiddle(struct node* prevNode, int nData){
	if(prevNode == NULL){
		cout<<"Given node is empty;"<<endl;
		return;
	}
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = nData;
	newNode->next = prevNode->next;
	newNode->prev = prevNode;
	prevNode->next = newNode;
}

void pushLast(struct node** headRef, int nData){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = nData;
	newNode->next = NULL;
	struct node* last = *headRef;

	if(*headRef==NULL){
		newNode->prev = NULL;
		*headRef = newNode;
		return;
	}
	while(last->next!=NULL){
		last = last->next;
	}

	newNode->prev = last;
	last->next = newNode;
	return;
}

void pushBeforeGivenNode(struct node* givenNode, int nData){
	if(givenNode == NULL){
		cout<<"Given node is empty;"<<endl;
		return;
	}
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = nData;

	newNode->prev = givenNode->prev;
	newNode->next = givenNode;
	givenNode->prev = newNode;
	cout<<"hello"<<endl;
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
	first->prev = NULL;
	
	second->data = 2;
	second->next = third;
	second->prev = first;
	
	third->data = 3;
	third->next  = NULL;
	third->prev = second;
	pushHead(&first,5);
	pushMiddle(second,6);
	pushLast(&first,10);
	pushBeforeGivenNode(third, 12);
	printList(first);
	return 0;

}
