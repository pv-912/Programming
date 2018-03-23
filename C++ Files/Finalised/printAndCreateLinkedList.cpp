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

void deleteNode(struct node** headRef, int key){
	struct node* temp = *headRef, *prev;

	if(temp!=NULL && temp->data==key){
		*headRef = temp->next;
		free(temp);
		return; 
	} 

	while(temp!=NULL && temp->data!=key){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
}

void deleteNodeAtGivenPosition(struct node** headRef, int position){
	struct node* temp = *headRef;

	if(*headRef==NULL){
		return;
	}


	if(position==0){
		*headRef = temp->next;
		free(temp);
		return;
	}

	for(int i=0;temp!=0 && i<position-1; i++){
		temp = temp->next;
	}

	if(temp==0 || temp->next==0){
			return;
	}
	// struct node *next = temp->next->next;
	free(temp->next);
	temp->next = temp->next->next;
}

void listLength(struct node** headRef){
	struct node* temp = *headRef;
	int a = 0;
	while(temp!=NULL){
		temp = temp->next;
		a++;
	}
	cout<<a<<endl;
}

void printList(node *a){
    while(a != NULL){
        cout<<a->data<<" ";
        a = a -> next;
    }
    cout<<endl;
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
	listLength(&first);
	printList(first);

	deleteNode(&first, 3);
	printList(first);

	deleteNodeAtGivenPosition(&first, 1);
	deleteNodeAtGivenPosition(&first, 3);
	printList(first);
	return 0;

}
